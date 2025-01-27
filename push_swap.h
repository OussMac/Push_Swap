#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


// external libraries
# include <unistd.h> // for writing instructions.
# include <stdbool.h> // for true or false flags.
# include <stdlib.h> // for heap usage, mem allocation.
# include <unistd.h> // for write, writing commands.
# include <limits.h> // library for limits.


// doubly linked list data structure, type definition.
typedef struct s_box
{
    int value; // box value
    
    int index; // box metadata
    int push_cost;
    bool cheapest;
    bool above_median;
    struct s_box *target;

    struct s_box *next; // links
    struct s_box *prev;
} t_box;



// split utils -- in ft_split_utils.c
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	free_argv(char **av, bool argc_2);

// stack a initialization.
void    build_pile_a(t_box **pile_a, char **av, bool argc);

// error handling
bool    syntax_parser(char *str);
bool    duplicate_parser(t_box **pile_a, int num);
void    free_failure(t_box **pile_a, char **av, bool argc_2);
void    free_pile(t_box **pile_a);
bool    sorted_pile(t_box *pile_a);

// for printing Errors, and commands.
void    ft_putstr_fd(char *s, int fd);
void    print_error(void);
bool    ft_isdigit(char c);
bool    ft_issign(char c);

// libraries for testing.
# include <stdio.h>
// functions for testing
void    print_argv(char **av);
void    stack_printer(t_box *pile);


#endif // PUSH_SWAP_H