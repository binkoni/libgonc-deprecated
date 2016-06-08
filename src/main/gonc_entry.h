#ifndef _GONC_ENTRY_H
#define _GONC_ENTRY_H

#include <stdlib.h>

struct gonc_entry
{
    union {
        struct gonc_entry* entry_data;
        void* primitive_data;
    };
    size_t primitive_data_size;
    size_t (*get_size)(struct gonc_entry*);
    struct gonc_entry* (*copy)(struct gonc_entry*);
    void (*destroy)(struct gonc_entry*);

};

static inline struct gonc_entry* gonc_entry_create_primitive(void* primitive_data, size_t primitive_data_size)
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->primitive_data = primitive_data;
    entry->primitive_data_size = primitive_data_size;
    entry->copy = gonc_entry_copy_primitive;
    entry->destroy = gonc_entry_destroy_primitive;
    return entry;
}

static inline gonc_entry* gonc_entry_copy_primitive(struct gonc_entry* entry)
{
    struct gonc_entry* new_entry = malloc(sizeof(struct gonc_entry));
    new_entry->primitive_data = malloc(entry->primitive_data_size);
    memcpy(new_entry->primitive_data, entry->primitive_data, entry->primitive_data_size);
    new_entry->primitive_data_size = entry->primitive_data_size;
    new_entry->copy = gonc_entry_copy_primitive;
    new_entry->destroy = gonc_entry_destroy_primitive;
}

static inline void gonc_entry_destroy_primitive(struct gonc_entry* entry)
{
    free(entry->primitive_data);
    free(entry);
}

static inline struct gonc_entry* gonc_entry_create_entry(struct gonc_entry* entry_data)
{
    struct gonc_entry* entry = malloc(sizeof(struct gonc_entry));
    entry->entry_data;
    entry->primitive_data_size = 0;
    return entry;
}

static inline struct gonc_entry* gonc_entry_copy_entry(struct gonc_entry* entry)
{
    struct gonc_entry* new_entry = malloc(sizeof(struct gonc_entry));
    new_entry->entry_data = new_entry->entry_data->copy(new_entry->entry_data);
}

static inline void gonc_entry_destroy_entry(struct gonc_entry* entry)
{
    entry->entry_data->destroy(entry->entry_data);
    free(entry);
}

#endif
