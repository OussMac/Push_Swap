#include "../push_swap.h"

// declarations for itoa in the bottom, and len i used up here.
static char	*ft_itoa(int n);
static	int	ft_len(int nbr);

static void draw_box(char *str, int len)
{
    int i = 0;
    int box_width = 25;
    // upper line
    while (i < box_width)
    {
        printf("-");
        i++;
    }
    printf("\n");


    //middle
    i = 0;
    printf("|");
    while ( i < (box_width - len - 2))
    {
        printf(" ");
        i++;
    }
    printf("%s|\n", str);

    // lower line
    i = 0;
    while (i < box_width)
    {
        printf("-");
        i++;
    }
    printf("\n");
}

static void print_value(int value)
{
    char *str = ft_itoa(value);
    if (!str)
        return;
    draw_box(str, ft_len(value));
    free(str);
}


// first function we call.

void    stack_printer(t_box *pile)
{
    int i = 1;
	if (!pile)
		return ;
    while (pile)
    {
        printf("+=======================+\n");

        printf("|Box Number %d\n", i);
        printf("|Address -> %p\n", pile);
        printf("|------------------------\n");

        print_value(pile->value);

        printf("|------------------------\n");
		printf("|⬆ ");
        printf("prev -> %p\n", pile->prev);
		printf("|⬇ ");
        printf("next -> %p\n", pile->next);

        printf("+=======================+\n");
        printf("\n\n\n");
        pile = pile->next;
        i++;
    }
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
