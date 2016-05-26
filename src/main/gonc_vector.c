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
    if(index >= vector->size || index < 0) return -1;
    memcpy((char*)(vector->array) + (index * vector->data_size), data, vector->data_size);
}

int gonc_vector_append(struct gonc_vector* vector, void* data)
{
    if(vector->size >= vector->capacity)
    {
        vector->capacity *= 2;
        vector->array = realloc(vector->array, vector->capacity); 
    }
    memcpy((char*)(vector->array) + (vector->size * vector->data_size), data, vector->data_size);
    ++(vector->size);
    return 0;
}

int gonc_vector_insert(struct gonc_vector* vector, size_t index, void* data)
{
    if(index + 1 >= vector->size || index < 0) return -1;
    if(vector->size >= vector->capacity)
    {
        vector->capacity *= 2;
        vector->array = realloc(vector->array, vector->capacity);
    }
    memmove((char*)(vector->array) + ((index + 1) * vector->data_size),
         (char*)(vector->array) + (index * vector->data_size),
         (vector->size - index) * vector->data_size);
    memcpy((char*)(vector->array) + (index * vector->data_size), data, vector->data_size);
    ++(vector->size);
    return 0;
}

int gonc_vector_get(struct gonc_vector* vector, size_t index, void* data)
{
    if(index >= vector->size || index < 0) return -1;
    memcpy(data, (char*)(vector->array) + (index * vector->data_size), vector->data_size);
    return 0;
}

int gonc_vector_remove(struct gonc_vector* vector, size_t index, void* data)
{
    if(index + 1 >= vector->size || index < 0) return -1;
    memcpy(data, (char*)(vector->array) + (index * vector->data_size), vector->data_size);
    memmove((char*)(vector->array) + (index * vector->data_size),
         (char*)(vector->array) + ((index + 1) * vector->data_size),
         (vector->size - index) * vector->data_size);
    --(vector->size);
    return 0;
}

int gonc_vector_compact(struct gonc_vector* vector)
{
    vector->capacity = vector->size;
    vector->array = realloc(vector->array, vector->capacity);
    if(vector->array != NULL) return 0;
    else return -1;
}
