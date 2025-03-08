/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pocket_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:49:44 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 11:30:36 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	return (false);
}

static int	vector_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

bool	pocket_parser(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (is_space(av[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	pocket_checker(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (pocket_parser(av[i]))
			return (true);
		i++;
	}
	return (false);
}

char	**append_pocket(char **old_av, char *av_p, int stop)
{
	t_vars	vars;

	vars.av_pocket = ft_split(av_p, ' ');
	if (vars.av_pocket[0] == NULL)
		return (vars.av_pocket);
	vars.new_len = vector_len(old_av) + vector_len(vars.av_pocket);
	vars.new_av = (char **) malloc (sizeof(char *) * (vars.new_len + 1));
	if (!vars.new_av)
		return (free_argv(vars.av_pocket, true), NULL);
	vars.i = 0;
	while (vars.i < stop)
	{
		vars.new_av[vars.i] = ft_strdup(old_av[vars.i]);
		vars.i++;
	}
	vars.j = 0;
	while (vars.av_pocket[vars.j])
		vars.new_av[vars.i++] = vars.av_pocket[vars.j++];
	while (old_av[++stop])
		vars.new_av[vars.i++] = ft_strdup(old_av[stop]);
	vars.new_av[vars.i] = NULL;
	free(vars.av_pocket);
	return (vars.new_av);
}
