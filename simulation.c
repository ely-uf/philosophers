#include "simulation.h"
#include "philo_const.h"
#include "philosopher.h"
#include "fork.h"

int		simulation_run(void)
{
	t_philosopher	philosophers[PHILO_N];
	t_fork			forks[PHILO_N];
	int				i;

	i = 0;
	while (i < PHILO_N)
	{
		fork_init(&forks[i], i);
		i++;
	}

	i = 0;
	while (i < PHILO_N)
	{
		philosopher_init(&philosophers[i], forks, i);
		i++;
	}

	/*
	 *	TODO: Run philosopher threads.
	 */

	return (0);
}
