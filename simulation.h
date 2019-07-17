#ifndef __SIMULATION_H
# define __SIMULATION_H

# include <stdbool.h>

typedef enum	e_simul_state
{
	S_RUNNING,
	S_SUSPENDED,
	S_DONE
}				t_simstate;

int			simulation_run(void);
void		simulation_suspend(void);
void		simulation_resume(void);
void		simulation_stop(void);
t_simstate	simulation_state_get(void);

#endif
