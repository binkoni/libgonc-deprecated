#include <stdlib.h>
#include <string.h>
#include "gonc_vector.h"

struct gonc_vector* gonc_vector_create(size_t size, size_t data_size)
{
    struct gonc_vector* vector = malloc(sizeof(struct gonc_vector));
    vector->array = calloc(size, sizeof(void*));
    vector->size = size;
    return vector;
}

int gonc_vector_set(struct gonc_vector* vector, size_t index, void* data, size_t data_size)
{
    vector->array 
    return 0;
}

int gonc_vector_add(struct gonc_vector* vector, size_t index, void* data, size_t data_size)
{
    return 0;
}

int gonc_vector_get(struct gonc_vector* vector, size_t index, void* data, size_t data_size)
{
    return 0;
}

int gonc_vector_remove(struct gonc_vector* vector, size_t index, void* data, size_t data_size)
{
    return 0;
}
