#ifndef _GONC_NODE_H
#define _GONC_NODE_H

/**
* @brief use brief, otherwise the index won't have a brief explanation
*
* detailed explanation
*/

struct gonc_node
{
    void* data; /**< some documentation for data */
    struct gonc_node* previous; /**< some documentation for previous */
    struct gonc_node* next; /**< some documentation for next */
};

#endif
