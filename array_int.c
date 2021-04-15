#include <stdlib.h>
#include <stdio.h>

#include "array_int.h"

array *create_int()
{
    array *a = (array *)malloc(sizeof(array));

    if (a == 0)
        return 0;
    a->data = (int *)malloc(sizeof(int) * 100);
    a->size = 0;
    a->capacity = 100;

    return a;
};

// a -> capacity, is to receive content from the pointer of a struct.
void append_int(array *a, int x, int *error)
{
    *error = 1;

    // increase *capacity
    if (a->size == a->capacity)
    {
        a->capacity = a->capacity + 10;
        int *new = (int *)malloc(sizeof(int) * (a->capacity));

        int *old = a->data; // points to old space

        int i;
        for (i = 0; i < a->size; ++i)
        {
            *(new + i) /* new[i] */ = *(old + i);
        }
        a->data = new;

        free(old); // free up old memory
    }

    a->data[a->size] = x;
    *error = 0;
}

// ------ need to validate this assignment ------
int array_insert_at(array *a, int index, int value)
{
    if (a->size != a->capacity)
    {
        int i;
        for (i = (a->size)++; i > index; --i)
        {
            // a[i] = a[i - 1];
            a->data[i] = value;
        }
    }
    return a->size;
}

// ------ need to validate this assignment ------
int array_remove_from(array *a, int index)
{
    int i;
    for (i = index; i < a->size; ++i)
    {
        a->data[i] = a->data[i + 1];
    }

    return --(a->size);
}

int array_find(array *a, int element)
{
    while ((a->size)--)
    {
        if (a->data == element)
            return 1;
    }
}

void array_destroy(array *a)
{
    free(a->data);
    free(a);
}
