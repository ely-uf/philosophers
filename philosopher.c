#include "philosopher.h"
#include "philosopher_actions.h"

void	*philosopher_routine(void *self)
{
	return (self);
}

int		philosopher_stop(t_philosopher *ph)
{
	ph->alive = false;
	pthread_join(ph->thread_id, NULL);
	return (0);
}

int		philosopher_run(t_philosopher *ph)
{
	return (pthread_create(&ph->thread_id, NULL, philosopher_routine, ph));
}

int		philosopher_init(t_philosopher *ph, t_fork fork_list[PHILO_N], int id)
{
	ph->id = id;
	philosopher_hp_change(ph, MAX_LIFE);
	philosopher_state_change(ph, P_THINK);
	ph->forks[F_RIGHT] = &fork_list[id];
	ph->forks[F_LEFT] = id == PHILO_N - 1 ? &fork_list[0] : &fork_list[id + 1];
	ph->forks_held = 0;

	return (0);
}
