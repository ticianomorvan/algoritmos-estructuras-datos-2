#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_stack_array(stack s) {
  unsigned int size = stack_size(s);
  stack_elem *array = stack_to_array(s);

  printf("La pila corresponde al arreglo (der. a izq.): [");
  for (unsigned int i = 0u; i < size; ++i) {
    if (i == 0u) {
      printf(" %i ", array[i]);
    } else {
      printf("%i ", array[i]);
    }
  }
  printf("]\n\n");

  free(array);
}

void print_stack(stack s) {
  unsigned int size = stack_size(s);
  stack_elem *array = stack_to_array(s);

  for (int i = size - 1; i >= 0; --i) {
    printf(
      "-----------------------------\n"
      "Elemento %u en pila: %i\n",
      size - i, array[i]
    );
  }
  printf(
    "------------------------------\n"
    "La pila tiene %u elementos\n\n",
    size
  );

  free(array);
}

int main() {
  stack s = stack_empty();

  printf("///// AÑADIR TRES ELEMENTOS /////\n");
  s = stack_push(s, 5);
  s = stack_push(s, 12);
  s = stack_push(s, 25);
  print_stack(s);
  print_stack_array(s);

  printf("///// CAMBIAR TOPE DE LA PILA /////\n");
  s = stack_pop(s);
  s = stack_push(s, 50);
  print_stack(s);
  print_stack_array(s);


  printf("///// VACIAR LA PILA /////\n");
  s = stack_pop(s);
  s = stack_pop(s);
  s = stack_pop(s);
  print_stack(s);
  print_stack_array(s);


  printf("///// AÑADIR UN ELEMENTO A UNA PILA QUE FUE VACIADA /////\n");
  s = stack_push(s, 69420);
  print_stack(s);
  print_stack_array(s);

  s = stack_destroy(s);
  return EXIT_SUCCESS;
}