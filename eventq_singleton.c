#include "eventq_singleton.h"

t_eventq			*eventq_get(void)
{
	static t_eventq eventq;
	return &eventq;
}
