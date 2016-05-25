#include <stdlib.h>
#include <string.h>
#include "gonc_stack.h"

int gonc_stack_push(struct gonc_stack* stack, void* data, size_t data_size)
{
    if(stack->size > 0)
    {
        stack->top->next = malloc(sizeof(struct gonc_node));
        stack->top->next->previous = stack->top;

        stack->top->next->data = malloc(data_size);
        memcpy(stack->top->next->data, data, data_size);

        stack->top = stack->top->next;
        ++(stack->size);
    }
    else if(stack->size == 0)
    {
        stack->top = malloc(sizeof(struct gonc_node));
        stack->top->data = malloc(data_size);
        memcpy(stack->top->data, data, data_size);
        ++(stack->size);
    }
    else
    {
        return -1;
    }
    return 0;
}

int gonc_stack_peek(struct gonc_stack* stack, void* data, size_t data_size)
{
    memcpy(data, stack->top->data, data_size);
    return 0;
}


int gonc_stack_pop(struct gonc_stack* stack, void* data, size_t data_size)
{
    if(stack->size <= 0)
    {
        return -1;
    }

    if(data == NULL) return 0;
    memcpy(data, stack->top->data, data_size);
    struct gonc_node* old_top = stack->top;
    stack->top = stack->top->previous;
    free(old_top);
    --(stack->size);
    return 0;
}

int gonc_stack_destroy(struct gonc_stack* stack)
{
    struct gonc_node* old_top;
    while(stack->size > 0) 
    {
        old_top = stack->top;
        stack->top = stack->top->previous;
        free(old_top->data);
        free(old_top);
        --(stack->size);
    }
    free(stack);
    return 0;
}
