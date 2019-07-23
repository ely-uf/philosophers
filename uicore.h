#ifndef __UICORE_H
# define __UICORE_H

# include "util.h"
# include <pthread.h>
# include "sdl2_tools.h"
# include "simulation.h"
# include "eventq_singleton.h"

# define WINX 600
# define WINY 600

typedef struct      s_uicore {
    pthread_t       thread_id;
    t_sdl2_tools    *sdl2;
    pthread_t       *simulation_thread;
}                   t_uicore;


int run_ui(pthread_t *simulation_thread);

void stop_ui(t_uicore *uicore);

#endif /* __UICORE_H */