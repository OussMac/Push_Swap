#include "push_swap.h"

static t_box    *find_big(t_box *pile)
{
    int     big_value;
    t_box   *biggest;

    big_value = INT_MIN;
    while (pile)
    {
        if (pile->value >= big_value)
        {
            big_value = pile->value;
            biggest = pile;
        }
        pile = pile->next;
    }
    return (biggest);
}

void    two_boxes(t_box **pile)
{
    if ((*pile)->value > (*pile)->next->value)
        sa(pile);
}

void    three_boxes(t_box **pile)
{
    t_box   *big_box;

    big_box = find_big(*pile);
    if (*pile == big_box)
        ra(pile);
    else if ((*pile)->next == big_box)
        rra(pile);
    if ((*pile)->value > (*pile)->next->value)
        sa(pile);
}