#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array_int.h"
#include "list_int.h"

// Removes library entry and exit handling
// void print_vector(array *a)
// {
//     int i;

//     printf(" (%u %u) {", a->size, a->capacity);
//     for (i = 0; i < a->size; ++i)
//     {
//         printf("%d", a->data[i]);
//     }
//     printf("}\n");
// }

void print_vector(array *a)
{
    int i;
    unsigned int size = get_size(a);
    unsigned int capacity = get_capacity(a);
    int *data = get_data(a);

    printf(" (%u %u) {", size, capacity);
    for (i = 0; i < size; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("}\n");
}

int main()
{
    clock_t beginning, end;
    array *a1 = array_create();
    print_vector(a1);

    if (a1 == 0)
        return 0;

    int i, error;
    beginning = clock();
    for (i = 0; i < 200; ++i)
    {
        append_array(a1, i * 3, &error);
        if (error)
        {
            printf("Erro de memória!\n");
            break;
        }
    }
    end = clock();

    print_vector(a1);
    // destroy_int(a1);

    double time = (end - beginning) / (CLOCKS_PER_SEC / 1000.0);
    printf("Tempo decorrido: %lfms\n", time);
    return 0;
}