#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *file = fopen(filepath, "r");

    int array_length;

    for (unsigned int i = 0; i < max_size; i++) {
        int value, length;

        if (i == 0) {
            fscanf(file, "%d", &array_length);
        } else {
            length = fscanf(file, "%d", &value);

            if (length == -1) {
                break;
            }

            array[i - 1] = value;
        }
    }

    fclose(file);

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