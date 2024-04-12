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


