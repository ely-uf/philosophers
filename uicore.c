
#include "uicore.h"


void *run_loop(t_uicore *uicore)
{
    SDL_Event   event;

	SDL_RenderPresent(uicore->sdl2->renderer);
	while (1) {
		SDL_PollEvent(&event);
		if ((event.type == SDL_QUIT) || (event.key.keysym.sym == SDLK_ESCAPE))
        {
            stop_ui(uicore);
            PRINT_CONST("STOP UI\n");
            // TODO: Ask Erik about sim states
            simulation_kill(uicore->simulation_thread);
            PRINT_CONST("SIM_KILL\n");
            break ;
        }
	}
    return (NULL);
}

int run_ui(pthread_t *simulation_thread)
{
    t_uicore uicore;

	uicore.sdl2 = sdl2_init(WINX, WINY);
    uicore.simulation_thread = simulation_thread;
    run_loop(&uicore);
    return (0);
}

void stop_ui(t_uicore *uicore)
{
    sdl2_release(uicore->sdl2);
    eventq_deinit(eventq_get());
}
