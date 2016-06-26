#ifndef _GONC_ENTRY_H
#define _GONC_ENTRY_H

#include <stdlib.h>

struct gonc_entry
{
    void* data;
    struct gonc_entry* (*copy)(struct gonc_entry*);
    void (*destroy)(struct gonc_entry*);
//    size_t (*get_size)(struct gonc_entry*);
};

static inline struct gonc_entry* gonc_entry_create(void* data, struct gonc_entry* (*copy)(struct gonc_entry*), void (*destroy)(struct gonc_entry*))
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->data = data;
    entry->copy = copy;
    entry->destroy = destroy;
    return entry;
}

static inline void* gonc_entry_get_data(struct gonc_entry* entry)
{
    return entry->data;
}

static inline struct gonc_entry* gonc_entry_copy(struct gonc_entry* entry)
{
    return entry->copy(entry);
}

static inline void gonc_entry_destroy(struct gonc_entry* entry)
{
    entry->destroy(entry);
}

#endif
