
# include "push_swap.h"

int	main(int ac, char *av[])
{
	t_box	*pile_a;
	t_box	*pile_b;

	pile_a = NULL;
	pile_b = NULL;

	if (pile_a || pile_b)
		return (0);

	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
		av = ft_split( av[1], ' ');

	// initialize stack a
		//also process input for errors within.
	// if (not sorted)
	/*
		implement algorithm
		// if 		pile_height --> two boxes
		// else if 	pile_height --> three boxes 
		// else		big_pile 	--> sort pile
	*/

	// free stack in the end

	ft_putstr_fd("All looks good!\n", 1);
	return (0);
}
