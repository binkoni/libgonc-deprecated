#ifndef _GONC_NODE_H
#define _GONC_NODE_H

/**
* @file gonc_node.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_node.
*/

/**
* @brief A doubly linked node.
* A doubly linked node which has previous and next pointer.
* This struct is used by gonc_stack and gonc_linked_list.
*/

struct gonc_node
{
    void* data; /**< pointer of data. */
    struct gonc_node* previous; /**< pointer of previous node. */
    struct gonc_node* next; /**< pointer of next node. */
};

#endif
