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

int		fork_try_acquire(t_fork *fork)
{
	return (pthread_mutex_trylock(&fork->mutex));
}

void	fork_release(t_fork *fork)
{
	pthread_mutex_unlock(&fork->mutex);
}
