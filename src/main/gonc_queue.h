#ifndef _GONC_QUEUE_H
#define _GONC_QUEUE_H

#include <stdlib.h>
#include <string.h>
#include "gonc_singly_linked_node.h"

struct gonc_queue
{
    struct gonc_singly_linked_node* front;
    struct gonc_singly_linked_node* back;
    size_t size;
};

static inline void* gonc_queue_create()
{
    return calloc(1, sizeof(struct gonc_queue));
}

static inline size_t gonc_queue_get_size(struct gonc_queue* queue)
{
    return queue->size;
}

int gonc_queue_push(struct gonc_queue* queue, void* data, size_t data_size);

static inline void gonc_queue_peek(struct gonc_queue* queue, void* data, size_t data_size)
{
    memcpy(data, queue->front->data, data_size);
}

int gonc_queue_pop(struct gonc_queue* queue, void* data, size_t data_size);


int gonc_queue_destroy(struct gonc_queue* queue);

#endif
