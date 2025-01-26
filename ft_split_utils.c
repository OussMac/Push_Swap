# include "push_swap.h"

// needed by split --- a function that cuts a sub string from a full string.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return ((char *)sub);
}

// needed by substr --- a function that allocates a duplication for a string.

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// needed by strdup --- a function that calculates the lenght of a string

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// free artificial (fake) argument vector

void	free_argv(char **av, bool argc_2)
{
	int i;

	i = 0;
	if (!argc_2)
		return ;
	while(av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void    print_error(void) // void when used in a func parameter list. indicates it takes no parameters
{
    ft_putstr_fd("Error\n", 2);
    exit(EXIT_FAILURE);
}