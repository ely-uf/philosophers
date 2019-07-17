#ifndef __FORK_H
# define __FORK_H

# include <pthread.h>

typedef enum		e_fork_side
{
	F_LEFT = 0,
	F_RIGHT = 1
}					t_fork_side;

typedef struct		s_fork
{
	int				id;
	pthread_mutex_t mutex;
}					t_fork;

int		fork_init(t_fork *fork, int id);
void	fork_deinit(t_fork *fork);

#endif
