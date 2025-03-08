/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:40:00 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 12:37:48 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	rotate(t_box **pile)
{
	t_box	*to_rotate;
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
		to_rotate = *pile;
		*pile = (*pile)->next;
		(*pile)->prev = NULL;
		last_box = find_lastbox(*pile);
		last_box->next = to_rotate;
		to_rotate->prev = last_box;
		to_rotate->next = NULL;
	}
	return (1);
}

void	ra(t_box **pile_a)
{
	rotate(pile_a);
}

void	rb(t_box **pile_b)
{
	rotate(pile_b);
}

void	rr(t_box **pile_a, t_box **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
}
