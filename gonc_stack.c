#include <stdlib.h>
#include "gonc_stack.h"

int gonc_stack_push(struct gonc_stack* stack, void* data)
{
    if(stack->size > 0)
    {
        stack->top->next = malloc(sizeof(struct gonc_node));
        stack->top->next->previous = stack->top;
        stack->top->next->data = data;
        stack->top = stack->top->next;
        ++(stack->size);
    }
    else if(stack->size == 0)
    {
        stack->top = malloc(sizeof(struct gonc_node));
        stack->top->data = data;
        ++(stack->size);
    }
    else
    {
        return -1;
    }
    return 0;
}

int gonc_stack_pop(struct gonc_stack* stack, void** output_data)
{
    if(stack->size <= 0)
    {
        return -1;
    }
    if(output_data == NULL) return 0;
    void* data = stack->top->data;
    struct gonc_node* old_top = stack->top;
    free(old_top);
    stack->top = stack->top->previous;
    --(stack->size);
    *output_data = data;
    return 0;
}

int gonc_stack_destroy(struct gonc_stack* stack)
{
    while(stack->size > 0)
        gonc_stack_pop(stack, (void**)NULL);
    free(stack);
    return 0;
}
