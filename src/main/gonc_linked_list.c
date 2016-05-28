#include <stdlib.h>
#include <string.h>
#include "gonc_linked_list.h"
#include "gonc_node.h"

int gonc_linked_list_set(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    struct gonc_node* current_node = linked_list->node;
    for(int i = 0; i < index; i++)
        current_node = current_node->next;
    memcpy(current_node->data, data, data_size);
    return 0;
}

int gonc_linked_list_insert(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    struct gonc_node* current_node = linked_list->node;
    for(int i = 0; i < index; i++)
        current_node = current_node->next;
    struct gonc_node* previous_node = current_node->previous;
    struct gonc_node* new_node = malloc(sizeof(struct gonc_node));
    new_node->data = malloc(data_size);
    memcpy(new_node->data, data, data_size);
    new_node->previous = previous_node;
    previous_node->next = new_node;
    new_node->next = current_node;
    current_node->previous = new_node;
    return 0;
}

int gonc_linked_list_get(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    struct gonc_node* current_node = linked_list->node;
    for(int i = 0; i < index; i++)
        current_node = current_node->next;
    memcpy(data, current_node->data, data_size);
    return 0;
}

int gonc_linked_list_remove(struct gonc_linked_list* linked_list, size_t index, void* data, size_t data_size)
{
    struct gonc_node* target_node = linked_list->node;
    for(int i = 0; i < index; i++)
        target_node = target_node->next;
    struct gonc_node* previous_node = target_node->previous;
    struct gonc_node* next_node = target_node->next;
    previous_node->next = next_node;
    next_node->previous = previous_node;
    free(target_node->data);
    free(target_node);
    return 0;
}

int gonc_linked_list_destroy(struct gonc_linked_list* linked_list)
{
    struct gonc_node* target_node;
    while((target_node = linked_list->node) != NULL)
    {
        linked_list->node = linked_list->node->next;
        free(target_node->data);
        free(target_node);
    }
    free(linked_list);
    return 0;
}

