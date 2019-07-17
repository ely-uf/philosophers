#ifndef __PHILOSOPHER_H
# define __PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include "philo_const.h"
# include "fork.h"

typedef enum		e_phil_state
{
	P_EAT,
	P_REST,
	P_THINK,
	__P_STATE_MAX
}					t_phil_state;

typedef struct		s_philosopher
{
	int				id;
	pthread_t		thread_id;
	size_t			hp;
	t_phil_state	state;
	t_fork			*forks[2];
	int				forks_held;
	_Atomic bool	alive;
}					t_philosopher;

typedef int			(*t_phil_action)(t_philosopher *);

int		philosopher_init(t_philosopher *philo, t_fork fork_list[PHILO_N], int id);
int		philosopher_run(t_philosopher *philo);
int		philosopher_stop(t_philosopher *philo);

#endif
