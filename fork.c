#include "fork.h"

void	fork_deinit(t_fork *fork)
{
	pthread_mutex_destroy(&fork->mutex);
}

int		fork_init(t_fork *fork, int id)
{
	fork->id = id;
	return (pthread_mutex_init(&fork->mutex, NULL));
}
