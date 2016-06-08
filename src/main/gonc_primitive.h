#ifndef _GONC_PRIMITIVE_H
#define _GONC_PRIMITIVE_H

#include <stdlib.h>

struct gonc_primitive
{
    void* data;
    size_t data_size;
}

static inline struct gonc_primitive* gonc_primitive_create(void* data, size_t data_size)
{
    struct gonc_primitive* primitive = malloc(sizeof(struct gonc_primitive));
    primitive->data = data;
    primitive->data_size = data_size;
    return primitive;
}

static inline struct gonc_primitive* gonc_primitive_copy(struct gonc_primitive* primitive)
{
    struct gonc_primtive* new_primitive =  malloc(sizeof(struct gonc_primitive));
    new_primitive->data = malloc(primitive->data_size);
    memcpy(new_primitive->data, primitive->data, primitive->data_size);
    new_primitive->data_size = primitive->data_size;
}

static inline gonc_primitive_destroy(struct gonc_primitive* primitive)
{
    free(primitive->data);
    free(primitive);
}

#endif
