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
    int     new_len;
    
    av_pocket = ft_split(av_p, ' ');
    if (av_pocket[0] == NULL)
        return(av_pocket);
    new_av = (char **) malloc (sizeof(char *) * (vector_len(old_av) + vector_len(av_pocket) + 1));
    if (!new_av)
        return (NULL);
    i = 0;
    while (i < stop)
    {
        new_av[i] = ft_strdup(old_av[i]);
        i++;
    }
    j = 0;
    while (av_pocket[j])
        new_av[i++] = av_pocket[j++];
    new_len = vector_len(old_av) + vector_len(av_pocket);
    while (old_av[++stop])
        new_av[i++] = ft_strdup(old_av[stop]);
    new_av[i] = NULL;
    free(av_pocket);
    return (new_av);
}
