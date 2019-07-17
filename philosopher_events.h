#ifndef __PHILOSOPHER_EVENTS_H
# define __PHILOSOPHER_EVENTS_H

# include "philosopher.h"
# include "event.h"

void		philosopher_state_changed(t_philosopher *phil);
void		philosopher_hp_changed(t_philosopher *phil);
void		philosopher_fork_acquired(t_philosopher *phil, t_fork_side side);
void		philosopher_fork_released(t_philosopher *phil, t_fork_side side);
void		philosopher_died(t_philosopher *phil);

#endif
