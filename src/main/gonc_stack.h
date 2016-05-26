#ifndef _GONC_STACK_H
#define _GONC_STACK_H

#include <stdlib.h>
#include <string.h>
#include "gonc_node.h"

struct gonc_stack {
    struct gonc_node* top;
    size_t size;
};

static inline struct gonc_stack* gonc_stack_create()
{
    return calloc(1, sizeof(struct gonc_stack));
}

static inline size_t gonc_stack_get_size(struct gonc_stack* stack)
{
    return stack->size;
}

int gonc_stack_push(struct gonc_stack* stack, void* data, size_t data_size);

static inline void gonc_stack_peek(struct gonc_stack* stack, void* data, size_t data_size)
{
    memcpy(data, stack->top->data, data_size);
}

int gonc_stack_pop(struct gonc_stack* stack, void* data, size_t data_size);

int gonc_stack_destroy(struct gonc_stack* stack);

#endif
