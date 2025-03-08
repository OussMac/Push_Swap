/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pile_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:32:19 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 11:30:50 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static long	ft_atol(const char *str)
{
	int		i;
	long	pow;
	int		s;

	i = 0;
	s = 1;
	pow = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		pow = (pow * 10) + (str[i] - 48);
		i++;
	}
	return (pow * s);
}

t_box	*init_metadata(int value)
{
	t_box	*new_box;

	new_box = (t_box *) malloc (sizeof(t_box));
	if (!new_box)
		return (NULL);
	new_box->value = value;
	new_box->index = 0;
	new_box->push_cost = 0;
	new_box->rank = 0;
	new_box->cheapest = false;
	new_box->above_median = false;
	new_box->target = NULL;
	new_box->next = NULL;
	new_box->prev = NULL;
	return (new_box);
}

t_box	*find_last_box(t_box **pile_a)
{
	t_box	*current;

	current = *pile_a;
	while (current->next)
		current = current->next;
	return (current);
}

void	pile_box(t_box **pile_a, int value)
{
	t_box	*new_box;
	t_box	*last_box;

	new_box = init_metadata(value);
	if (!new_box)
		return ;
	if (!*pile_a)
		*pile_a = new_box;
	else
	{
		last_box = find_last_box(pile_a);
		last_box->next = new_box;
		new_box->prev = last_box;
	}
}

char	**build_pile_a(t_box **pile_a, char **av, bool argc_2)
{
	t_vars	vars;

	vars.i = 0;
	while (av[vars.i])
	{
		if (pocket_parser(av[vars.i]))
		{
			vars.tmp = av;
			av = append_pocket(av, av[vars.i], vars.i);
			if (!av || av[0] == NULL)
				free_failure(pile_a, av, true);
			if (argc_2)
				free_argv(vars.tmp, true);
			argc_2 = true;
		}
		if (syntax_parser(av[vars.i]))
			free_failure(pile_a, av, argc_2);
		vars.value = ft_atol(av[vars.i++]);
		if (!(vars.value >= INT_MIN && vars.value <= INT_MAX))
			free_failure(pile_a, av, argc_2);
		if (duplicate_parser(pile_a, (int)vars.value))
			free_failure(pile_a, av, argc_2);
		pile_box(pile_a, (int)vars.value);
	}
	return (av);
}
