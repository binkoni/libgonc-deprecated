#ifdef _GONC_LINKED_LIST_H
#define _GONC_LINKED_LIST_H

#include <stdlib.h>
#include "gonc_node.h"

struct gonc_linked_list
{
    struct gonc_node* node;
    size_t size;
}

static inline struct gonc_linked_list* gonc_linked_list_create()
{
    return calloc(1, sizeof(struct gonc_linked_list));
}

static inline size_t gonc_linked_list_get_size(struct gonc_linked_list linked_list)
{
    return linked_list->size;
}

int gonc_linked_list_set(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size);

int gonc_linked_list_insert(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size);

static inline int gonc_linked_list_prepend(struct gonc_linked_list* linked_list, void* data, size_t data_size)
{
    return gonc_linked_list_insert(linked_list, 0, data, data_size);
}

static inline int gonc_linked_list_append(struct gonc_linked_list* linked_list, void* data, size_t data_size)
{
    return gonc_linked_list_insert(linked_list, linked_list->size, data, size_t data_size);
}

int gonc_linked_list_get(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size);

int gonc_linked_list_remove(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size);

int gonc_linked_list_destroy(struct gonc_linked_list* linked_list);

#endif
