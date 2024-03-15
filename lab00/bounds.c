#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

int get_value () {
  int n;
 
  printf("Ingrese un valor a verificar: ");
  scanf("%i", &n);

  return n;
}

void populate_array(int length, int arr[]) {
  for (int i = 0; i < length; i++) {
    int x;

    printf("Ingrese un valor entero para el índice %d: ", i);
    scanf("%i", &x);

    arr[i] = x;
  }
}

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    for (unsigned int i = 0; i < length; i++) {
      if (arr[i] <= value) {
        res.is_upperbound = true;
	res.is_lowerbound = false;
      } else if (arr[i] >= value) {
        res.is_lowerbound = true;
	res.is_upperbound = false;
      }

      if (arr[i] == value) {
	res.exists = true;
        res.where = i;
      } else {
	res.exists = false;
	res.where = 0;
      }
    }

    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    populate_array(ARRAY_SIZE, a);

    int value = get_value();

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d", result.is_upperbound); // Imprime 1
    printf("%d", result.is_lowerbound); // Imprime 0
    printf("%u", result.exists);        // Imprime 1
    printf("%u", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

