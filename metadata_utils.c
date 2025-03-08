/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:14:23 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:21:58 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*find_smallest(t_box *pile)
{
	int		small_value;
	t_box	*curr;
	t_box	*small;

	curr = pile;
	small = NULL;
	small_value = INT_MAX;
	while (curr)
	{
		if (curr->value <= small_value)
		{
			small_value = curr->value;
			small = curr;
		}
		curr = curr->next;
	}
	return (small);
}

static int	max_cost(int a_cost, int b_cost)
{
	if (a_cost > b_cost)
		return (a_cost);
	return (b_cost);
}

void	update_pushcost(t_box **pile_a, t_box **pile_b)
{
	t_box	*curr;
	t_pcost	vars;

	if (!pile_b || !*pile_b)
		return ;
	curr = *pile_b;
	vars.a_size = pile_size(*pile_a);
	vars.b_size = pile_size(*pile_b);
	while (curr)
	{
		if (curr->above_median == true)
			vars.b_cost = curr->index;
		else
			vars.b_cost = vars.b_size - curr->index;
		if (curr->target->above_median == true)
			vars.a_cost = curr->target->index;
		else
			vars.a_cost = (vars.a_size - curr->target->index);
		if (curr->above_median == curr->target->above_median)
			curr->push_cost = max_cost(vars.a_cost, vars.b_cost);
		else
			curr->push_cost = vars.a_cost + vars.b_cost;
		curr = curr->next;
	}
}

void	update_cheapest(t_box **pile_b)
{
	t_box	*curr;
	int		cheapest;

	if (!pile_b || !*pile_b)
		return ;
	curr = *pile_b;
	cheapest = curr->push_cost;
	while (curr)
	{
		if (curr->push_cost < cheapest)
			cheapest = curr->push_cost;
		curr = curr->next;
	}
	curr = *pile_b;
	while (curr)
	{
		curr->cheapest = (cheapest == curr->push_cost);
		curr = curr->next;
	}
}

void	settle_at_top(t_box **pile, t_box *cheapest, char pile_name)
{
	if (!*pile)
		return ;
	while (*pile != cheapest)
	{
		if (pile_name == 'A')
		{
			if (cheapest->above_median)
				ra(pile);
			else
				rra(pile);
		}
		else if (pile_name == 'B')
		{
			if (cheapest->above_median)
				rb(pile);
			else
				rrb(pile);
		}
	}
}
