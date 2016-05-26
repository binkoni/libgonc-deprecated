#include <stdio.h>
#include "../main/gonc_stack.h"

int main()
{
    struct gonc_stack* stack = gonc_stack_create();
    int p = 280;
    gonc_stack_push(stack, (void*)&p, sizeof(int));
    p = 190;
    gonc_stack_push(stack, (void*)&p, sizeof(int));

    int output;
    gonc_stack_pop(stack, (void*)&output, sizeof(int));
    printf("%d %d\n", output, gonc_stack_get_size(stack));
    gonc_stack_peek(stack, (void*)&output, sizeof(int));
    printf("%d %d\n", output, gonc_stack_get_size(stack));
    gonc_stack_pop(stack, (void*)&output, sizeof(int));
    printf("%d %d\n", output, gonc_stack_get_size(stack));
    printf("%d\n", gonc_stack_pop(stack, (void*)&output, sizeof(int)));

 
    gonc_stack_destroy(stack);

}
