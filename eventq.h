#ifndef __EVENTQ_H
# define __EVENTQ_H

# include "event.h"

typedef struct			s_event_list
{
	t_event				ev;
	struct s_event_list *next;
}						t_event_list;

typedef struct			s_eventq
{
	pthread_mutex_t		lock;
	t_event_list		*ev_lst_head;
	t_event_list		*ev_lst_tail;
}						t_eventq;

int						eventq_init(t_eventq *queue);
int						eventq_deinit(t_eventq *queue);

#endif
