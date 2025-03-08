/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:29:18 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 07:32:06 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	syntax_parser(char *str)
{
	int	i;

	i = 0;
	if (!ft_issign(str[i]) && !ft_isdigit(str[i]))
		return (true);
	if (ft_issign(str[i]) && !ft_isdigit(str[i + 1]))
		return (true);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	duplicate_parser(t_box **pile_a, int new_value)
{
	t_box	*cur;

	if (!*pile_a)
		return (false);
	cur = *pile_a;
	while (cur)
	{
		if (cur->value == new_value)
			return (true);
		cur = cur->next;
	}
	return (false);
}

void	free_pile(t_box **pile_a)
{
	t_box	*cur;
	t_box	*tmp;

	if (!*pile_a)
		return ;
	cur = *pile_a;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}

void	free_failure(t_box **pile_a, char **av, bool argc_2)
{
	free_pile(pile_a);
	free_argv(av, argc_2);
	print_error();
}

bool	sorted_pile(t_box *pile_a)
{
	t_box	*current;

	if (!pile_a)
		return (true);
	current = pile_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
