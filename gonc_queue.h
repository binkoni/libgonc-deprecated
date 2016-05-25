#include <stdlib.h>
#include "gonc_node.h"

#ifndef GONC_QUEUE_H
#define GONC_QUEUE_H

struct gonc_queue
{
    struct gonc_node* front;
    struct gonc_node* back;
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

int gonc_queue_push_back(struct gonc_queue* queue, void* data, size_t data_size);

int gonc_queue_peek_front(struct gonc_queue* queue, void* data, size_t data_size);

int gonc_queue_pop_front(struct gonc_queue* queue, void* data, size_t data_size);


int gonc_queue_destroy(struct gonc_queue* queue);

#endif
