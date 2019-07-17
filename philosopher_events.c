#include "philosopher.h"
#include "philosopher_events.h"
#include "event.h"
#include "eventq_singleton.h"

void		philosopher_state_changed(t_philosopher *phil)
{
	event_dispatch(eventq_get(), (t_event){
		.type = P_PHILO_STATE_CHANGED,
		.ev = {
			.state = {
				.id = phil->id,
				.state = phil->state
			}
		}
	});
}

void		philosopher_hp_changed(t_philosopher *phil)
{
	event_dispatch(eventq_get(), (t_event){
		.type = P_PHILO_HP_CHANGED,
		.ev = {
			.health = {
				.id = phil->id,
				.new_hp = phil->hp,
			}
		}
	});
}

void		philosopher_fork_acquired(t_philosopher *phil, t_fork_side side)
{
	event_dispatch(eventq_get(), (t_event){
		.type = P_PHILO_FORK_ACQUIRED,
		.ev = {
			.fork = {
				.id = phil->id,
				.fork_side = side,
			}
		}
	});
}

void		philosopher_fork_released(t_philosopher *phil, t_fork_side side)
{
	event_dispatch(eventq_get(), (t_event){
		.type = P_PHILO_FORK_RELEASED,
		.ev = {
			.fork = {
				.id = phil->id,
				.fork_side = side,
			}
		}
	});
}

void		philosopher_died(t_philosopher *phil)
{
	event_dispatch(eventq_get(), (t_event){
		.type = P_PHILO_DIED,
		.ev = {
			.died = {
				.id = phil->id,
			}
		}
	});
}

