#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
  stack_elem elem;
  stack next;
};

stack stack_empty() {
  stack new_stack = NULL;

  return new_stack;
}

bool stack_is_empty(stack s) {
  return s == NULL;
}

stack stack_push(stack s, stack_elem e) {
  stack p = NULL;

  p = malloc(sizeof (stack_elem));
  p -> elem = e;
  p -> next = s;
  s = p;

  return s;
}

stack stack_pop(stack s) {
  stack p = NULL;
  p = s;
  s = s -> next;
  free(p);

  return s;
}

unsigned int stack_size(stack s) {
  stack p = NULL;
  unsigned int size = 0u;

  if (!stack_is_empty(s)) {
    p = s;
    ++size;
    while (p -> next != NULL) {
      p = p -> next;
      ++size;
    }
  }
  
  return size;
}

stack_elem stack_top(stack s) {
  return s -> elem;
}

stack_elem *stack_to_array(stack s) {
  stack p = NULL;
  stack_elem *result = NULL;
  unsigned int size, i;
  
  if (!stack_is_empty(s)) {
    size = stack_size(s);
    result = calloc(size, sizeof (stack_elem));
    p = s;
    i = size - 1;
  
    while (!stack_is_empty(p)) {
      stack_elem elem = p -> elem;
      result[i] = elem;
      p = p -> next;
      --i;
    }
  }

  return result;
}

stack stack_destroy(stack s) {
  stack p = NULL;

  if (!stack_is_empty(s)) {
    while (p -> next != NULL) {
      p = s;
      s = p -> next;
      free(p);
    }
  }

  return s;
}