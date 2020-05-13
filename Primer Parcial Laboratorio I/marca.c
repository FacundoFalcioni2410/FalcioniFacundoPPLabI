#include "marca.h"

void mostrarMarcas(eMarcas marca[], int tamMarca)
{
    printf("\n\n~~~ MARCAS ~~~\n\n");
    printf(" ID       MARCA\n\n");

    for(int i = 0; i < tamMarca; i++)
    {
        printf("%4d       %10s\n", marca[i].id, marca[i].descripcion);
    }

    printf("\n\n");
}
