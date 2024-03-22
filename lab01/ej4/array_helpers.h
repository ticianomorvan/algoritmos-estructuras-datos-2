/*
    En la compilación, no pasamos este archivo puesto que no incluye código a ser traducido,
    sino que contiene información util para que el compilador pueda incluir las definiciones
    necesarias de las funciones aquí definidas que sí deben ser traducidas a código máquina.
    Además, el incluir estos archivos en la compilación puede provocar duplicados en las
    definiciones de las funciones involucradas y demás problemas a la hora de compilar el código.
*/

#include <stdbool.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath);

void array_dump(int array[], unsigned int length);

bool array_is_sorted(int array[], unsigned int length);