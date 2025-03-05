#include "push_swap.h"

static void    push_small(t_box **pile_a, t_box **pile_b)
{
    int     small_value;
    t_box   *curr;
    t_box   *small;

    curr = *pile_a;
    small = NULL;
    small_value = INT_MAX;
    while(curr)
    {
        if (curr->value <= small_value)
        {
            small_value = curr->value;
            small = curr;
        }
        curr = curr->next;
    }
    if (small->above_median == true)
        ra(pile_a);
    else
        rra(pile_a);
    if (*pile_a == small)
        pb(pile_a, pile_b);
}

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

void    five_boxes(t_box **pile_a, t_box **pile_b)
{
    while (pile_size(*pile_a) > 3)
    {
        update_metadata(pile_a, pile_b);
        push_small(pile_a, pile_b);
    }
    three_boxes(pile_a);
    while (*pile_b)
        pa(pile_a, pile_b);
}

/*
    five boxes algo

    --> declare a size variable to keep track of size
    --> find smallest and push to b
    --> size--;
    --> find second smallest and push to b
    --> size--;
    --> now we only have big numbers in a
    --> if (size == 3)
        --> sort three boxes;
    push back from b if og size was 5
    push back once if it was 4;
*/