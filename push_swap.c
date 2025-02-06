
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
		print_error();
	else if (ac == 2)
		av = ft_split( av[1], ' '); // artificial allocated arg vector in heap, dont forget
	else
		av = av + 1;   				// just move the ptr of og argv to not include program name.
	build_pile_a(&pile_a, av, ac == 2); // initialize stack a
		//also process input for errors within.
	if (!sorted_pile(pile_a))
	{
		// implement algorithm \\

		// if 		pile_height --> two boxes
		// else if 	pile_height --> three boxes 
		// else if	pile-height --> fibe boxes
		// else		big_pile 	--> sort pile

	}


	//print_argv(av); // for testing
	stack_printer(pile_a); // printing stack in visual form
	free_argv(av, ac == 2); // free fake argument vector once done, if ac was 2
	free_pile(&pile_a); // free stack in the end

	exit (EXIT_SUCCESS);
}
