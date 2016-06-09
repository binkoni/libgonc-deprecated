#ifndef _GONC_PRIMITIVE_H
#define _GONC_PRIMITIVE_H

#include <stdlib.h>
#include "gonc_entry.h"

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

static inline gonc_entry* gonc_primitive_copy_entry(struct gonc_entry* entry)
{
    struct gonc_entry* new_entry = malloc(sizeof(struct gonc_entry));
    new_entry->primitive = malloc(sizeof(struct gonc_primitive));
    new_entry->primitive->data = malloc(entry->primitive->data_size);
    memcpy(new_entry->primitive->data, entry->primitive->data, entry->primitive->data_size);
    new_entry->primitive->data_size = entry->primitive->data_size;
    new_entry->copy = gonc_entry_copy_primitive;
    new_entry->destroy = gonc_entry_destroy_primitive;
}

static inline void gonc_primitive_destroy_entry(struct gonc_entry* entry)
{
    gonc_primitive_destroy(entry->primitive);
    free(entry);
}


#endif
