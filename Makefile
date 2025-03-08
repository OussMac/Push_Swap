CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
CHECKER = checker

HEADER = push_swap.h
HEADER_B = bonus/checker.h

SRC = 	push_swap.c ft_split.c ft_split_utils.c ft_putstr_fd.c build_pile_a.c \
		error_parser.c pocket_parser.c commands/cmd_swap.c commands/cmd_push.c \
		commands/cmd_utils.c commands/cmd_rot.c commands/cmd_rev_rot.c \
		small_pile.c update_metadata.c metadata_utils.c \
		big_pile.c metadata_optimization.c

SRC_B = bonus/checker_bonus.c bonus/ft_split_bonus.c bonus/ft_split_utils_bonus.c \
		bonus/ft_putstr_fd_bonus.c bonus/build_pile_a_bonus.c bonus/error_parser_bonus.c \
		bonus/pocket_parser_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c \
		bonus/commands/cmd_swap.c bonus/commands/cmd_push.c bonus/commands/cmd_utils.c \
		bonus/commands/cmd_rot.c bonus/commands/cmd_rev_rot.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

$(CHECKER): $(OBJ_B)
	$(CC) $(OBJ_B) -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER_B)
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME) $(NAME_B)

clean:
	rm -f $(OBJ) $(OBJ_B)

re: fclean all

.PHONY: clean