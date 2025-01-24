#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


// external libraries
# include <unistd.h> // for writing instructions.
# include <stdbool.h> // for true or false flags.
# include <stdlib.h> // for heap usage, mem allocation.
# include <unistd.h> // for write, writing commands.


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

// for printing Errors, and commands.
void    ft_putstr_fd(char *s, int fd);

// libraries for testing.
# include <stdio.h>
// functions for testing
void    print_argv(char **av);


#endif // PUSH_SWAP_H