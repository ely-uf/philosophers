#include "philosopher_routine.h"
#include "philosopher_actions.h"
#include "philosopher_events.h"
#include "philo_const.h"
#include "event.h"
#include "eventq_singleton.h"
#include <sys/time.h>
#include <unistd.h>

extern const	t_phil_action	g_phil_actions[__P_STATE_MAX];

void		philosopher_hp_lose(t_philosopher *phil, size_t hp_to_lose)
{
	if (phil->hp < hp_to_lose)
		philosopher_hp_change(phil, 0);
	else
		philosopher_hp_change(phil, phil->hp - hp_to_lose);
}

void		*philosopher_routine(void *_self)
{
	t_philosopher	* const self = _self;
	time_t					last_second;
	time_t					curr_second;

	last_second = time(NULL);
	while (self->alive)
	{
		if (self->suspended)
		{
			time(&last_second);
			usleep(PHILO_PAUSE_MSECONDS);
			continue ;
		}
		g_phil_actions[self->state](self);
		if (time(&curr_second) > last_second)
		{
			last_second = curr_second;
			philosopher_hp_lose(self, 1);
		}
		if (self->hp == 0)
			philosopher_die(self);
		self->mseconds_alive += PHILO_PAUSE_MSECONDS;
		usleep(PHILO_PAUSE_MSECONDS * 1000);
	}

	return (NULL);
}
