#ifndef _GONC_VECTOR_H
#define _GONC_VECTOR_H

#include <stdlib.h>
#include <string.h>

struct gonc_array_list
{
    void** array;
    size_t capacity;
    size_t data_size;
    size_t size;
};

struct gonc_array_list* gonc_array_list_create(size_t capacity, size_t data_size);

static inline size_t gonc_array_list_get_capacity(struct gonc_array_list* array_list)
{
    return array_list->capacity;
}

static inline size_t gonc_array_list_get_data_size(struct gonc_array_list* array_list)
{
    return array_list->data_size;
}

static inline size_t gonc_array_list_get_size(struct gonc_array_list* array_list)
{
    return array_list->size;
}

int gonc_array_list_set(struct gonc_array_list* array_list, size_t index, void* data);

int gonc_array_list_insert(struct gonc_array_list* array_list, size_t index, void* data);

static inline int gonc_array_list_append(struct gonc_array_list* array_list, void* data)
{
    return gonc_array_list_insert(array_list, array_list->size, data);
}

int gonc_array_list_get(struct gonc_array_list* array_list, size_t index, void* data);

int gonc_array_list_remove(struct gonc_array_list* array_list, size_t index, void* data);

int gonc_array_list_compact(struct gonc_array_list* array_list);

static inline void gonc_array_list_destroy(struct gonc_array_list* array_list)
{
    free(array_list->array);
    free(array_list);
}

#endif
