#ifndef _GONC_VECTOR_H
#define _GONC_VECTOR_H

#include <string.h>

struct gonc_vector
{
    void** array;
    size_t capacity;
    size_t data_size;
    size_t size;
};

struct gonc_vector* gonc_vector_create(size_t capacity, size_t data_size);

int gonc_vector_add(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_remove(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_destroy(struct gonc_vector* vector);

#endif
