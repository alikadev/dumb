#ifndef CSTR_H
#define CSTR_H

#include <string.h>
#include <stdbool.h>
#include <dumb/list.h>

#define TOKENS_PREALLOC 32
#define TOKENS_MAX_LENGTH (32 * 1024)

// Same as strcmp == 0
bool streq(const char *s1, const char *s2);

// Will init the dumb_list, need to free with strtok_free!
// ptr = char**
int strtokc(dumb_list *tokens, const char *src, const char delim);

void strtok_free(dumb_list *list);

#endif