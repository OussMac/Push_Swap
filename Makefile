CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEADER = push_swap.h

SRC = push_swap.c ft_split.c ft_split_utils.c ft_putstr_fd.c print_argv.c print_errors.c init_pile_a.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: clean