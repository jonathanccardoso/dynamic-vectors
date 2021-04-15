/**
 * ANSI C dinamic array of int values library
 *
 * Author: Jonathan Cardoso F. de Moura
 * Date: xx/xx/xxxx
 *
 */

#ifndef _ARRAY_INT_H_
#define _ARRAY_INT_H_

/**
 * Type: array_int
 * Description: a array_int is a pointer to a type that
 *              stores the dynamic array data. 
 *
 */
struct array_int
{
    int *data;
    unsigned int size, capacity;
};

typedef struct array_int array;

/**
 * Function: array * array_init();
 *
 * Description: Creates and inititialize a dynamic array list of integers.
 *
 * Return: A pointer to array type, the dynamic array implementation
 *
 */
array *array_create();

/**
 * Function: int array_get(array * array, int index);
 *
 * Description: Gets the element at index 'index'.
 *
 * Return: The element located at index i.
 *         The value is undeterminated if index is not in the range [0..size-1]
 *
 */
int array_get(array *array, int index);

/**
 * Function: unsigned int array_push_back(array * array, int i);
 *
 * Description: Add integer value 'i' to the end of the 'array' dynamic array.
 *
 * Return: The number of elements stored in 'array' AFTER inserting 'i'.
 *
 */
unsigned int array_push_back(array *array, int i);

/**
 * Function: unsigned int array_pop_back(array * array);
 *
 * Description: Removes the last element of the dynamic array
 *              referenced (pointed) by 'array'.
 *
 * Return: The number of elements after deletion.
 *
 */
unsigned int array_pop_back(array *array);

/**
 * Function: unsigned int array_size(array * array);
 *
 * Description: Computes the number of int elements stored in 'array'.
 *
 * Return: The number of integer values stored in 'array'.
 *
 */
unsigned int array_size(array *array);

/**
 * Function: int array_find(array * array, int element);
 *
 * Description: Gets the index of  element 'element'.
 *
 * Return: The index of element 'element' if element is in the range [0..size-1].
 *
 */
int array_find(array *array, int element);

/**
 * Function: int array_insert_at(array * array, int index, int value);
 *
 * Description: Insert the internal value 'value' in the last index of the array,
 *              between 0 and 'array_size'-1.
 *
 * Return: the value index, if insertion ok or -1 if the insertion could
 *         not be done.
 *
 */
int array_insert_at(array *array, int index, int value);

/**
 * Function: array_remove_from(array * array, int index);
 *
 * Description: Removes the value at index 'index'. 'index' must
 *              be a valid index, between 0 and 'array_size'-1.
 *
 * Return: The size of the new array.
 *
 */
int array_remove_from(array *array, int index);

/**
 * Function: unsigned int array_capacity(array * array);
 *
 * Description: Computes the array array capacity.
 *
 * Return: The capicity of the 'array' array.
 *
 */
unsigned int array_capacity(array *array);

/**
 * Function: unsigned int array_percent_occuped(array * array);
 *
 * Description: Check the array 'array' occupation, in percent.
 *
 * Return: A double, from 0 to 1 with the occupation rate of 'array'.
 *
 */
double array_percent_occuped(array *array);

/**
 * Function extra: void append-array(array * array, int x, int *error);
 *
 * Description: Relese memory used by the 'array' reference.
 *              Invalidate memory area too.
 *
 */

void append_array(array *array, int x, int *error);

/**
 * Function: void array_destroy(array * array);
 *
 * Description: Relese memory used by the 'array' reference.
 *              Invalidate memory area too.
 *
 */

void array_destroy(array *array);

#endif
