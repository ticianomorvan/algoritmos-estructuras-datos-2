#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define INITIAL_CAPACITY 1

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep(stack s) {
    return s != NULL;
}

stack stack_empty() {
    stack s = (stack) malloc(sizeof (struct _s_stack));
    s -> elems = (stack_elem*) malloc(INITIAL_CAPACITY * sizeof (stack_elem));
    s -> size = 0;
    s -> capacity = INITIAL_CAPACITY;

    assert(invrep(s) && stack_is_empty(s));
    return s;
}

bool stack_is_empty(stack s) {
    assert(invrep(s));

    return s -> size == 0;
}

stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));
    
    if (s -> size == s -> capacity) {
        unsigned int new_capacity = s -> capacity * 2;
        stack_elem *new_elems = (stack_elem*) realloc(s -> elems, new_capacity * sizeof(stack_elem));
    
        s -> elems = new_elems;
        s -> capacity = new_capacity;
    }

    s -> elems[s -> size] = e;
    s -> size++;

    assert(invrep(s) && !stack_is_empty(s));
    return s;
}

stack stack_pop(stack s) {
    assert(invrep(s) && !stack_is_empty(s));

    s -> elems[s -> size] = 0;
    s -> size--;

    assert(invrep(s));
    return s; 
}

unsigned int stack_size(stack s) {
    assert(invrep(s));

    unsigned int size = 0u;

    if (!stack_is_empty(s)) {
        size = s -> size;
    }

    return size;
}

stack_elem stack_top(stack s) {
    assert(invrep(s) && !stack_is_empty(s));

    return s -> elems[s -> size - 1];
}

stack_elem *stack_to_array(stack s) {
    assert(invrep(s));
    stack_elem *a = NULL;
    unsigned int size = stack_size(s);

    if (size > 0) {
        a = calloc(size, sizeof (stack_elem));

        for (unsigned int i = 0u; i < size; ++i) {
            a[i] = s -> elems[i];
        }
    }

    assert(invrep(s));
    return a;
}

stack stack_destroy(stack s) {
    assert(invrep(s));

    free(s -> elems);
    s -> elems = NULL;
    
    free(s);
    s = NULL;
    
    assert(s == NULL);
    return s;
}