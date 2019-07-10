#include "fork.h"

int		fork_init(t_fork *fork, int id)
{
	fork->id = id;
	return (pthread_mutex_init(&fork->mutex, NULL));
}
