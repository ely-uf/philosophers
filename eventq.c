#include "event.h"
#include "eventq.h"

static inline void	eventq_list_destroy(t_event_list *iter)
{
	t_event_list	*next;

	while (iter)
	{
		next = iter->next;
		free(iter);
		iter = next;
	}
}

int					eventq_init(t_eventq *queue)
{
	pthread_mutex_init(&queue->lock, NULL);
	queue->ev_lst_head = NULL;
	queue->ev_lst_tail = NULL;

	return (0);
}

int					eventq_deinit(t_eventq *queue)
{
	eventq_list_destroy(queue->ev_lst_head);
	queue->ev_lst_head = NULL;
	queue->ev_lst_tail = NULL;
	pthread_mutex_destroy(&queue->lock);
	return (0);
}
