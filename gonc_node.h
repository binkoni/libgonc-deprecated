#ifndef _GONC_NODE_H
#define _GONC_NODE_H

struct gonc_node
{
    void* data;
    struct gonc_node* previous;
    struct gonc_node* next;
};

#endif
