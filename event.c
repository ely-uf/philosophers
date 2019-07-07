#include "event.h"
#include "eventq.h"

static inline t_event_list	*event_list_entry_new(t_event ev)
{
	t_event_list	*new_entry;

	new_entry = (t_event_list*)malloc(sizeof(*new_entry));
	if (!new_entry)
		return (NULL);

	new_entry->next = NULL;
	new_entry->ev = ev;
	return (new_entry);
}

int							event_dispatch(t_eventq *queue, t_event ev)
{
	t_event_list	*new_entry;

	new_entry = event_list_entry_new(ev);
	if (!new_entry)
		return (1);

	pthread_mutex_lock(&queue->lock);
	if (!queue->ev_lst_head)
	{
		queue->ev_lst_head = new_entry;
		queue->ev_lst_tail = new_entry;
	}
	else
	{
		queue->ev_lst_tail->next = new_entry;
		queue->ev_lst_tail = new_entry;
	}
	pthread_mutex_unlock(&queue->lock);

	return (0);
}

t_event						event_poll(t_eventq *queue)
{
	t_event_list	*entry;
	t_event			ev;

	pthread_mutex_lock(&queue->lock);
	entry = queue->ev_lst_head;
	if (entry)
	{
		if (queue->ev_lst_head == queue->ev_lst_tail)
			queue->ev_lst_tail = NULL;
		queue->ev_lst_head = queue->ev_lst_head->next;
	}
	pthread_mutex_unlock(&queue->lock);

	ev = entry ? entry->ev : (t_event) { .type = P_EV_NONE };
	free(entry);

	return (ev);
}
