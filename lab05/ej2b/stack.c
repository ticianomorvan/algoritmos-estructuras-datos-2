#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
  stack_elem elem;
  stack next;
  size_t size;
};

bool invrep(stack s) {
  return s != NULL;
}

stack stack_empty() {
  stack s = NULL;
  s = malloc(sizeof (struct _s_stack));
  s -> next = NULL;
  s -> size = 0;

  assert(invrep(s) && stack_is_empty(s));
  return s;
}

bool stack_is_empty(stack s) {
  assert(invrep(s));
  return s -> next == NULL;
}

stack stack_push(stack s, stack_elem e) {
  assert(invrep(s));
  stack p = NULL;

  p = malloc(sizeof (struct _s_stack));
  p -> elem = e;
  p -> next = s;
  p -> size = s -> size + 1;
  s = p;

  assert(invrep(s) && !stack_is_empty(s));
  return s;
}

stack stack_pop(stack s) {
  assert(invrep(s) && !stack_is_empty(s));

  stack p = NULL;
  p = s;
  s = s -> next;
  free(p);

  assert(invrep(s));
  return s;
}

unsigned int stack_size(stack s) {
  assert(invrep(s));

  unsigned int size = 0u;

  if (!stack_is_empty(s)) {
    size = s -> size;
  } 

  return size;
}

stack_elem stack_top(stack s) {
  assert(invrep(s) && !stack_is_empty(s));

  return s -> elem;
}

stack_elem *stack_to_array(stack s) { 
  assert(invrep(s));
  stack p = NULL;
  stack_elem *result = NULL;
  unsigned int size, i;
  
  if (!stack_is_empty(s)) {
    size = stack_size(s);
    result = calloc(size, sizeof (stack_elem));
    p = s;
    i = size - 1;
  
    while (!stack_is_empty(p)) {
      stack_elem elem = stack_top(p);
      result[i] = elem;
      p = p -> next;
      --i;
    }
  }

  return result;
}

stack stack_destroy(stack s) {
  assert(invrep(s));
  stack p = NULL;

  while (!stack_is_empty(s)) {
    p = s;
    s = p -> next;  
    free(p);
  }

  free(s);
  s = NULL;

  assert(s == NULL);
  return s;
}