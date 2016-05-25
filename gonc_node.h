#ifndef GONC_NODE_H
#define GONC_NODE_H
struct gonc_node
{
    void* data;
    struct gonc_node* previous;
    struct gonc_node* next;
};
#endif
