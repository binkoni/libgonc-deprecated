#include <stdio.h>
#include "gonc_stack.h"

int main()
{
    struct gonc_stack* stack = gonc_stack_create();
    int p = 280;
    gonc_stack_push(stack, (void*)&p, sizeof(int));
    p = 190;
    gonc_stack_push(stack, (void*)&p, sizeof(int));

    int output;
    gonc_stack_pop(stack, (void*)&output, sizeof(int));
    printf("%d\n", output);
    gonc_stack_pop(stack, (void*)&output, sizeof(int));
    printf("%d\n", output);
    gonc_stack_destroy(stack);

}
