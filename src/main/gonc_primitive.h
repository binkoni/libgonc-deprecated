#ifndef _GONC_PRIMITIVE_H
#define _GONC_PRIMITIVE_H

struct gonc_primitive
{
    void* value;
    size_t value_size;
};

struct gonc_primitive* gonc_primitive_create(void* value, size_t value_size);

static inline void* gonc_primitive_get_value(struct gonc_primitive* primitive)
{
    return primitive->value;
}

static inline size_t gonc_primitive_get_value_size(struct gonc_primitive* primitive)
{
    return primitive->value_size;
}

struct gonc_primitive* gonc_primitive_copy(struct gonc_primitive* primitive);

void gonc_primitive_destroy(struct gonc_primitive* primitive);

struct gonc_entry* gonc_primitive_copy_entry(struct gonc_entry* entry);

void gonc_primitive_destroy_entry(struct gonc_entry* entry);

#endif
