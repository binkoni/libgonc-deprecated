#include <stdlib.h>
#include "gonc_node.h"

#ifndef GONC_STACK_H
#define GONC_STACK_H

struct gonc_stack {
    struct gonc_node* top;
    size_t size;
};

static inline struct gonc_stack* gonc_stack_create()
{
    return calloc(1, sizeof(struct gonc_stack));
}

static inline int gonc_stack_get_size(struct gonc_stack* stack)
{
    return stack->size;
}

int gonc_stack_push(struct gonc_stack* stack, void* data, size_t data_size);

int gonc_stack_peek(struct gonc_stack* stack, void* data, size_t data_size);

int gonc_stack_pop(struct gonc_stack* stack, void* data, size_t data_size);

int gonc_stack_destroy(struct gonc_stack* stack);

#endif
