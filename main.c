#include "simulation.h"
#include "util.h"
#include "eventq.h"
#include "eventq_singleton.h"

int main(void)
{
	int		ret;

	eventq_init(eventq_get());

	ret = simulation_run();
	if (ret != 0)
		PRINT_CONST("Failed to run the simulation.\n");

	eventq_deinit(eventq_get());
	return (ret);
}
