#ifndef _GONC_STACK_H
#define _GONC_STACK_H

#include <stdlib.h>
#include <string.h>
#include "gonc_node.h"

/**
* @file gonc_stack.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_stack and related functions.
*/

/**
* @brief A linked list based stack.
* Because this stack is linked list based, you don't have to worry about the capacity.
*/

struct gonc_stack {
    struct gonc_node* top; /**< Pointer of topmost node */
    size_t size; /**< The number of nodes in the stack. */
};

/**
* @brief Creates new stack.
* This is an inline function to create new stack.
* This function dynamically allocates the stack then returns its pointer.
* You must call gonc_stack_destroy() after use to free allocated memory.
* @return Pointer of newly created stack or NULL if error.
*/

static inline struct gonc_stack* gonc_stack_create()
{
    return calloc(1, sizeof(struct gonc_stack));
}

/**
* @brief Returns the number of nodes in the stack.
* This is an inline function to get the size of the stack
* @param stack Pointer of the stack.
* @return Size of the stack.
*/

static inline size_t gonc_stack_get_size(struct gonc_stack* stack)
{
    return stack->size;
}

/**
* @brief Pushs data to the stack.
* Pushes data to the stack.
* @param stack Pointer of the stack.
* @param data Pointer of the data to push.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_stack_push(struct gonc_stack* stack, void* data, size_t data_size);

/**
* @brief Copies topmost data of the stack to parameter 'data'.
* This is an inline function and simply copies topmost data of the stack to parameter 'data'.
* @param stack Pointer of the stack.
* @param data Pointer of the output data.
* @param data_size Size of the data.
*/

static inline void gonc_stack_peek(struct gonc_stack* stack, void* data, size_t data_size)
{
    memcpy(data, stack->top->data, data_size);
}

/**
* @brief Pops data to parameter 'data'.
* This function pops data from the stack and copies to parameter 'data'
* @param stack Pointer of the stack.
* @param data Pointer of the output data.
* @param data_size Size of the data.
* @return 0 if no error, -1 if error.
*/

int gonc_stack_pop(struct gonc_stack* stack, void* data, size_t data_size);

/**
* @brief Destroys the stack.
* This function destroys the stack and frees the memory.
* @param stack Pointer of the stack.
* @return 0 if no error, -1 if error.
*/

int gonc_stack_destroy(struct gonc_stack* stack);

#endif
