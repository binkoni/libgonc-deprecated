#include <stdio.h>
#include "gonc_stack.h"

int main()
{
    struct gonc_stack* stack = gonc_stack_create();
    gonc_stack_push(stack, (void*)280);
    gonc_stack_push(stack, (void*)190);
    int* output;
    gonc_stack_pop(stack, (void**)&output);
    printf("%d\n", output);
    gonc_stack_pop(stack, (void**)&output);
    printf("%d\n", output);
    gonc_stack_destroy(stack);
}
