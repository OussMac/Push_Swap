/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:38:17 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:39:48 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (swap_pile(pile_a))
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_box **pile_b)
{
	if (swap_pile(pile_b))
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_box **pile_a, t_box **pile_b)
{
	int	ret_a;
	int	ret_b;

	ret_a = swap_pile(pile_a);
	ret_b = swap_pile(pile_b);
	if (ret_a && ret_b)
	{
		ft_putstr_fd("ss\n", 1);
		return ;
	}
	if (ret_a)
		ft_putstr_fd("sa\n", 1);
	else if (ret_b)
		ft_putstr_fd("sb\n", 1);
}
