#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void mostrarServicios(eServicios servicios[], int tamServicios)
{
    printf("~~~ SERVICIOS ~~~\n\n");
    printf("    ID       MARCA    PRECIO\n");

    for(int i = 0; i < tamServicios; i++)
    {
        printf("%4d      %10s      %.2f\n", servicios[i].id, servicios[i].nombreServicio, servicios[i].precio);
    }

    printf("\n");
}
