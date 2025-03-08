/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:42:35 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 12:54:26 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	push(t_box **from_pile, t_box **to_pile)
{
	t_box	*to_push;
	int		size;

	to_push = *from_pile;
	size = pile_size(*from_pile);
	if (size == 1)
	{
		append_box(to_pile, to_push);
		*from_pile = NULL;
	}
	else if (size > 1)
	{
		*from_pile = (*from_pile)->next;
		(*from_pile)->prev = NULL;
		append_box(to_pile, to_push);
	}
}

void	pa(t_box **pile_a, t_box **pile_b)
{
	if (!*pile_b)
		return ;
	push(pile_b, pile_a);
}

void	pb(t_box **pile_a, t_box **pile_b)
{
	if (!*pile_a)
		return ;
	push(pile_a, pile_b);
}
