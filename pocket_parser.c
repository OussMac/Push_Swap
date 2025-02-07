#include "push_swap.h"

static  bool is_space(char c)
{
    if(c == ' ')
        return (true);
    return (false);
}

static int  vector_len(char **av)
{
    int i;

    i = 0;
    while(av[i])
        i++;
    return (i);
}

bool    pocket_parser(char *av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if (is_space(av[i]))
            return (true);
        i++;
    }
    return(false);
}

char    **append_pocket(char **old_av,char *av_p, int stop)
{
    char    **av_pocket;
    char    **new_av;
    int     i;
    int     j;
    int     pocket_len;
    
    av_pocket = ft_split(av_p, ' ');
    pocket_len = vector_len(av_pocket);
    new_av = (char **) malloc (sizeof(char *) * (vector_len(old_av) + pocket_len + 1));
    if (!new_av)
        return (NULL);
    i = 0;
    j = 0;
    while (i < stop)
    {
        new_av[i] = old_av[i];
        i++;
    }
    j = 0;
    while (j < pocket_len)
    {
        new_av[i] = av_pocket[j];
        i++;
        j++;
    }
    pocket_len = vector_len(old_av) + vector_len(av_pocket);  // reusing this variable
    while (i < pocket_len)
    {
        new_av[i] = old_av[++stop];
        i++;
    }
    new_av[i] = NULL;
    print_argv(new_av);
    free_argv(av_pocket, true);
    return (new_av);
}
