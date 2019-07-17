#include "simulation.h"

/*
**	Avoiding global variables...
*/

static t_simstate	*_simulation_state_get(void)
{
	static t_simstate alive = S_RUNNING;

	return (&alive);
}

void		simulation_suspend(void)
{
	*_simulation_state_get() = S_SUSPENDED;
}

void		simulation_resume(void)
{
	*_simulation_state_get() = S_RUNNING;
}

void		simulation_stop(void)
{
	*_simulation_state_get() = S_DONE;
}

t_simstate	simulation_state_get(void)
{
	return (*_simulation_state_get());
}
