#include <sys/time.h>
#include "simulation.h"
#include "philo_const.h"
#include "philosopher.h"
#include "fork.h"
#include "event.h"
#include "eventq_singleton.h"

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

	event_dispatch(eventq_get(), (t_event){ .type = P_SIMULATION_INIT });

	return (0);
}

static void	simulation_deinit(t_philosopher ph[PHILO_N], t_fork forks[FORK_N])
{
	size_t	i;

	event_dispatch(eventq_get(), (t_event){ .type = P_SIMULATION_END });

	i = 0;
	while (i < FORK_N)
	{
		fork_deinit(&forks[i]);
		i++;
	}
	(void)ph;
}

static void	philosophers_run(t_philosopher philosophers[PHILO_N])
{
	size_t	i;

	i = 0;
	while (i < PHILO_N)
	{
		philosopher_run(&philosophers[i]);
		i++;
	}
}

static void	philosophers_stop(t_philosopher philosophers[PHILO_N])
{
	size_t	i;

	i = 0;
	while (i < PHILO_N)
	{
		philosopher_stop(&philosophers[i]);
		i++;
	}
}

int			simulation_run(void)
{
	t_philosopher	philosophers[PHILO_N];
	t_fork			forks[FORK_N];
	time_t			start_time;

	simulation_init(philosophers, forks);
	start_time = time(NULL);

	philosophers_run(philosophers);

	while (simulation_alive())
	{
		if (time(NULL) - start_time >= TIMEOUT)
			simulation_stop();
	}

	philosophers_stop(philosophers);

	simulation_deinit(philosophers, forks);

	return (0);
}
