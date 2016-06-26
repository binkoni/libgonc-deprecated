#include <stdlib.h>
#include <string.h>
#include "gonc_primitive.h"
#include "gonc_entry.h"

struct gonc_primitive* gonc_primitive_create(void* value, size_t value_size)
{
    struct gonc_primitive* primitive = malloc(sizeof(struct gonc_primitive));
    primitive->value = value;
    primitive->value_size = value_size;
    return primitive;
}

struct gonc_primitive* gonc_primitive_copy(struct gonc_primitive* primitive)
{
    struct gonc_primitive* new_primitive =  malloc(sizeof(struct gonc_primitive));
    new_primitive->value = malloc(primitive->value_size);
    memcpy(new_primitive->value, primitive->value, primitive->value_size);
    new_primitive->value_size = primitive->value_size;
}

void gonc_primitive_destroy(struct gonc_primitive* primitive)
{
    free(primitive->value);
    free(primitive);
}

struct gonc_entry* gonc_primitive_copy_entry(struct gonc_entry* entry)
{
    struct gonc_entry* new_entry = malloc(sizeof(struct gonc_entry));
    struct gonc_primitive* primitive = (struct gonc_primitive*)entry->data;
    struct gonc_primitive* new_primitive = gonc_primitive_copy(primitive);
    new_primitive->value = malloc(primitive->value_size);
    memcpy(new_primitive->value, primitive->value, primitive->value_size);
    new_entry->data = new_primitive;
    new_entry->copy = gonc_primitive_copy_entry;
    new_entry->destroy = gonc_primitive_destroy_entry;
}

void gonc_primitive_destroy_entry(struct gonc_entry* entry)
{
    gonc_primitive_destroy((struct gonc_primitive*)(entry->data));
    free(entry);
}
