/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:41:13 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 12:37:20 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	rev_rotate(t_box **pile)
{
	t_box	*last_box;
	int		size;

	size = pile_size(*pile);
	if (size <= 1)
		return (0);
	else if (size == 2)
	{
		swap_pile(pile);
		return (1);
	}
	else
	{
		last_box = find_lastbox(*pile);
		last_box->prev->next = NULL;
		last_box->prev = NULL;
		append_box(pile, last_box);
	}
	return (1);
}

void	rra(t_box **pile_a)
{
	rev_rotate(pile_a);
}

void	rrb(t_box **pile_b)
{
	rev_rotate(pile_b);
}

void	rrr(t_box **pile_a, t_box **pile_b)
{
	rev_rotate(pile_a);
	rev_rotate(pile_b);
}
