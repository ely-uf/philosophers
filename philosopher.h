#ifndef __PHILOSOPHER_H
# define __PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include "philo_const.h"
# include "fork.h"

typedef enum		e_phil_state
{
	P_EAT,
	P_REST,
	P_THINK
}					t_phil_state;

typedef struct		s_philosopher
{
	int				id;
	pthread_t		thread_id;
	size_t			hp;
	t_phil_state	state;
	t_fork			*forks[2];
}					t_philosopher;

int		philosopher_init(t_philosopher *philo, t_fork fork_list[PHILO_N], int id);

#endif
