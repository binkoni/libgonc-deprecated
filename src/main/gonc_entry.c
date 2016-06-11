#include <stdlib.h>
#include "gonc_primitive.h"

struct gonc_entry* gonc_entry_create_primitive(struct gonc_primitive* primitive)
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->primitive = primitive;
    entry->copy = gonc_primitive_copy_entry;
    entry->destroy = gonc_primitive_destroy_entry;
    return entry;
}

struct gonc_entry* gonc_entry_create_complex(void* complex,
                                                       struct gonc_entry* (*copy)(struct gonc_entry*),
                                                       void (*destroy)(struct gonc_entry*))
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->complex = complex;
    entry->copy = copy;
    entry->destroy = destroy;
    return entry;
}
