#include <stdlib.h>
#include <stdio.h>

#include "array_int.h"

struct array_int
{
    int *data;
    unsigned int size, capacity;
};

array *array_create()
{
    array *a = (array *)malloc(sizeof(array));

    if (a == 0)
        return 0;

    a->data = (int *)malloc(sizeof(int) * 100);
    a->size = 0;
    a->capacity = 100;

    return a;
};

int array_get(array *a, int index)
{
    return a->data[index];
}

int array_find(array *a, int element)
{
    int i;
    unsigned int size = a->size;

    for (i = 0; i < size; ++i)
    {
        if (a->data[i] == element)
        {
            return i;
            break;
        }
    }

    return 0;
}

// a -> capacity, is to receive content from the pointer of a struct.
void append_array(array *a, int x, int *error)
{
    *error = 1;

    // increase *capacity
    if (a->size == a->capacity)
    {
        a->capacity = a->capacity + 100;
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

    // a->size++ atribute new size
    a->data[a->size++] = x;
    *error = 0;
}

int array_insert_at(array *a, int index, int value)
{
    if (index < a->size)
    {
        a->data[index] = value;
        return index;
    }
    else
        return -1;
}

int array_remove_from(array *a, int index)
{
    int i;
    for (i = index; i < a->size; ++i)
    {
        a->data[i] = a->data[i + 1];
    }

    return --(a->size);
}

void array_destroy(array *a)
{
    free(a->data);
    free(a);
}

unsigned int array_push_back(array *a, int i)
{
    if (a->size == a->capacity)
    {
        printf("size == capacity");
        a->capacity = a->capacity + 100;
        int *new = (int *)malloc(sizeof(int) * (a->capacity));
        int *old = a->data;

        int i;
        for (i = 0; i < a->size; ++i)
        {
            *(new + i) /* new[i] */ = *(old + i);
        }
        a->data = new;

        free(old);
    }
    printf("size != capacity %d %d\n", a->size, a->capacity);
    printf("i %d\n", i);

    a->data[(a->size)++] = i;
    return a->size;
}

unsigned int array_pop_back(array *a)
{
    // check if array is not empty, test extra!
    if (a->size <= 0)
    {
        return 0;
    }

    int i;
    for (i = a->size - 1; i < a->size; ++i)
    {
        a->data[i] = a->data[i + 1];
    }

    return --(a->size);
}

unsigned int array_size(array *a)
{
    return a->size;
}

unsigned int array_capacity(array *a)
{
    return a->capacity;
}

double array_percent_occuped(array *a)
{
    return a->size / a->capacity;
}

int *array_data(array *a)
{
    return a->data;
}
