#include "push_swap.h"

static void    update_median(t_box **pile)
{
    int     size;
    t_box   *curr;

    if(!pile || !*pile)
        return ;
    size = pile_size(*pile);
    curr = *pile;
    while (curr)
    {
        if (curr->index <= (size / 2))
            curr->above_median = true;
        else
            curr->above_median = false;
        curr = curr->next;
    }
}

static void    update_index(t_box **pile)
{
    int     i;
    t_box   *curr;

    i = 0;
    if (!pile || !*pile)
        return ;
    curr = *pile;
    while (curr)
    {
        curr->index = i;
        curr = curr->next;
        i++;
    }
}


void    update_metadata(t_box **pile_a, t_box **pile_b)
{
    // update index for boxes;
    update_index(pile_a);
    update_index(pile_b);
    // update current median value for both piles. (needs index)
    update_median(pile_a);
    update_median(pile_b);
}