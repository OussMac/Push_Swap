/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:34:26 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:36:53 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_piles(t_box **pile_a, t_box **pile_b, t_box *cheapest)
{
	while (*pile_b != cheapest && *pile_a != cheapest->target)
		rr(pile_a, pile_b);
	update_metadata(pile_a, pile_b);
}

static void	rev_rotate_piles(t_box **pile_a, t_box **pile_b, t_box *cheapest)
{
	while (*pile_b != cheapest && *pile_a != cheapest->target)
		rrr(pile_a, pile_b);
	update_metadata(pile_a, pile_b);
}

static t_box	*find_cheapest(t_box *pile_b)
{
	if (!pile_b)
		return (NULL);
	while (pile_b)
	{
		if (pile_b->cheapest == true)
			return (pile_b);
		pile_b = pile_b->next;
	}
	return (NULL);
}

static void	move_to_a(t_box **pile_a, t_box **pile_b)
{
	t_box	*cheapest;

	cheapest = find_cheapest(*pile_b);
	if (!cheapest)
		return ;
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_piles(pile_a, pile_b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_piles(pile_a, pile_b, cheapest);
	settle_at_top(pile_a, cheapest->target, 'A');
	settle_at_top(pile_b, cheapest, 'B');
	pa(pile_a, pile_b);
}

void	big_pile(t_box **pile_a, t_box **pile_b)
{
	t_box	*smallest;

	ranking_system(pile_a, pile_b);
	three_boxes(pile_a);
	while (*pile_b)
	{
		update_metadata(pile_a, pile_b);
		move_to_a(pile_a, pile_b);
	}
	update_metadata(pile_a, pile_b);
	smallest = find_smallest(*pile_a);
	while (*pile_a != smallest)
	{
		if (smallest->above_median)
			ra(pile_a);
		else
			rra(pile_a);
	}
}
