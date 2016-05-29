#ifndef _GONC_ARRAY_LIST_H
#define _GONC_ARRAY_LIST_H

#include <stdlib.h>
#include <string.h>

/**
* @file gonc_array_list.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_array_list and related functions.
*
*/

/**
* @brief A dynamic capacity array.
* Capacity will be doubled when you insert new data but the size and the capacity of the array_list are the same.
*/

struct gonc_array_list
{
    void** array; /**< Pointer of the array. */
    size_t capacity; /**< Size of allocated memory of the array */
    size_t size; /**< The number of nodes in the array */
};

/**
* @brief Creates new array_list.
* You must call gonc_array_list_destroy() after use.
* @param capacity Initial capacity of the array_list.
* @return Pointer of newly created array_list or NULL if error.
*/

struct gonc_array_list* gonc_array_list_create(size_t capacity);

/**
* @brief Returns the capacity of the array_list.
*
* @param array_list Pointer of the array_list.
* @return Capacity of the array_list.
*/

static inline size_t gonc_array_list_get_capacity(struct gonc_array_list* array_list)
{
    return array_list->capacity;
}

/**
* @brief Returns the number of elements in the array_list.
*
* @param array_list Pointer of the array_list.
* @return The numer of elements.
*/

static inline size_t gonc_array_list_get_size(struct gonc_array_list* array_list)
{
    return array_list->size;
}

/**
* @brief Sets the data to specified index.
*
* @param array_list Pointer of the array_list.
* @param index Index which the data is placed at.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_array_list_set(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size);

/**
* @brief Inserts the data to specified index. Elements after the index will be pushed back.
*
* @param array_list Pointer of the array_list.
* @param index Index which the data will be placed to.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_array_list_insert(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size);

/**
* @brief Inserts the data to last index + 1.
*
* @param array_list Pointer of the array_list.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

static inline int gonc_array_list_append(struct gonc_array_list* array_list, void* data, size_t data_size)
{
    return gonc_array_list_insert(array_list, array_list->size, data, data_size);
}

/**
* @brief Copies data at the specified index to parameter 'data'.
*
* @param array_list Pointer of the array_list.
* @param index Index which the data will be copied from.
* @param data Pointer of the output data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_array_list_get(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size);

/**
* @brief Removes the data to specified index and copies the data to parameter 'data'. Elements after the index will be pulled forth.
*
* @param array_list Pointer of the array_list.
* @param index Index which the data will be removed from.
* @param data Pointer of the data or give it NULL if you don't want.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_array_list_remove(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size);

/**
* @brief Reduces the capcity of the array_list.
* Reduces the capacity to fit the size of the array_list.
* @param array_list Pointer of the array_list.
* @return 0 if no error, -1 if error.
*/

int gonc_array_list_compact(struct gonc_array_list* array_list);

/**
* @brief Destroys the array_list and frees the memory.
* 
* @param Pointer of the array_list.
*/

static inline void gonc_array_list_destroy(struct gonc_array_list* array_list)
{
    while(gonc_array_list_remove(array_list, array_list->size - 1, NULL, 0) == 0)
        ;
    free(array_list->array);
    free(array_list);
}

#endif
