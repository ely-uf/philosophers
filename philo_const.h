#ifndef __PHILO_CONST_H
# define __PHILO_CONST_H

# ifndef PHILO_N
#  define PHILO_N	7
# endif

# define FORK_N PHILO_N

# if PHILO_N % 2 == 0
#  error "The number of philosophers should be odd."
# endif

# define SEC_TO_MSEC(_sec) ((_sec) * 1000)
# define PHILO_PAUSE_MSECONDS	100
# define SIMUL_STEP_MSECONDS	30

# define MAX_LIFE   10
# define EAT_T      1
# define REST_T     10
# define THINK_T    1
# define TIMEOUT    20

#endif
