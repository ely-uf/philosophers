#ifndef __FORK_H
# define __FORK_H

# include <pthread.h>

typedef struct		s_fork
{
	int				id;
	pthread_mutex_t mutex;
}					t_fork;

#endif
