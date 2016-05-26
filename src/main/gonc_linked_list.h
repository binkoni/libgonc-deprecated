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

int gonc_linked_list_set(struct gonc_linked_list* linked_list, size_t index, void* data);

int gonc_linked_list_insert(struct gonc_linked_list* linked_list, void* data);

int gonc_linked_list_prepend(struct gonc_linked_list* linked_list, void* data);
int gonc_linked_list_append(struct gonc_linked_list* linked_list, void* data);

int gonc_linked_list_get(struct gonc_linked_list* linked_list, size_t index, void* data);

int gonc_linked_list_remove(struct gonc_linked_list* linked_list, void* data);

int gonc_linked_list_destroy(struct gonc_linked_list* linked_list);

