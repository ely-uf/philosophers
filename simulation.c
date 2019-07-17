#include "simulation.h"
#include "philo_const.h"
#include "philosopher.h"
#include "fork.h"

static int	simulation_init(t_philosopher ph[PHILO_N], t_fork forks[FORK_N])
{
	size_t	i;

	i = 0;
	while (i < FORK_N)
	{
		fork_init(&forks[i], i);
		i++;
	}

	i = 0;
	while (i < PHILO_N)
	{
		philosopher_init(&ph[i], forks, i);
		i++;
	}

	return (0);
}

static void	simulation_deinit(t_philosopher ph[PHILO_N], t_fork forks[FORK_N])
{
	size_t	i;

	i = 0;
	while (i < FORK_N)
	{
		fork_deinit(&forks[i]);
		i++;
	}
	(void)ph;
}

int			simulation_run(void)
{
	t_philosopher	philosophers[PHILO_N];
	t_fork			forks[FORK_N];

	simulation_init(philosophers, forks);

	/*
	 *	TODO: Run philosopher threads.
	 */

	simulation_deinit(philosophers, forks);

	return (0);
}
