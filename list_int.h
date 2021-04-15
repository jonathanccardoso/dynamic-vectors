/**
 * ANSI C dinamic list of int values library
 *
 * Author: Jonathan Cardoso F. de Moura
 * Date: xx/xx/xxxx
 *
 */

#ifndef _LIST_INT_H_
#define _LIST_INT_H_

/**
 * Type: list_int
 * Description: a list_int is a pointer to a type that
 *              stores the dynamic list data. 
 *
 */
struct list_int
{
    // ...
};

typedef struct list_int list;

/**
 * Function: list * list_init();
 *
 * Description: Creates and inititialize a dynamic list list of integers.
 *
 * Return: A pointer to list type, the dynamic list implementation
 *
 */
list *list_create();

/**
 * Function: int list_get(list * list, int index);
 *
 * Description: Gets the element at index 'index'.
 *
 * Return: The element located at index i.
 *         The value is undeterminated if index is not in the range [0..size-1]
 *
 */
int list_get(list *list, int index);

/**
 * Function: unsigned int list_push_back(list * list, int i);
 *
 * Description: Add integer value 'i' to the end of the 'list' dynamic list.
 *
 * Return: The number of elements stored in 'list' AFTER inserting 'i'.
 *
 */
unsigned int list_push_back(list *list, int i);

/**
 * Function: unsigned int list_pop_back(list * list);
 *
 * Description: Removes the last element of the dynamic list
 *              referenced (pointed) by 'list'.
 *
 * Return: The number of elements after deletion.
 *
 */
unsigned int list_pop_back(list *list);

/**
 * Function: unsigned int list_size(list * list);
 *
 * Description: Computes the number of int elements stored in 'list'.
 *
 * Return: The number of integer values stored in 'list'.
 *
 */
unsigned int list_size(list *list);

/**
 * Function: int list_find(list * list, int element);
 *
 * Description: Gets the index of  element 'element'.
 *
 * Return: The index of element 'element' if element is in the range [0..size-1].
 *
 */
int list_find(list *list, int element);

/**
 * Function: int list_insert_at(list * list, int index, int value);
 *
 * Description: Inserts int value 'value' at index 'index'. 'index' must
 *              be a valid index, between 0 and 'list_size'-1.
 *
 * Return: the value index, if insertion ok or -1 if the insertion could
 *         not be done.
 *
 */
int list_insert_at(list *list, int index, int value);

/**
 * Function: list_remove_from(list * list, int index);
 *
 * Description: Removes the value at index 'index'. 'index' must
 *              be a valid index, between 0 and 'list_size'-1.
 *
 * Return: The size of the new list.
 *
 */
int list_remove_from(list *list, int index);

/**
 * Function: unsigned int list_capacity(list * list);
 *
 * Description: Computes the list list capacity.
 *
 * Return: The capicity of the 'list' list.
 *
 */
unsigned int list_capacity(list *list);

/**
 * Function: unsigned int list_percent_occuped(list * list);
 *
 * Description: Check the list 'list' occupation, in percent.
 *
 * Return: A double, from 0 to 1 with the occupation rate of 'list'.
 *
 */
double list_percent_occuped(list *list);

/**
 * Function: void list_destroy(list * list);
 *
 * Description: Relese memory used by the 'list' reference.
 *              Invalidate memory area too.
 *
 */
void list_destroy(list *list);

#endif
