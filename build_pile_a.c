#include "push_swap.h"

static long ft_atol(const char *str)
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

// init_metadata function

// last_box function

// pile_box function

void    build_pile_a(t_box **pile_a, char **av)
{
    (void)pile_a;
    (void)av;
    ft_atol("1");

	// while argv[i]
		//if (syntax_parser)
			//free_failure
		// put num in temp variable using atol
		// check for overflow if (tmp > INT_MAX || tmp < INT_MIN)
			//free_failure
		//if (dublicate_parser)
			//parse pile and check if number already exits
			//if so free_failure
		//pile_box -> append number to list
	
}