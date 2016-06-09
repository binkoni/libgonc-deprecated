#ifndef _GONC_ENTRY_H
#define _GONC_ENTRY_H

#include <stdlib.h>
#include "gonc_primitive.h"

struct gonc_entry
{
    union {
        struct gonc_primitive* primitive;
        void* complex;
    };
//    size_t (*get_size)(struct gonc_entry*);
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

static inline struct gonc_entry* gonc_entry_create_complex(void* complex,
                                                       struct gonc_entry* (*copy)(struct gonc_entry*),
                                                       void (*destroy)(struct gonc_entry*))
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->complex = complex;
    entry->copy = copy;
    entry->destroy = destroy;
    return entry;
}

static inline struct gonc_entry* gonc_entry_copy(struct gonc_entry* entry)
{
    return entry->copy(entry);
}

statir inline void gonc_entry_destroy(struct gonc_entry* entry)
{
    entry->destroy();
}

#endif
