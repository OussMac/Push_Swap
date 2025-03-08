/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:40:00 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:40:54 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (rotate(pile_a))
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_box **pile_b)
{
	if (rotate(pile_b))
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_box **pile_a, t_box **pile_b)
{
	int	ret_a;
	int	ret_b;

	ret_a = rotate(pile_a);
	ret_b = rotate(pile_b);
	if (ret_a && ret_b)
	{
		ft_putstr_fd("rr\n", 1);
		return ;
	}
	if (ret_a)
		ft_putstr_fd("ra\n", 1);
	else if (ret_b)
		ft_putstr_fd("rb\n", 1);
}
