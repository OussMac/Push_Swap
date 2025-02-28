#include "../push_swap.h"

// declarations for itoa in the bottom, and len i used up here.
static char	*ft_itoa(int n);
static	int	ft_len(int nbr);

static void draw_box(char *str, int len)
{
    int i = 0;
    int box_width = 25;

    //middle
    i = 0;
    printf("|");
    while ( i < (box_width - len - 2))
    {
        printf(" ");
        i++;
    }
    printf("%s|", str);
	free(str);
}

static void print_value(int value)
{
    char *str = ft_itoa(value);
    if (!str)
        return;
    draw_box(str, ft_len(value));
}

void	spaces(void)
{
	printf("\t\t\t\t\t");
}

void	num_spaces(int num)
{
	int i = 0;
	int len = 12;
	len -= ft_len(num);
	while(i < len)
	{
		printf(" ");
		i++;
	}
	printf("|");
}

#include <string.h>

void	add_spaces(char *str, bool flag, int is_add)
{
	int i = 0;

	int len;

	if (flag)
		len = 9;
	else
	{
		len = 14;
		len -= ft_strlen(str);
	}
	if (is_add)
	{
		len = 12;
		len -= ft_strlen(str);
	}
	while(i < len)
	{
		printf(" ");
		i++;
	}
	printf("|");
}

void	print_arrows(void)
{
	int total = 23;
	int i = 0;
	while (i < (total / 2))
	{
		printf(" ");
		i++;
	}
	printf("| |");
	i = 0;
	while (i < (total / 2))
	{
		printf(" ");
		i++;
	}
}

// first function we call.
void    stack_printer(t_box *pile_a, t_box *pile_b)
{
	char str[18];
    int i = 1;
    while (pile_a)
    {
        printf("+=======================+");
		if (pile_b)
		{
			spaces();
			printf("+=======================+");
		}
		printf("\n");

        printf("|Box Number %d", i);
		num_spaces(i);
		if (pile_b)
		{
			spaces();
			printf("|Box Number %d", i);
			num_spaces(i);
		}
		printf("\n");

        printf("|Address -> %p", pile_a);
		sprintf(str ,"%p", pile_a);
		add_spaces(str, pile_a == NULL, 1);
		if (pile_b)
		{
			spaces();
			printf("|Address -> %p", pile_b);
			sprintf(str ,"%p", pile_b);
			add_spaces(str, pile_b == NULL, 1);
		}
		printf("\n");

        printf("|------------------------");
		if (pile_b)
		{
			spaces();
        	printf("|------------------------");
		}
		printf("\n");

        print_value(pile_a->value);
		if (pile_b)
		{
			spaces();
			print_value(pile_b->value);
		}
		printf("\n");

        printf("|------------------------");
		if (pile_b)
		{
			spaces();
			printf("|------------------------");
		}
		printf("\n");

        printf("| prev -> %p", pile_a->prev);
		sprintf(str ,"%p", pile_a);
		add_spaces(str, pile_a->prev == NULL, 0);
		if (pile_b)
		{
			spaces();
			printf("| prev -> %p", pile_b->prev);
			sprintf(str ,"%p", pile_b);
			add_spaces(str, pile_b->prev == NULL, 0);
		}
		printf("\n");

        printf("| next -> %p", pile_a->next);
		sprintf(str ,"%p", pile_a);
		add_spaces(str, pile_a->next == NULL, 0);
		if (pile_b)
		{
			spaces();
			printf("| next -> %p", pile_b->next);
			sprintf(str ,"%p", pile_b);
			add_spaces(str, pile_b->next == NULL, 0);
		}
		printf("\n");

        printf("+=======================+");

		if (pile_b)
		{
			spaces();
			printf("+=======================+");
		}
		printf("\n");

		print_arrows();
		if (pile_b)
		{
			spaces();
			print_arrows();
		}
		printf("\n");

		print_arrows();
		if (pile_b)
		{
			spaces();
			print_arrows();
		}

        printf("\n");
        pile_a = pile_a->next;
		if(pile_b)
			pile_b = pile_b->next;
        i++;
    }

	printf("-------------------------");
	spaces();
	printf("-------------------------");
	printf("\n");

	printf("|        | NULL |       |");
	spaces();
	printf("|        | NULL |       |");
	printf("\n");

	printf("-------------------------");
	spaces();
	printf("-------------------------");
	printf("\n");
}

// numbers to string, gonna print everything as string.

static	int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*max_int(char *str)
{
	char	*tmp;
	int		i;

	tmp = "-2147483648";
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	return (str);
}

static char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_len(n);
	s = (char *) malloc ((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len--] = 0;
	if (n == 0)
		s[0] = '0';
	if (n == -2147483648)
		return (max_int(s));
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n != 0)
	{
		s[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}
