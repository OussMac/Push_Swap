#include "../push_swap.h"

/*
        push from a to b

        -> find first node on pile a, have a ptr to it
        -> move pile a head to next (only if pile_size > 1)
        -> else set it to null;
        -> update head prev to point to null;
        -> now attach node to b using append_box
*/

void    push(t_box **from_pile, t_box **to_pile)
{
    t_box   *to_push;
    int     size;

    to_push = *from_pile;
    size = pile_size(*from_pile);
    if (size == 1)
    {
        append_box(to_pile, to_push);
        *from_pile = NULL;
    }
    else if (size > 1)
    {
        *from_pile = (*from_pile)->next;
        (*from_pile)->prev = NULL;
        append_box(to_pile, to_push);
    }
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