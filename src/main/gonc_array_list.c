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
#include "gonc_array_list.h"

struct gonc_array_list* gonc_array_list_create(size_t capacity)
{
    struct gonc_array_list* array_list = malloc(sizeof(struct gonc_array_list));
    array_list->array = calloc(capacity, sizeof(void*));
    array_list->capacity = capacity;
    array_list->size = 0;
    return array_list;
}

int gonc_array_list_set(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size)
{
    if(index >= array_list->size || index < 0) return -1;

    *(array_list->array + index) = malloc(data_size);
    memcpy(*(array_list->array + index), data, data_size);
    return 0;
}

int gonc_array_list_insert(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size)
{
    if(index > array_list->size || index < 0) return -1;

    if(array_list->size >= array_list->capacity)
    {
        array_list->capacity *= 2;
        array_list->array = realloc(array_list->array, array_list->capacity * sizeof(void*));
    }
    if(index < array_list->size - 1)
    {
        memmove(array_list->array + (index + 1), array_list->array + index, (array_list->size - index) * sizeof(void*));
    }
    *(array_list->array + index) = malloc(data_size);
    memcpy(*(array_list->array + index), data, data_size);
    ++(array_list->size);
    return 0;
}

int gonc_array_list_get(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size)
{
    if(index >= array_list->size || index < 0) return -1;
    memcpy(data, *(array_list->array + index), data_size);
    return 0;
}

int gonc_array_list_remove(struct gonc_array_list* array_list, size_t index, void* data, size_t data_size)
{
    if(index >= array_list->size || index < 0) return -1;
    if(data != NULL)
        memcpy(data, *(array_list->array + index), data_size);
    free(*(array_list->array + index));
    if(index < array_list->size - 1)
    {
        memmove(array_list->array + index, array_list->array + (index + 1), (array_list->size - index) * sizeof(void*));
    }
    --(array_list->size);
    return 0;
}

int gonc_array_list_compact(struct gonc_array_list* array_list)
{
    array_list->capacity = array_list->size;
    array_list->array = realloc(array_list->array, array_list->capacity);
    if(array_list->array != NULL) return 0;
    else return -1;
}
