/*
* Copyright (C) 2016  Byeonggon Lee <gonny952@gmail.com>
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Library General Public
* License as published by the Free Software Foundation; either
* version 3 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Library General Public License for more details.
*
* You should have received a copy of the GNU Library General Public
* License along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GONC_LINKED_LIST_H
#define _GONC_LINKED_LIST_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include "gonc_node.h"
#include "gonc_entry.h"

/**
* @file gonc_linked_list.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_linked_list and related functions.
*/

/**
* @brief A linked list.
* 
*/

struct gonc_linked_list
{
    struct gonc_node* head; /**< Pointer of first node. */
    size_t size; /**< The number of nodes in the linked list. */
};

/**
* @brief Creates new linked list.
* This is an inline function to create new linked list.
* This function dynamically allocates the linked list then returns its pointer.
* You must call gonc_stack_destroy() after use to free allocated memory.
* @return Pointer of newly created linked list or NULL if error.
*/

static inline struct gonc_linked_list* gonc_linked_list_create()
{
    return calloc(1, sizeof(struct gonc_linked_list));
}

/**
* @brief Returns the number of nodes in the linked list.
* This is an inline function to get the size of the linked list.
* @param linked_list Pointer of the linked list.
* @return Size of the linked list.
*/

static inline size_t gonc_linked_list_get_size(struct gonc_linked_list* linked_list)
{
    return linked_list->size;
}

/**
* @brief Sets the data to specified index.
*
* @param linked_list Pointer of the linked_list.
* @param index Index which the data will be placed to.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_linked_list_set(struct gonc_linked_list* linked_list, size_t index, struct gonc_entry* entry);

/**
* @brief Inserts the data to specified index. Elements after the index will be pushed back.
*
* @param linked_list Pointer of the linked_list.
* @param index Index which the data will be placed to.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error. 
*/

int gonc_linked_list_insert(struct gonc_linked_list* linked_list, size_t index, struct gonc_entry* entry);

/**
* @brief Inserts the data to index 0.
*
* @param linked_list Pointer of the linked_list.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

static inline int gonc_linked_list_prepend(struct gonc_linked_list* linked_list, struct gonc_entry* entry)
{
    return gonc_linked_list_insert(linked_list, 0, entry);
}

/**
* @brief Inserts the data to last index + 1.
*
* @param linked_list Pointer of the linked_list.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

static inline int gonc_linked_list_append(struct gonc_linked_list* linked_list, struct gonc_entry* entry)
{
    return gonc_linked_list_insert(linked_list, linked_list->size, entry);
}

/**
* @brief Copies data at the specified index to parameter 'data'.
*
* @param linked_list Pointer of the array_list.
* @param index Index which the data will be copied from.
* @param data Pointer of the output data.
* @param data_size Size of the output data.
* @return 0 if no error, -1 if error.
*/

struct gonc_entry* gonc_linked_list_get(struct gonc_linked_list* linked_list, size_t index);

/**
* @brief Removes the data to specified index and copies the data to parmeter 'data'. Elements after the index will be pulled forth.
*
* @param linked_list Pointer of the linked_list.
* @param index Index which the data will be removed from.
* @param data Pointer of the data or give it NULL if you don't want.
* @param data_size Size of the output data.
* @return 0 if no error, -1 if error.
*/

struct gonc_entry* gonc_linked_list_remove(struct gonc_linked_list* linked_list, size_t index);


/**
* @brief Removes the data to specified index and copies the data to parmeter 'data'. Elements after the index will be pulled forth.
*
* @param linked_list Pointer of the linked_list.
* @param index Index which the data will be removed from.
* @param data Pointer of the data or give it NULL if you don't want.
* @param data_size Size of the output data.
* @return 0 if no error, -1 if error.
*/

static inline void gonc_linked_list_delete(struct gonc_linked_list* linked_list, size_t index);
{
    gonc_entry_destroy(gonc_linked_list_remove(linked_list, index));
}

/**
* @brief Destroys the linked_list and frees the memory.
* 
* @param Pointer of the linked_list.
*/

static inline void gonc_linked_list_destroy(struct gonc_linked_list* linked_list)
{
    while(linked_list->size > 0)
        gonc_linked_list_destroy(linked_list, 0);
    free(linked_list);
}

#endif
