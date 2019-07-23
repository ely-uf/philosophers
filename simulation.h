#ifndef __SIMULATION_H
# define __SIMULATION_H

# include <stdbool.h>
# include <pthread.h>

typedef enum	e_simul_state
{
	S_RUNNING,
	S_SUSPENDED,
	S_DONE
}				t_simstate;

int			simulation_run(pthread_t *simulation_thread);
int 		simulation_kill(pthread_t *simulation_thread);
void		simulation_suspend(void);
void		simulation_resume(void);
void		simulation_stop(void);
t_simstate	simulation_state_get(void);

#endif
