#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_stack(stack s) {
  unsigned int size = stack_size(s);
  stack_elem *array = stack_to_array(s);

  for (unsigned int i = 0u; i < size; ++i) {
    printf(
      "-----------------------------\n"
      "Elemento %u en pila: %i\n",
      i, array[i]
    );
  }
  printf(
    "------------------------------\n"
    "La pila tiene %u elementos\n",
    size
  );
}

int main() {
  stack s = stack_empty();
  s = stack_push(s, 5);
  s = stack_push(s, 10);

  print_stack(s);

  stack_destroy(s);
  return EXIT_SUCCESS;
}