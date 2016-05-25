#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, char** argv)
{
    struct gonc_node* node1 = calloc(1, sizeof(struct gonc_node));
    node1->data = calloc(1, sizeof(int));
    *(int*)(node1->data) = 100;

    node1->next = calloc(1, sizeof(struct gonc_node));

    node1->next->data = calloc(1, sizeof(int));
    *(int*)(node1->next->data) = 200;

    printf("%d\n", *(int*)(node1->data));
    printf("%d\n", *(int*)(node1->next->data));
}
