/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:37:06 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 12:35:36 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	pile_size(t_box *pile)
{
	int	i;

	i = 0;
	if (!pile)
		return (0);
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

void	append_box(t_box **pile, t_box *new_box)
{
	if (!*pile)
	{
		*pile = new_box;
		(*pile)->next = NULL;
		(*pile)->prev = NULL;
		return ;
	}
	new_box->next = *pile;
	(*pile)->prev = new_box;
	*pile = new_box;
}

t_box	*find_lastbox(t_box *lst)
{
	t_box	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
