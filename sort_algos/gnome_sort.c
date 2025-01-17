#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void gnome_sort(int *tab, size_t size, int *swap, int *reset)
{
    size_t i = 0;

    while (i < size - 1)
    {
        if (tab[i] > tab[i + 1])
        {
           ft_swap(&tab[i], &tab[i + 1]);
           (*swap)++;
           i = 0;
           (*reset)++;
        }
        else
            i++;
    }
}

int main (void)
{
    int tab[11] = {5, 3, -1, -5, 0, 4, 2, 1, -4, -2, -3};

    size_t size = (sizeof(tab) / sizeof(int));
    int swap = 0;
    int reset = 0;

    printf("size of array ===> %zu\n", size);
    gnome_sort(tab, size, &swap, &reset);

    for (size_t i = 0; i < size; i++)
    {
        printf("[%zu] ===> %d\n", i , tab[i]);
    }

    printf(" -> %d Resets in Total \n", reset);
    printf(" -> %d Swaps in Total \n", swap);

    return (0);
}