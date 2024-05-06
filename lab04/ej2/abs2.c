#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x >= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a = 0, res = 0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---
    a = -10;
    absolute(a, &res);
    printf("a = %i, res = %i\n", a, res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/*
    - El parámetro int *y de absolute() es de tipo out, porque no leemos su contenido sino que solo lo escribimos.
    - Al lenguaje C podemos traducir los tres tipos de parámetros del lenguaje de la materia, por ejemplo:
        - Parámetro in: int sum(int x, int y); // en esta función, x e y son parámetros in.
        - Parámetro out: void sum(int x, int y, int *res); // en este caso, x e y son parámetros in y res es un parámetro out.
        - Parámetro in/out: void sum(int x, int *y); // en este caso, x es parámetro in e y es parámetro in/out, suponiendo que guardamos el resultado en dicha variable. 
*/

