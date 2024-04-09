#include <assert.h>
#include <stdbool.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*
    Respondiendo a las preguntas basadas en los resultados del programa, vemos que:
    `goes_before()` ordena los elementos en base a su valor absoluto,
    de modo que "-63760" irá detrás de "63885" pero después de "63736", lo cual,
    si estuvieramos teniendo en cuenta el signo de los números, no tendría sentido.

    Los números usados como ejemplo pueden ser vistos en práctica en la ejecución del
    programa para el archivo "unsorted-1000.in" en la carpeta "input". 
*/

static void insert(int a[], unsigned int i) {
    int j;
    j = i;

    while (j > 0 && goes_before(a[j], a[j - 1])) {
        swap(a, j - 1, j);
        j = j - 1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        int b[i - 1];
        array_copy(b, a, i - 1);
        assert(array_is_sorted(b, i - 1));

        insert(a, i);
    }
}
