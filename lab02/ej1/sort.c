#include <assert.h>
#include <stdbool.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


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
