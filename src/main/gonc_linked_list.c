#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <string.h>
#include "gonc_linked_list.h"
#include "gonc_node.h"

int gonc_linked_list_set(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    if(index >= linked_list->size || index < 0) return -1;
    struct gonc_node* current_node = linked_list->head;
    for(int i = 0; i < index; i++)
        current_node = current_node->next;
    memcpy(current_node->data, data, data_size);
    return 0;
}

int gonc_linked_list_insert(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    if(index > linked_list->size || index < 0) return -1;

    struct gonc_node* new_node = calloc(1, sizeof(struct gonc_node));
    new_node->data = malloc(data_size);
    memcpy(new_node->data, data, data_size);

    if(linked_list->size == 0)
    {
        linked_list->head = new_node;
        linked_list->head->previous = linked_list->head;
        linked_list->head->next = linked_list->head;
    }
    else if(index == 0)
    {
        struct gonc_node* tail_node = linked_list->head->previous;

        new_node->previous = tail_node;
        new_node->next = linked_list->head;

        linked_list->head->previous = new_node;
        tail_node->next = new_node;

        linked_list->head = new_node;
    }
    else if(index == linked_list->size)
    {
        struct gonc_node* tail_node = linked_list->head->previous;

        new_node->previous = tail_node;
        new_node->next = linked_list->head;

        linked_list->head->previous = new_node;
        tail_node->next = new_node;

        tail_node = new_node;
    }
    else
    {
        struct gonc_node* previous_node = linked_list->head;
        for(int i = 0; i < index - 1; i++)
            previous_node = previous_node->next;

        struct gonc_node* next_node = previous_node->next;

        new_node->previous = previous_node;
        new_node->next = next_node;

        previous_node->next = new_node;
        next_node->previous = new_node;
    }

    ++(linked_list->size);
    return 0;
}

int gonc_linked_list_get(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    if(index >= linked_list->size || index < 0) return -1;
    struct gonc_node* current_node = linked_list->head;
    for(int i = 0; i < index; i++)
        current_node = current_node->next;
    memcpy(data, current_node->data, data_size);
    return 0;
}

int gonc_linked_list_remove(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    if(index >= linked_list->size || index < 0) return -1;

    struct gonc_node* target_node = linked_list->head;
    for(int i = 0; i < index; i++)
        target_node = target_node->next;

    if(linked_list->size == 1)
    {
        linked_list->head = NULL;
    }
    else if(index == 0)
    {
        struct gonc_node* next_node = target_node->next;

        next_node->previous = target_node->previous;
        target_node->previous->next = next_node;

        linked_list->head = next_node;
    }
    else if(index == linked_list->size - 1)
    {
        struct gonc_node* previous_node = target_node->previous;
        previous_node->next = target_node->next;
        target_node->next->previous = previous_node;
    }
    else
    {
        struct gonc_node* previous_node = target_node->previous;
        struct gonc_node* next_node = target_node->next;
        previous_node->next = next_node;
        next_node->previous = previous_node;
    }

    if(data != NULL)
        memcpy(data, target_node->data, data_size);
    free(target_node->data);
    free(target_node);
    --(linked_list->size);
    return 0;
}
