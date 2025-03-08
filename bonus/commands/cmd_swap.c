/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:38:17 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 12:38:17 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	swap_pile(t_box **pile)
{
	t_box	*first;
	t_box	*second;

	if (!pile || !*pile || !(*pile)->next)
		return (0);
	first = (*pile);
	second = (*pile)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*pile = second;
	return (1);
}

void	sa(t_box **pile_a)
{
	swap_pile(pile_a);
}

void	sb(t_box **pile_b)
{
	swap_pile(pile_b);
}

void	ss(t_box **pile_a, t_box **pile_b)
{
	swap_pile(pile_a);
	swap_pile(pile_b);
}
