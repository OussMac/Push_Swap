#include "../push_swap.h"

static int  swap_pile(t_box **pile)
{
    t_box   *first;
    t_box   *second;
    // do nothing if only 1 box or none.
    if (!pile || !*pile || !(*pile)->next)
        return (0);
    first = (*pile);
    second = (*pile)->next; // this will be the second node
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *pile = second;
    return (1);
}
void    sa(t_box **pile_a)
{
    if (swap_pile(pile_a))
        ft_putstr_fd("sa\n", 1);
}
void    sb(t_box **pile_b)
{
    if(swap_pile(pile_b))
        ft_putstr_fd("sb\n", 1);
}
void    ss(t_box **pile_a, t_box **pile_b)
{
    int ret_a;
    int ret_b;

    ret_a = swap_pile(pile_a);
    ret_b = swap_pile(pile_b);
    if (ret_a && ret_b)
    {
        ft_putstr_fd("ss\n", 1);
        return ;
    }
    if (ret_a)
        ft_putstr_fd("sa\n", 1);
    else if (ret_b)
        ft_putstr_fd("sb\n", 1);
}
