#include "philosopher_actions.h"
#include "philosopher_events.h"

void	philosopher_state_change(t_philosopher *phil, t_phil_state state)
{
	phil->state = state;
	philosopher_state_changed(phil);
}

void	philosopher_hp_change(t_philosopher *phil, int new_hp)
{
	phil->hp = new_hp;
	philosopher_hp_changed(phil);
}

void	philosopher_die(t_philosopher *phil)
{
	phil->alive = false;
	philosopher_died(phil);
}
