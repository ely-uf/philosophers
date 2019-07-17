NAME = philo
SRC = main.c event.c eventq.c eventq_singleton.c simulation.c \
	  simulation_status.c philosopher.c fork.c \
	  philosopher_events.c philosopher_actions.c \
	  philosopher_state.c philosopher_routine.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
