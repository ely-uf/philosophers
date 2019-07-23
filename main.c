#include "simulation.h"
#include "util.h"
#include "eventq.h"
#include "eventq_singleton.h"
#include "uicore.h"

int main(void)
{
	int		ret;
	pthread_t simulation_thread;

	eventq_init(eventq_get());

	ret = simulation_run(&simulation_thread);
	
	if (ret != 0) {
		PRINT_CONST("Failed to run the simulation.\n");
		eventq_deinit(eventq_get());
	}

	run_ui(&simulation_thread);
	
	return (ret);
}
