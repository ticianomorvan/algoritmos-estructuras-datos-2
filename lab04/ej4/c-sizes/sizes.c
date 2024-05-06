#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",
           sizeof(messi.name),
           sizeof(messi.age),
           sizeof(messi.height),
           sizeof(messi)
    );

    printf("data_t-address: %p\n"
           "name-address  : %p\n"
           "age-address   : %p\n"
           "height-address: %p\n",
           (void *) &messi,
           (void *) &messi.name,
           (void *) &messi.age,
           (void *) &messi.height
    );

    return EXIT_SUCCESS;
}

/*
    El total de memoria que ocupa el objeto no es igual a la suma del espacio ocupado por sus campos
    y vemos que el tamaño que tenga "name" no dependerá del valor que se termine usando, sino que ya
    está reservado desde la declaración del tipo.

    Podemos ver que "name" está contenido en la "misma" dirección de memoria que el objecto en sí,
    lo que nos dice que el objecto como tal no está asignado a una posición particular en memoria,
    sino que empieza desde donde lo hace el primer campo de éste.

    Luego, vemos que los campos del objeto están almacenados contiguamente, distanciados por su
    tamaño en memoria. Por lo que vemos que como "name" toma aproximadamente 30 bytes de memoria y
    está a 32 bytes de distancia del campo "age", que le sigue.

    En esta última observación encontramos una coincidencia con el primer párrafo, puesto que
    la suma total de los campos debería ser igual a 40 bytes, que es lo que obtenemos al calcular
    el tamaño del objeto en sí, pero encontramos que el valor de la suma es en realidad 38 bytes.
    Estos dos bytes que nos faltan entre los espacios ocupados por la suma de los campos y
    el del objeto en sí mismo, se reflejan en las direcciones de memoria que utilizan.
*/

