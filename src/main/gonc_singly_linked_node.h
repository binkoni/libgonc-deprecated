#ifndef _GONC_SINGLY_LINKED_NODE_H
#define _GONC_SINGLY_LINKED_NODE_H

/**
* @file gonc_singly_linked_node.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_singly_linked_node.
*/

/**
* @brief A singly linked node.
* A singly linked node which has only next pointer.
* This struct is used by gonc_queue.
*/

struct gonc_singly_linked_node
{
    void* data; /**< pointer of data. */
    struct gonc_singly_linked_node* next; /**< pointer of next node. */
};

#endif
