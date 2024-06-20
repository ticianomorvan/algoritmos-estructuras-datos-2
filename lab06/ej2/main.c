#include <stdlib.h>
#include <stdio.h>
#include "string.h"

#define MAX_LENGTH 24

int main(void) {
	string first_str = string_create("Caza");
	string second_str = string_create("Casamiento");

	printf("Teniendo las palabras: ");
	string_dump(first_str, stdout);
	printf(" y ");
	string_dump(second_str, stdout);
	printf("\n");

	if (string_eq(first_str, second_str)) {
		printf("Ambas son iguales.\n");
	} else if (string_less(first_str, second_str)) {
		printf("La primera palabra viene antes que la segunda, alfabéticamente.\n");
	} else {
		printf("La primera palabra viene después que la segunda, alfabéticamente.\n");
	}

	string_destroy(first_str);
	string_destroy(second_str);

	return EXIT_SUCCESS;
}
