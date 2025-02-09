#include "../push_swap.h"

static void  swap_pile(t_box **pile)
{
    t_box *first;

    // do nothing if only 1 box or none.
    if (!*pile || !(*pile)->next)
        return ;
    first = (*pile)->next; // this will be the first node
    first->next = *pile;
    first->prev = NULL;
    (*pile)->prev = first;
    (*pile)->next = NULL;
    *pile = first;
}

void    sa(t_box **pile_a)
{
    swap_pile(pile_a);
    ft_putstr_fd("sa\n", 1);
}


void    sb(t_box **pile_b)
{
    swap_pile(pile_b);
    ft_putstr_fd("sb\n", 1);
}

void    ss(t_box **pile_a, t_box **pile_b)
{
    swap_pile(pile_a);
    swap_pile(pile_b);
    ft_putstr_fd("ss\n", 1);
}