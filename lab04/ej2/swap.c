#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main() {
  int x = 6, y = 4;
  printf("x = %i, y = %i\n", x, y);
  swap(&x, &y);
  printf("x = %i, y = %i\n", x, y);

  assert(x == 4 && y == 6);
  return EXIT_SUCCESS;
}