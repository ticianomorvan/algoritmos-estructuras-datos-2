#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0) {
        y = x;
    } else {
        y = -x;
    }
}

int main(void) {
    int a = 0, res = 0;
    a = -10;
    absolute(a, res);
    printf("a: %i, res: %i\n", a, res);

    return EXIT_SUCCESS;
}

// El resultado no coincide, ya que tenemos que "a = -10, res = 0", por lo que vemos que la traducción literal de los procedimientos no funciona.

