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

// init_metadata function (default values just so they are initialized)

t_box	*init_metadata(int value)
{
	t_box *new_box;
	new_box = (t_box *) malloc (sizeof(t_box));
	if (!new_box)
		return (NULL);
	new_box->value = value;
	new_box->index = 0;
	new_box->push_cost = 0;
	new_box->cheapest = false;
	new_box->above_median = false;
	new_box->target = NULL;
	new_box->next = NULL;
	new_box->prev = NULL;
	return (new_box);
}

// last_box function
t_box	*find_last_box(t_box **pile_a)
{
	t_box	*current;

	current = *pile_a;
	while (current->next)
		current = current->next;
	return (current);
}

// pile_box function
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

void	build_pile_a(t_box **pile_a, char **av, bool argc_2)
{
	int	i;
	long value;

	i = 0;
	while (av[i])
	{
		if(syntax_parser(av[i]))
			free_failure(pile_a, av, argc_2);
		value = ft_atol(av[i]);
		if (!(value >= INT_MIN && value <= INT_MAX))
			free_failure(pile_a, av, argc_2);
		if (duplicate_parser(pile_a, (int)value))
			free_failure(pile_a, av, argc_2);
		pile_box(pile_a, (int)value);
		i++;
	}
}
