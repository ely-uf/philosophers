#ifndef __PHILOSOPHER_ACTION
# define __PHILOSOPHER_ACTION

# include "philosopher.h"

void	philosopher_state_change(t_philosopher *phil, t_phil_state state);
void	philosopher_hp_change(t_philosopher *phil, int new_hp);
void	philosopher_die(t_philosopher *phil);

#endif
