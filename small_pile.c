/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:55:51 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:00:36 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_small(t_box **pile_a, t_box **pile_b)
{
	t_box	*small;

	small = find_smallest(*pile_a);
	if (small->above_median == true)
		ra(pile_a);
	else
		rra(pile_a);
	if (*pile_a == small)
		pb(pile_a, pile_b);
}

static t_box	*find_big(t_box *pile)
{
	int		big_value;
	t_box	*biggest;

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

void	two_boxes(t_box **pile)
{
	if ((*pile)->value > (*pile)->next->value)
		sa(pile);
}

void	three_boxes(t_box **pile)
{
	t_box	*big_box;

	big_box = find_big(*pile);
	if (*pile == big_box)
		ra(pile);
	else if ((*pile)->next == big_box)
		rra(pile);
	if ((*pile)->value > (*pile)->next->value)
		sa(pile);
}

void	five_boxes(t_box **pile_a, t_box **pile_b)
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
