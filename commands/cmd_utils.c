#include "../push_swap.h"

int     pile_size(t_box *pile)
{
    int i;

    i = 0;
    while (pile)
    {
        pile = pile->next;
        i++;
    }
    return (i);
}

void	append_box(t_box **pile, t_box *new_box)
{
	if (!*pile || !new_box)
	{
		*pile = new_box;
        (*pile)->next = NULL;
        (*pile)->prev = NULL;
		return ;
	}
    new_box->next = *pile;
    (*pile)->prev = new_box;
    *pile = new_box;
}