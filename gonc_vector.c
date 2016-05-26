#include <stdlib.h>
#include <string.h>
#include "gonc_vector.h"

struct gonc_vector* gonc_vector_create(size_t capacity, size_t data_size)
{
    struct gonc_vector* vector = malloc(sizeof(struct gonc_vector));
    vector->array = calloc(capacity, sizeof(void*));
    vector->capacity = capacity;
    vector->data_size = data_size;
    vector->size = 0;
    return vector;
}

int gonc_vector_set(struct gonc_vector* vector, size_t index, void* data)
{
    if(index >= vector->capacity || index < 0) return -1;
    memcpy((char*)(vector->array) + (index * vector->data_size), data, vector->data_size);
}

int gonc_vector_add(struct gonc_vector* vector, size_t index, void* data)
{
    (char*)(vector->array) + (index * vector->data_size)
    return 0;
}

int gonc_vector_get(struct gonc_vector* vector, size_t index, void* data)
{
    if(index >= vector->capacity || index < 0) return -1;
    memcpy(data, (char*)(vector->array) + (index * vector->data_size), vector->data_size);
    return 0;
}

int gonc_vector_remove(struct gonc_vector* vector, size_t index, void* data)
{
    return 0;
}

int gonc_vector_destroy(struct gonc_vector* vector)
{
    free(vector->array);
    free(vector);
    return 0;
}
