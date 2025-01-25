
# include "push_swap.h"

int	main(int ac, char *av[])
{
	t_box	*pile_a;
	t_box	*pile_b;

	pile_a = NULL; 
	pile_b = NULL;

	// just using these in a statement for now, to silence the warning.
	if (pile_a || pile_b)
		return (0);

	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		no_args_error();
	else if (ac == 2)
		av = ft_split( av[1], ' '); // artificial allocated arg vector in heap, dont forget
	else
		av = av + 1;   				// just move the ptr of og argv to not include program name.

	// initialize stack a
	init_pile_a(&pile_a, av);
		//also process input for errors within.
	
	// if (not sorted)
	/*
		implement algorithm
		// if 		pile_height --> two boxes
		// else if 	pile_height --> three boxes 
		// else		big_pile 	--> sort pile
	*/

	print_argv(av); // for testing

	// free fake argument vector once done, if ac was 2
	free_argv(av, ac == 2);
	// free stack in the end

	ft_putstr_fd("All looks good!\n", 1);
	return (EXIT_SUCCESS);
}
