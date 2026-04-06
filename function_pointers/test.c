#include <stdio.h>
#include "function_pointers.h"

void print_elem(int elem)
{
    printf("%d\n", elem);
}

int main(void)
{
    int array[5] = {0, 98, 402, 1024, 4096};

    array_iterator(array, 5, print_elem);

    return (0);
}
