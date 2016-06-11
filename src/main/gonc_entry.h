#ifndef _GONC_ENTRY_H
#define _GONC_ENTRY_H

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


struct gonc_entry* gonc_entry_create_primitive(struct gonc_primitive* primitive);

struct gonc_entry* gonc_entry_create_complex(void* complex,
                                                       struct gonc_entry* (*copy)(struct gonc_entry*),
                                                       void (*destroy)(struct gonc_entry*));

static inline struct gonc_entry* gonc_entry_copy(struct gonc_entry* entry)
{
    return entry->copy(entry);
}

static inline void gonc_entry_destroy(struct gonc_entry* entry)
{
    entry->destroy(entry);
}

#endif
