#ifndef __PHILO_CONST_H
# define __PHILO_CONST_H

# ifndef PHILO_N
#  define PHILO_N	7
# endif

# if PHILO_N % 2 == 0
#  error "The number of philosophers should be odd."
# endif

# define MAX_LIFE   10
# define EAT_T      1
# define REST_T     3
# define THINK_T    3
# define TIMEOUT    15

#endif
