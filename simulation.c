#include <unistd.h>
#include "simulation.h"
#include "philo_const.h"
#include "philosopher.h"
#include "fork.h"
#include "event.h"
#include "eventq_singleton.h"

static int	simulation_init(t_philosopher ph[PHILO_N], t_fork forks[FORK_N])
{
	size_t	i;

	event_dispatch(eventq_get(), (t_event){ .type = P_SIMULATION_INIT });

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

static void *_simulation_run(void *unused)
{
	t_philosopher	philosophers[PHILO_N];
	t_fork			forks[FORK_N];
	size_t			mseconds;

	(void)unused;
	simulation_init(philosophers, forks);
	philosophers_run(philosophers);

	mseconds = 0;
	while (simulation_state_get() != S_DONE)
	{
		usleep(SIMUL_STEP_MSECONDS * 1000);
		if (simulation_state_get() == S_SUSPENDED)
			continue ;
		mseconds += SIMUL_STEP_MSECONDS;
		if (mseconds >= SEC_TO_MSEC(TIMEOUT))
			simulation_stop();
	}

	philosophers_stop(philosophers);
	simulation_deinit(philosophers, forks);
	return (NULL);
}

int			simulation_run(pthread_t *simulation_thread)
{
	return (pthread_create(simulation_thread, NULL, _simulation_run, NULL));
}

int 		simulation_kill(pthread_t *simulation_thread)
{
	return (pthread_join(*simulation_thread, NULL));
}
