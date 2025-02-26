#include "../push_swap.h"

static int  swap_pile(t_box **pile)
{
    t_box   *first;
    t_box   *second;
    // do nothing if only 1 box or none.
    if (!*pile || !(*pile)->next)
        return (1);
    first = (*pile);
    second = (*pile)->next; // this will be the second node
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *pile = second;
    return (0);
}
void    sa(t_box **pile_a)
{
    int nthng;
    nthng = swap_pile(pile_a);
    if (!nthng)
        ft_putstr_fd("sa\n", 1);
}
void    sb(t_box **pile_b)
{
    int nthng;
    nthng = swap_pile(pile_b);
    if (!nthng)
        ft_putstr_fd("sb\n", 1);
}
void    ss(t_box **pile_a, t_box **pile_b)
{
    int nthng_a;
    int nthng_b;
    nthng_a = swap_pile(pile_a);
    nthng_b = swap_pile(pile_b);
    if (!nthng_a && nthng_b)
        ft_putstr_fd("sa\n", 1);
    else if (!nthng_b && nthng_a)
        ft_putstr_fd("sb\n", 1);
    else
        ft_putstr_fd("ss\n", 1);
}