#ifndef _STRFUNCS_H
#define _STRFUNCS_H

#include <stdbool.h>

size_t string_length(const char *str);
/**
 * Returns the length of the string
*/

char *string_filter(const char *str, char c);
/**
 * Returns a new string without the characters equal to <c>
*/

bool string_is_symmetric(const char *str);
/**
 * Returns true if the string is symmetric
 * Symmetric means the string can be read both from left to right and viceversa, e.g. "neuquen"
*/

#endif