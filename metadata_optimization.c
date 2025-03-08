/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_optimization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:22:34 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:24:18 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_rank(int box_value, t_box **pile)
{
	t_box	*curr;
	int		rank;

	curr = *pile;
	rank = 0;
	while (curr)
	{
		if (box_value != curr->value && box_value > curr->value)
			rank++;
		curr = curr->next;
	}
	return (rank);
}

void	update_rank(t_box **pile)
{
	t_box	*curr;

	if (!pile || !*pile)
		return ;
	curr = *pile;
	while (curr)
	{
		curr->rank = set_rank(curr->value, pile);
		curr = curr->next;
	}
}

void	ranking_system(t_box **pile_a, t_box **pile_b)
{
	t_box	*curr;

	while (pile_size(*pile_a) > 3)
	{
		curr = *pile_a;
		update_metadata(pile_a, pile_b);
		if (curr->rank <= pile_size(*pile_a) / 2)
			pb(pile_a, pile_b);
		else
			ra(pile_a);
	}
}
