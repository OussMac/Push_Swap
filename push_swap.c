/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:47:23 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 06:47:25 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	input_check(ac, &av);
	check = pocket_checker(av);
	av = build_pile_a(&pile_a, av, ac == 2);
	if (!sorted_pile(pile_a))
	{
		if (pile_size(pile_a) == 2)
			two_boxes(&pile_a);
		else if (pile_size(pile_a) == 3)
			three_boxes(&pile_a);
		else if (pile_size(pile_a) == 4 || pile_size(pile_a) == 5)
			five_boxes(&pile_a, &pile_b);
		else
			big_pile(&pile_a, &pile_b);
	}
	if (ac == 2)
		free_argv(av, ac == 2);
	else if (ac > 2 && check)
		free_argv(av, true);
	return (free_pile(&pile_a), EXIT_SUCCESS);
}
