#include "../push_swap.h"

void    push(t_box **from_pile, t_box **to_pile)
{
    t_box   *box_to_push;
    t_box   *new_head;

    box_to_push = *from_pile;
    new_head = (*from_pile)->next;
    *from_pile = new_head;
    if (to_pile != NULL)
        box_to_push->next = *to_pile;
    box_to_push->prev = NULL;
    (*to_pile)->prev = box_to_push;
    *to_pile = (*to_pile)->prev;
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