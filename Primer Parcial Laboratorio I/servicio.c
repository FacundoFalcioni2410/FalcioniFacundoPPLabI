#include "servicio.h"

void mostrarServicios(eServicios servicios[], int tamServicios)
{
    printf("\n\n~~~ SERVICIOS ~~~\n\n");
    printf("    ID       MARCA    PRECIO");

    for(int i = 0; i < tamServicios; i++)
    {
        printf("%4d      %10s      %.2f", servicios[i].id, servicios[i].nombreServicio, servicios[i].precio);
    }

    printf("\n\n");
}
