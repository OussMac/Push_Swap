/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:41:13 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:42:11 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (rev_rotate(pile_a))
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_box **pile_b)
{
	if (rev_rotate(pile_b))
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_box **pile_a, t_box **pile_b)
{
	int	ret_a;
	int	ret_b;

	ret_a = rev_rotate(pile_a);
	ret_b = rev_rotate(pile_b);
	if (ret_a && ret_b)
	{
		ft_putstr_fd("rrr\n", 1);
		return ;
	}
	if (ret_a)
		ft_putstr_fd("rra\n", 1);
	else if (ret_b)
		ft_putstr_fd("rrb\n", 1);
}
