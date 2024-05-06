#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = NULL;
    c = malloc(sizeof(unsigned int));
    c -> count = 0u;

    return c;
}

void counter_inc(counter c) {
    c -> count = c -> count + 1;
}

bool counter_is_init(counter c) {
    return c -> count == 0u; 
}

void counter_dec(counter c) {
    if (!counter_is_init(c)) {
        c -> count = c -> count - 1;
    }
}

counter counter_copy(counter c) {
    counter z = NULL;
    z = malloc(sizeof c);
    z -> count = c -> count;

    return z;
}

void counter_destroy(counter c) {
    free(c);
    c = NULL;
}