#ifndef _GONC_PRIMITIVE_H
#define _GONC_PRIMITIVE_H

struct gonc_primitive
{
    void* data;
    size_t data_size;
};

struct gonc_primitive* gonc_primitive_create(void* data, size_t data_size);

static inline void* gonc_primitive_get_data(struct gonc_primitive* primitive)
{
    return primitive->data;
}

static inline size_t gonc_primitive_get_data_size(struct gonc_primitive* primitive)
{
    return primitive->data_size;
}

struct gonc_primitive* gonc_primitive_copy(struct gonc_primitive* primitive);

void gonc_primitive_destroy(struct gonc_primitive* primitive);

struct gonc_entry* gonc_primitive_copy_entry(struct gonc_entry* entry);

void gonc_primitive_destroy_entry(struct gonc_entry* entry);

#endif
