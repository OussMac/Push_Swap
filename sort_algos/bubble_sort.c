#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *tab, size_t size, int *swap, int *reset)
{
    size_t i = 0;
    size_t j = 0;

    int flag = 0;
    while (i < size - 1)
    {
        j = 0;
        (*reset)++;
        flag = 0;
        while (j < size - i - 1)
        {
            if (tab[j] > tab[j + 1])
            {
                ft_swap(&tab[j], &tab[j + 1]);
                (*swap)++;
                flag = 1;
            }
            j++;
        }
        if (!flag)
            break;
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
    bubble_sort(tab, size, &swap, &reset);

    for (size_t i = 0; i < size; i++)
    {
        printf("[%zu] ===> %d\n", i , tab[i]);
    }

    printf(" -> %d Resets in Total \n", reset);
    printf(" -> %d Swaps in Total \n", swap);
    
    return (0);
}