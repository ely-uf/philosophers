#include <pthread.h>
#include "philosopher.h"
#include "philosopher_state.h"
#include "philosopher_events.h"
#include "philosopher_actions.h"

const	t_phil_action	g_phil_actions[__P_STATE_MAX] = {
	[P_EAT] = philosopher_eat,
	[P_REST] = philosopher_rest,
	[P_THINK] = philosopher_think,
};

int		philosopher_eat(t_philosopher *phil)
{
	size_t	msecs_in_state;

	msecs_in_state = phil->mseconds_alive - phil->state_start_time;
	if (msecs_in_state >= SEC_TO_MSEC(EAT_T))
	{
		fork_release(phil->forks[F_LEFT]);
		philosopher_fork_released(phil, F_LEFT);
		fork_release(phil->forks[F_RIGHT]);
		philosopher_fork_released(phil, F_RIGHT);
		philosopher_state_change(phil, P_REST);
	}

	philosopher_hp_change(phil, MAX_LIFE);

	return (0);
}

int		philosopher_rest(t_philosopher *phil)
{
	size_t	msecs_in_state;

	msecs_in_state = phil->mseconds_alive - phil->state_start_time;
	if (msecs_in_state >= SEC_TO_MSEC(REST_T))
		philosopher_state_change(phil, P_THINK);
	return (0);
}

void	philosopher_fork_try_grab(t_philosopher *phil)
{
	t_fork_side	fork_to_grab;

	if (phil->forks_held == 0)
		fork_to_grab = phil->forks[F_LEFT]->id < phil->forks[F_RIGHT]->id ?
					F_LEFT : F_RIGHT;
	else
		fork_to_grab = phil->forks[F_LEFT]->id < phil->forks[F_RIGHT]->id ?
					F_RIGHT : F_LEFT;

	if (fork_try_acquire(phil->forks[fork_to_grab]) == 0)
	{
		philosopher_fork_acquired(phil, fork_to_grab);
		phil->forks_held++;
	}
}

int		philosopher_think(t_philosopher *phil)
{
	size_t	msecs_in_state;

	if (phil->forks_held == 2)
	{
		msecs_in_state = phil->mseconds_alive - phil->state_start_time;
		if (msecs_in_state < SEC_TO_MSEC(THINK_T))
			return (0);
		philosopher_state_change(phil, P_EAT);
		return (0);
	}

	philosopher_fork_try_grab(phil);

	return (0);
}
