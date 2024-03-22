#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *file = fopen(filepath, "r");

    unsigned int array_length;
    fscanf(file, "%u", &array_length);

    if (array_length > max_size) {
        printf("The number of elements in the array exceeds the established limit: %d\n", max_size);
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < array_length; i++) {
        int value;
        int length = fscanf(file, "%d", &value);
        bool is_eof = length == -1; 

        if (is_eof) {
            printf("The number of elements in the array doesn't match the array length.\n");
            exit(EXIT_FAILURE);
        }

        array[i] = value;
    }

    return array_length;
}

void array_dump(int a[], unsigned int length) {
    if (length == 0) {
        printf("[ ]\n");

        return;
    }

    for (unsigned int i = 0; i < length; i++) {
        if (i == 0) {
            printf("[ %d,", a[i]);
        } else if (i == length - 1) {
            printf(" %d ]\n", a[i]);
        } else {
            printf(" %d,", a[i]);
        }
    }
}