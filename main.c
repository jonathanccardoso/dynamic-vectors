#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array_int.h"
#include "list_int.h"

// Removes library entry and exit handling
void print_array_vector(array *a)
{
    int i;
    unsigned int size = array_size(a);
    unsigned int capacity = array_capacity(a);
    // int *data_array = array_data(a);

    printf(" (%u %u) {", size, capacity);
    for (i = 0; i < size; ++i)
    {
        // two forms
        // printf("%d ", data_array[i]);
        printf("%d ", array_get(a, i));
    }
    printf("}\n");
}

int main()
{
    clock_t beginning, end;
    array *a1 = array_create();
    print_array_vector(a1);

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

    print_array_vector(a1);
    printf("Encontrar index do elemento 432: %d\n", array_find(a1, 432));
    printf("Percentual de ocupacao: %2.f\n", array_percent_occuped(a1));
    printf("Remover ultimo elemento do array: %d\n", array_pop_back(a1));
    printf("Adiciona numero 24 ao final do array: %d\n", array_push_back(a1, 24));
    printf("Remova o elemento do index 1: %d\n", array_remove_from(a1, 1));
    print_array_vector(a1);
    printf("Adicionando o elemento 10 no index 1: %d\n", array_insert_at(a1, 1, 10));
    print_array_vector(a1);

    array_destroy(a1);

    double time = (end - beginning) / (CLOCKS_PER_SEC / 1000.0);
    printf("Tempo decorrido: %lfms\n", time);
    return 0;
}
