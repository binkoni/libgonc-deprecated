#ifndef _GONC_ENTRY_H
#define _GONC_ENTRY_H

#include <stdlib.h>

struct gonc_entry
{
    void* data;
    void (*destroy)(void*);
};

static inline void gonc_primitive_destroy(void* primitive)
{
    free(primitive);
}

static inline struct gonc_entry* gonc_entry_create()
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    return entry;
}

static inline struct gonc_entry* gonc_entry_create_primitive()
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->destroy = gonc_primitive_destroy;
    return entry;
}

static inline void gonc_entry_destroy(struct gonc_entry* entry)
{
    entry->destroy(entry->data);
    free(entry);
}

#endif
