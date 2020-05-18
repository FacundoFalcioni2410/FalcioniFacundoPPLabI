#include "marca.h"

void mostrarMarcas(eMarcas marca[], int tamMarca)
{
    printf("\n  ~~~ MARCAS ~~~\n");
    printf(" ID           MARCA\n");

    for(int i = 0; i < tamMarca; i++)
    {
        printf("%4d       %10s\n", marca[i].id, marca[i].descripcion);
    }
}
