#include "simulation.h"

/*
**	Avoiding global variables...
*/

static bool	*simulation_status(void)
{
	static bool alive = true;

	return (&alive);
}

bool		simulation_alive(void)
{
	return (*simulation_status());
}

void		simulation_stop(void)
{
	*simulation_status() = false;
}
