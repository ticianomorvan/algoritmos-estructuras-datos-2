#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;

    for (int i = 0; i < FIXSTRING_MAX; i++) {
        if (s[i] == '\0') {
            break;
        }

        length += 1;
    }

    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int s1_length, s2_length;
    bool is_equal = false;

    s1_length = fstring_length(s1);
    s2_length = fstring_length(s2);

    for (unsigned int i = 0; (i < s1_length) && (s1_length == s2_length); i++) {
        is_equal = s1[i] == s2[i];
    }

    return is_equal;
}

/*
    NOTA: si dos palabras tienen un segmento inicial idéntico,
    aunque la segunda es más larga que la primera, dará verdadero.
    Ejemplo: 'automovil' "resulta ser" menor o igual a 'auto', cuando debería ser mayor. 
*/
bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool is_less_or_equal = false;
    unsigned int smaller_length, s1_length, s2_length;

    s1_length = fstring_length(s1);
    s2_length = fstring_length(s2);
    smaller_length = s1_length >= s2_length ? s2_length : s1_length;

    for (unsigned int i = 0; i <= smaller_length; i++) {
        if (s1[i] > s2[i]) {
            break;
        }

        is_less_or_equal = true;
    } 

    return is_less_or_equal;
}

