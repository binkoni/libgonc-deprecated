#ifndef _GONC_STRING_H
#define _GONC_STRING_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <string.h>

struct gonc_string
{
    char* chars;
    size_t length;
}

inline struct gonc_string* gonc_string_create(char* chars)
{
    struct gonc_string* string = malloc(sizeof(struct gonc_string));
    string->chars = chars;
    return string;
}

inline struct gonc_string* gonc_string_create_from_literal(char* chars)
{
    struct gonc_string* string = malloc(sizeof(struct gonc_string));
    string->length = strlen(chars);
    string->chars = malloc(string->length);
    memcpy(string->chars, chars, string->length);
    return string;
}

inline void gonc_string_destroy(struct gonc_string* string)
{
    free(string->chars);
    free(string);
}

#endif
