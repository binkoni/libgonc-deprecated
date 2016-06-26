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

#ifndef _GONC_QUEUE_H
#define _GONC_QUEUE_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <string.h>
#include "gonc_singly_linked_node.h"
#include "gonc_entry.h"

/**
* @file gonc_queue.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_queue and related functions.
*/

/**
* @brief A linked list based queue.
* Because this queue is linked list based, you don't have to worry about the capacity.
* This doesn't use struct gonc_linked_list.
*/

struct gonc_queue
{
    struct gonc_singly_linked_node* front; /**<  Pointer of first node. */
    struct gonc_singly_linked_node* back; /**<  Pointer of last node. */
    size_t size; /**< The number of nodes in the queue. */
};

/**
* @brief Creates new queue.
* This is an inline function to create new queue.
* This function dynamically allocates the stack then returns its pointer.
* You must call gonc_queue_destroy() after use to free allocated memory.
* @return Pointer of newly created queue or NULL if error.
*/

static inline void* gonc_queue_create()
{
    return calloc(1, sizeof(struct gonc_queue));
}

/**
* @brief Returns the number of nodes in the queue.
* This is an inline function to get the size of the queue.
* @param queue Pointer of the queue.
* @return Size of the queue.
*/

static inline size_t gonc_queue_get_size(struct gonc_queue* queue)
{
    return queue->size;
}

/**
* @brief Pushes data to the queue.
*
* @param queue Pointer of the queue.
* @param data Pointer of the data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_queue_push(struct gonc_queue* queue, struct gonc_entry* entry);

/**
* @brief Copies first data of the queue to parameter 'data'.
*
* @param queue Pointer of the queue.
* @param data Pointer of the output data.
* @param data_size Size of the data.
*/

static inline struct gonc_entry* gonc_queue_peek(struct gonc_queue* queue)
{
    return queue->front->entry;
}

/**
* @brief Pops first data of the queue to parameter 'data'
*
* @param queue Pointer of the queue.
* @param data Pointer of the output data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

struct gonc_entry* gonc_queue_pop(struct gonc_queue* queue);

/**
* @brief Destroys the queue.
* This function destroys the queue and frees the memory.
* @param queue Pointer of the queue
* @return 0 if no error, -1 if error.
*/

int gonc_queue_destroy(struct gonc_queue* queue);

#endif
