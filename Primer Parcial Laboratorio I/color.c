#include "color.h"

void mostrarColores(eColores color[], int tamColor)
{
    printf("\n  ~~~ COLORES ~~~\n");
    printf(" ID            COLOR\n");

    for(int i = 0; i < tamColor; i++)
    {
        printf("%4d      %10s\n", color[i].id, color[i].nombreColor);
    }

    printf("\n");
}
