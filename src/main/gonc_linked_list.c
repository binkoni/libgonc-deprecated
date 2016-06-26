/*
* Copyright (C) 2016  Byeonggon Lee <gonny952@gmail.com>
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Library General Public
* License as published by the Free Software Foundation; either
* version 3 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Library General Public License for more details.
*
* You should have received a copy of the GNU Library General Public
* License along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <string.h>
#include "gonc_linked_list.h"
#include "gonc_node.h"
#include "gonc_entry.h"

int gonc_linked_list_set(struct gonc_linked_list* linked_list, size_t index, struct gonc_entry* entry)
{
    if(index >= linked_list->size || index < 0) return -1;
    struct gonc_node* current_node = linked_list->head;
    for(int i = 0; i < index; i++)
        current_node = current_node->next;
    current_node->entry = entry;
    return 0;
}

int gonc_linked_list_insert(struct gonc_linked_list* linked_list, size_t index, struct gonc_entry* entry)
{
    if(index > linked_list->size || index < 0) return -1;

    struct gonc_node* new_node = calloc(1, sizeof(struct gonc_node));
    new_node->entry = entry;

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

struct gonc_entry* gonc_linked_list_get(struct gonc_linked_list* linked_list, size_t index, struct gonc_entry* entry)
{
    if(index >= linked_list->size || index < 0) return -1;
    struct gonc_node* current_node = linked_list->head;
    for(int i = 0; i < index; i++)
        current_node = current_node->next;
    return current_node->entry;
}

int gonc_linked_list_remove(struct gonc_linked_list* linked_list, size_t index)
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

    gonc_entry_destroy(target_node->entry);
    free(target_node);
    --(linked_list->size);
    return 0;
}
