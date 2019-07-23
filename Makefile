NAME = philo
SRC = main.c event.c eventq.c eventq_singleton.c simulation.c \
	  simulation_status.c philosopher.c fork.c \
	  philosopher_events.c philosopher_actions.c \
	  philosopher_state.c philosopher_routine.c \
	  uicore.c sdl2_tools.c 
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra

# -----------------------------------------------------------

FRMPATH = -F/Library/Frameworks

FRAMEWORKS = -framework SDL2

# libLodePNG

LIBLODEPNGBIN = liblodepng/libLodePNG.a


LIBLODEINC = liblodepng

LIBLODEPNG = liblodepng

# -----------------------------------------------------------

LIBS = -lLodePNG -pthread

LIBSDIR = -L$(LIBLODEPNG)

LIBSINC = -I$(LIBLODEINC)

# -----------------------------------------------------------

all: $(NAME)

$(NAME): $(LIBLODEPNGBIN) $(OBJ)
	$(CC) $(OBJ) $(FRMPATH) $(FRAMEWORKS) $(LIBSDIR) $(LIBS) -o $(NAME)

$(LIBLODEPNGBIN): lode.all

%.o:%.c
	$(CC) $(CFLAGS) $(FRMPATH) $(LIBSINC) -c $< -o $@

clean: lode.clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBLODEPNGBIN)

re: fclean all

lode.all:
	@echo  "\x1b[32mliblodepng   compiles...\x1b[0m"
	@make -C liblodepng/ all

lode.clean:
	@make -C liblodepng/ clean

lode.fclean:
	@make -C liblodepng/ fclean

lode.re:
	@make -C liblodepng/ re

.phony: all clean fclean re lode.all lode.clean lode.fclean lode.re

