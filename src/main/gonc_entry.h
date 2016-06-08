#ifndef _GONC_ENTRY_H
#define _GONC_ENTRY_H

#include <stdlib.h>
#include "gonc_primitive.h"

struct gonc_entry
{
    union {
        struct gonc_entry* entry;
        struct gonc_primitive* primitive;
    };
    size_t (*get_size)(struct gonc_entry*);
    struct gonc_entry* (*copy)(struct gonc_entry*);
    void (*destroy)(struct gonc_entry*);

};

static inline struct gonc_entry* gonc_entry_create_primitive(struct gonc_primitive* primitive)
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->primitive = primitive;
    entry->copy = gonc_entry_copy_primitive;
    entry->destroy = gonc_entry_destroy_primitive;
    return entry;
}

static inline gonc_entry* gonc_entry_copy_primitive(struct gonc_entry* entry)
{
    struct gonc_entry* new_entry = malloc(sizeof(struct gonc_entry));
    new_entry->primitive = malloc(sizeof(struct gonc_primitive));
    new_entry->primitive->data = malloc(entry->primitive->data_size);
    memcpy(new_entry->primitive->data, entry->primitive->data, entry->primitive->data_size);
    new_entry->primitive->data_size = entry->primitive->data_size;
    new_entry->copy = gonc_entry_copy_primitive;
    new_entry->destroy = gonc_entry_destroy_primitive;
}

static inline void gonc_entry_destroy_primitive(struct gonc_entry* entry)
{
    gonc_primitive_destroy(entry->primitive);
    free(entry);
}

static inline struct gonc_entry* gonc_entry_create_entry(struct gonc_entry* entry)
{
    struct gonc_entry* new_entry = malloc(sizeof(struct gonc_entry));
    new_entry->entry = entry;
    return new_entry;
}

static inline struct gonc_entry* gonc_entry_copy_entry(struct gonc_entry* entry)
{
    struct gonc_entry* new_entry = malloc(sizeof(struct gonc_entry));
    new_entry->entry = entry->copy(entry);
}

static inline void gonc_entry_destroy_entry(struct gonc_entry* entry)
{
    entry->entry->destroy(entry->entry);
    free(entry);
}

#endif
