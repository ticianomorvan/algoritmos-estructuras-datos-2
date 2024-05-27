#include <stdio.h>
#include <stdlib.h>
#include "strfuncs.h"

size_t string_length(const char *str) {
  unsigned last_index = 0u;

  while (str[last_index] != '\0') {
    last_index += 1;
  }

  return last_index;
}

char *string_filter(const char *str, char c) {
  char *filtered_str = NULL;
  size_t last_index = 0u;
  size_t valid_filtered_items = 1u; // '\0'
  size_t str_length = string_length(str);

  for (unsigned int i = 0u; i < str_length; ++i) {
    if (str[i] != c) {
      ++valid_filtered_items;
    }
  }

  filtered_str = calloc(valid_filtered_items, sizeof (char));

  for (unsigned i = 0u; i < str_length; ++i) {
    if (str[i] != c) {
      filtered_str[last_index] = str[i];
      last_index += 1;
    }
  }

  return filtered_str;
}

bool string_is_symmetric(const char *str) {
  char start, end;
  unsigned int i, j;
  bool result = true;
  size_t str_length = string_length(str);

  i = 0u;
  j = str_length - 1;

  while (i < j && result) {
    start = str[i];
    end = str[j];

    if (start != end) {
      result = false;
    }

    ++i;
    --j;
  }

  return result;
}