#ifndef _GONC_QUEUE_H
#define _GONC_QUEUE_H

#include <stdlib.h>
#include <string.h>
#include "gonc_singly_linked_node.h"

/**
* @file gonc_queue.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_queue and related functions.
*/

/**
* @brief A linked list based queue.
* Because this queue is linked list based, you don't have to worry about the capacity.
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

int gonc_queue_push(struct gonc_queue* queue, void* data, size_t data_size);

/**
* @brief Copies first data of the queue to parameter 'data'.
*
* @param queue Pointer of the queue.
* @param data Pointer of the output data.
* @param data_size Size of the data.
*/

static inline void gonc_queue_peek(struct gonc_queue* queue, void* data, size_t data_size)
{
    memcpy(data, queue->front->data, data_size);
}

/**
* @brief Pops first data of the queue to parameter 'data'
*
* @param queue Pointer of the queue.
* @param data Pointer of the output data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_queue_pop(struct gonc_queue* queue, void* data, size_t data_size);

/**
* @brief Destroys the queue.
* This function destroys the queue and frees the memory.
* @param queue Pointer of the queue
* @return 0 if no error, -1 if error.
*/
int gonc_queue_destroy(struct gonc_queue* queue);

#endif
