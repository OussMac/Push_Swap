/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_metadata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:52:17 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:44:39 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_median(t_box **pile)
{
	int		median;
	t_box	*curr;

	if (!pile || !*pile)
		return ;
	median = pile_size(*pile) / 2;
	curr = *pile;
	while (curr)
	{
		if (curr->index <= median)
			curr->above_median = true;
		else
			curr->above_median = false;
		curr = curr->next;
	}
}

static void	update_index(t_box **pile)
{
	int		i;
	t_box	*curr;

	i = 0;
	if (!pile || !*pile)
		return ;
	curr = *pile;
	while (curr)
	{
		curr->index = i;
		i++;
		curr = curr->next;
	}
}

static t_box	*find_smallest_big(t_box **pile_a, int b_value)
{
	t_box	*curr_a;
	t_box	*sb_target;
	int		sb_value;

	curr_a = *pile_a;
	sb_target = NULL;
	sb_value = INT_MAX;
	while (curr_a)
	{
		if (b_value < curr_a->value && curr_a->value < sb_value)
		{
			sb_value = curr_a->value;
			sb_target = curr_a;
		}
		curr_a = curr_a->next;
	}
	if (sb_value == INT_MAX)
		sb_target = find_smallest(*pile_a);
	return (sb_target);
}

static void	update_target(t_box **pile_a, t_box **pile_b)
{
	t_box	*curr_b;

	if (!pile_b || !*pile_b)
		return ;
	curr_b = *pile_b;
	while (curr_b)
	{
		curr_b->target = find_smallest_big(pile_a, curr_b->value);
		curr_b = curr_b->next;
	}
}

void	update_metadata(t_box **pile_a, t_box **pile_b)
{
	update_index(pile_a);
	update_index(pile_b);
	update_rank(pile_a);
	update_rank(pile_b);
	update_median(pile_a);
	update_median(pile_b);
	update_target(pile_a, pile_b);
	update_pushcost(pile_a, pile_b);
	update_cheapest(pile_b);
}
