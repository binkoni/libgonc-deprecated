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
#include "gonc_stack.h"
#include "gonc_entry.h"

int gonc_stack_push(struct gonc_stack* stack, struct gonc_entry* entry)
{
    if(stack->size > 0)
    {
        stack->top->next = malloc(sizeof(struct gonc_node));
        stack->top->next->previous = stack->top;
        stack->top = stack->top->next;
    }
    else if(stack->size == 0)
    {
        stack->top = malloc(sizeof(struct gonc_node));
    }
    else
    {
        return -1;
    }

    stack->top->entry = entry;
    ++(stack->size);

    return 0;
}

struct gonc_entry* gonc_stack_pop(struct gonc_stack* stack)
{
    if(stack->size <= 0) return NULL;

    struct gonc_node* target_top = stack->top;
    stack->top = stack->top->previous;
    struct gonc_entry* target_entry = target_top->entry;
    free(target_top);
    --(stack->size);
    
    return target_entry;
}

void gonc_stack_destroy(struct gonc_stack* stack)
{
    for(int i = 0; i < stack->size; i++)
    {
        gonc_entry_destroy(stack->top->entry);
        struct gonc_node* target_top = stack->top;
        stack->top = stack->top->previous;
        free(target_top);
    }
    free(stack);
}
