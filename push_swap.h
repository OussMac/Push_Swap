#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


// external libraries

# include <unistd.h> // for writing instructions.
# include <stdbool.h> // for true or false flags.
# include <stdlib.h> // for heap usage, mem allocation.
# include <unistd.h> // for write, writing commands.


// doubly linked list data structure, type definition.

typedef struct s_box
{
    int value; // box value
    
    int index; // box metadata
    int push_cost;
    bool cheapest;
    bool above_median;
    struct s_box *target;

    struct s_box *next; // links
    struct s_box *prev;
} t_box;





// libraries for testing.
# include <stdio.h>

#endif // PUSH_SWAP_H