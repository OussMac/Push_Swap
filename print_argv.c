#include "push_swap.h"

void    print_argv(char **av)
{
    int i;

    i = 0;
    while(av[i])
    {
        ft_putstr_fd(av[i], 1);
        ft_putstr_fd("\n", 1);
        i++;
    }
}