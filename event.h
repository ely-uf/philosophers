#ifndef __EVENT_H
# define __EVENT_H

# include <pthread.h>
# include <stdlib.h>
# include "fork.h"
# include "philosopher.h"

typedef struct s_eventq	t_eventq;

typedef enum		e_event_type
{
	P_EV_NONE,
	P_SIMULATION_INIT,
	P_PHILO_STATE_CHANGED,
	P_PHILO_HP_CHANGED,
	P_PHILO_FORK_ACQUIRED,
	P_PHILO_FORK_RELEASE,
	P_PHILO_DIED,
	P_SIMULATION_END,
}					t_event_type;

typedef struct		s_state_ev
{
	int				id;
	t_phil_state	state;
}					t_state_ev;

typedef struct		s_health_ev
{
	int				id;
	size_t			new_hp;
}					t_health_ev;

typedef struct		s_fork_ev
{
	int				id;
	t_fork_side		fork_side;
}					t_fork_ev;

typedef struct		s_died_ev
{
	int				id;
}					t_died_ev;

typedef struct		s_event
{
	t_event_type	type;
	union {
		t_state_ev	state;
		t_health_ev health;
		t_fork_ev	fork;
		t_died_ev	died;
	}				ev;
}					t_event;

int					event_dispatch(t_eventq *evq, t_event ev);
t_event				event_poll(t_eventq *evq);

#endif
