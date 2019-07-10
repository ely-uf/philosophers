#include "philosopher.h"

int		philosopher_init(t_philosopher *ph, t_fork fork_list[PHILO_N], int id)
{
	ph->id = id;
	ph->hp = MAX_LIFE;
	ph->state = P_THINK;
	ph->forks[F_RIGHT] = &fork_list[id];
	ph->forks[F_LEFT] = id == PHILO_N - 1 ? &fork_list[0] : &fork_list[id + 1];

	return (0);
}
