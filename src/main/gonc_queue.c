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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <string.h>
#include "gonc_queue.h"
#include "gonc_singly_linked_node.h"

int gonc_queue_push(struct gonc_queue* queue, void* data, size_t data_size)
{
    if(queue->size > 0)
    {
        queue->back->next = malloc(sizeof(struct gonc_queue));
        queue->back = queue->back->next;
    }
    else if(queue->size == 0)
        queue->back = queue->front = calloc(1, sizeof(struct gonc_singly_linked_node));
    else return -1;

    queue->back->data = malloc(data_size);
    memcpy(queue->back->data, data, data_size);
    ++(queue->size);

    return 0;
}

int gonc_queue_pop(struct gonc_queue* queue, void* data, size_t data_size)
{
    if(queue->size <= 0) return -1;

    memcpy(data, queue->front->data, data_size);
    struct gonc_singly_linked_node* old_front = queue->front;
    queue->front = queue->front->next;
    free(old_front->data);
    free(old_front);
    --(queue->size);

    return 0;
}

int gonc_queue_destroy(struct gonc_queue* queue)
{
    struct gonc_singly_linked_node* old_front;
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
