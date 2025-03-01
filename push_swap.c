
# include "push_swap.h"

int	main(int ac, char *av[])
{
	t_box	*pile_a;
	t_box	*pile_b;

	pile_a = NULL; 
	pile_b = NULL;

	(void)pile_b;

	if (ac == 1)
		exit (EXIT_FAILURE);
	else if (ac == 2)
		av = ft_split( av[1], ' '); // artificial allocated arg vector in heap, dont forget
	else
		av = av + 1;  				// just move the ptr of og argv to not include program name.
	if (ac == 2 && av[0] == NULL)
	{
		free_argv(av, ac == 2);
		print_error();
	}
	bool check = pocket_checker(av);
	av = build_pile_a(&pile_a, av, ac == 2); // initialize stack a
		//also process input for errors within.


	if (!sorted_pile(pile_a))
	{
		// implement algorithm 

		// if 		pile_height --> two boxes
		// else if 	pile_height --> three boxes 
		// else if	pile-height --> five boxes
		// else		big_pile 	--> sort pile

	}


	// build_pile_a(&pile_b, av, ac == 2);

	print_argv(av); // for testing
	// stack_printer(pile_a, pile_b); // printing stack in visual form

	// stack_printer(pile_a, pile_b);
	pb(&pile_a, &pile_b);
	sa(&pile_a);
	// pb(&pile_a, &pile_b);
	pa(&pile_a, &pile_b);
	// pa(&pile_a, &pile_b);
	stack_printer(pile_a, pile_b);
	if (ac == 2)
		free_argv(av, ac == 2); // free fake argument vector once done, if ac was 2
	else if (ac > 2 && check) // dir hna chi check ila makaina ta pocket fnumbers bach matdobble freeich
		free_argv(av, true);
	free_pile(&pile_a); // free stack in the end

	exit (EXIT_SUCCESS);
}
