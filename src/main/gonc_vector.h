#ifndef _GONC_VECTOR_H
#define _GONC_VECTOR_H

#include <stdlib.h>
#include <string.h>

struct gonc_vector
{
    void** array;
    size_t capacity;
    size_t data_size;
    size_t size;
};

struct gonc_vector* gonc_vector_create(size_t capacity, size_t data_size);

static inline size_t gonc_vector_get_capacity(struct gonc_vector* vector)
{
    return vector->capacity;
}

static inline size_t gonc_vector_get_data_size(struct gonc_vector* vector)
{
    return vector->data_size;
}

static inline size_t gonc_vector_get_size(struct gonc_vector* vector)
{
    return vector->size;
}

int gonc_vector_set(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_append(struct gonc_vector* vector, void* data);

int gonc_vector_insert(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_get(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_remove(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_compact(struct gonc_vector* vector);

static inline void gonc_vector_destroy(struct gonc_vector* vector)
{
    free(vector->array);
    free(vector);
}

#endif
