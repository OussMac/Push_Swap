CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEADER = push_swap.h

SRC = 	push_swap.c ft_split.c ft_split_utils.c ft_putstr_fd.c print_argv.c build_pile_a.c \
		error_parser.c pocket_parser.c utils/.stack_printer.c \
		commands/cmd_swap.c commands/cmd_push.c commands/cmd_utils.c commands/cmd_rot.c \
		commands/cmd_rev_rot.c small_boxes.c update_metadata.c

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