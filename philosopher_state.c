#include "philosopher.h"
#include "philosopher_state.h"

const	t_phil_action	phil_actions[__P_STATE_MAX] = {
	[P_EAT] = philosopher_eat,
	[P_REST] = philosopher_rest,
	[P_THINK] = philosopher_think,
};

int		philosopher_eat(t_philosopher *phil)
{
	(void)phil;
	return (0);
}

int		philosopher_rest(t_philosopher *phil)
{
	(void)phil;
	return (0);
}

int		philosopher_think(t_philosopher *phil)
{
	(void)phil;
	return (0);
}
