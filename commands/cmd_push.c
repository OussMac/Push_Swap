#include "../push_swap.h"

void    push(t_box **from_pile, t_box **to_pile)
{
    (void)from_pile;
    (void)to_pile;
}

void    pa(t_box **pile_a, t_box **pile_b)
{
    if (!*pile_b)
        return;
    push(pile_b, pile_a);
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_box **pile_a, t_box **pile_b)
{
    if (!*pile_a)
        return;
    push(pile_a, pile_b);
    ft_putstr_fd("pb\n", 1);
}