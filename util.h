#ifndef __UTIL_H
# define __UTIL_H

# include <unistd.h>
# define PRINT_CONST(_const_str) write(1, (_const_str), sizeof(_const_str) - 1);

#endif
