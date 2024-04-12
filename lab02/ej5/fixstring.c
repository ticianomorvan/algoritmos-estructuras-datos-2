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
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return true;
        } else if (s1[i] > s2[i]) {
            return false;
        }

        i++;
    }

    if (s1[i] == '\0' && s2[i] != '\0') {
        return true;
    } else if (s1[i] != '\0' && s2[i] == '\0') {
        return false;
    }

    return true;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}


