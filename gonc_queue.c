#include <stdlib.h>
#include <string.h>
#include "gonc_queue.h"
#include "gonc_node.h"

int gonc_queue_push_back(struct gonc_queue* queue, void* data, size_t data_size)
{
    if(queue->size > 0)
    {
        queue->back->next = malloc(sizeof(struct gonc_queue));
        queue->back = queue->back->next;
    }
    else if(queue->size == 0)
    {
        queue->back = queue->front = calloc(1, sizeof(struct gonc_node));
    }
    else
    {
        return -1;
    }

    queue->back->data = malloc(data_size);
    memcpy(queue->back->data, data, data_size);
    ++(queue->size);

    return 0;
}

int gonc_queue_peek_front(struct gonc_queue* queue, void* data, size_t data_size)
{
    memcpy(data, queue->front->data, data_size);
    return 0;
}

int gonc_queue_pop_front(struct gonc_queue* queue, void* data, size_t data_size)
{
    if(queue->size <= 0)
    {
        return -1;
    }

    memcpy(data, queue->front->data, data_size);
    struct gonc_node* old_front = queue->front;
    queue->front = queue->front->next;
    free(old_front->data);
    free(old_front);
    --(queue->size);

    return 0;
}

int gonc_queue_destroy(struct gonc_queue* queue)
{
    struct gonc_node* old_front;
    while(queue->size > 0)
    {
        old_front = queue->front;
        queue->front = queue->front->next;
        free(old_front->data);
        free(old_front);
        --(queue->size);
    }
    free(queue);
    return 0;
}
