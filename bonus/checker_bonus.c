/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:47:23 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 13:11:11 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// for testing.
#include <stdio.h>
void    print_pile(t_box *pile)
{
    int i;

    i = 0;
    while (pile)
    {
        printf("%d\t", pile->value);
        i++;
        if (i == 20)
        {
            puts("");
            i = 0;
        }
        pile = pile->next;
    }
    puts("");
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (i < n && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

int	validate_cmd(char *cmd, t_box **pile_a, t_box **pile_b)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		sa(pile_a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(pile_b);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(pile_a, pile_b);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		pa(pile_a, pile_b);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb(pile_a, pile_b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(pile_a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(pile_b);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(pile_a, pile_b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(pile_a, pile_b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(pile_a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(pile_b);
	else
		return (1);
	return (0);
}

void	process_commands(t_box **pile_a, t_box **pile_b, bool argc_2, char **av)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		if (validate_cmd(cmd, pile_a, pile_b) == 1)
		{
			free(cmd);
			free_failure(pile_a, av, argc_2);
		}
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	free(cmd);
}

void	input_check(int ac, char ***av)
{
	if (ac == 1)
		exit (EXIT_FAILURE);
	else if (ac == 2)
		*av = ft_split((*av)[1], ' ');
	else
		*av = (*av) + 1;
	if (ac == 2 && (*av)[0] == NULL)
	{
		free_argv(*av, ac == 2);
		print_error();
	}
}

int	main(int ac, char *av[])
{
	t_box	*pile_a;
	t_box	*pile_b;
	bool	check;

	pile_a = NULL;
	pile_b = NULL;
	(void)pile_b;
	input_check(ac, &av);
	check = pocket_checker(av);
	av = build_pile_a(&pile_a, av, ac == 2);
	process_commands(&pile_a, &pile_b, ac == 2, av);
	if (sorted_pile(pile_a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	if (ac == 2)
		free_argv(av, ac == 2);
	else if (ac > 2 && check)
		free_argv(av, true);
	return (free_pile(&pile_a), EXIT_SUCCESS);
}


