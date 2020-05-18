#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

#include "auto.h"
#include "color.h"
#include "marca.h"
#include "utn.h"



void inicializarAutos(eAutos x[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        x[i].isEmpty = 1;
    }
}

int buscarEspacioLibreAutos(eAutos x[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAutoPorId(eAutos x[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 0 && x[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void mostrarAuto(eAutos x,eMarcas marca[], int tamMarca, eColores color[], int tamColor)
{
    char nombreMarca[21];
    char nombreColor[21];

    cargarDescripcionMarca(nombreMarca,x.idMarca,marca,tamMarca);
    cargarDescripcionColor(nombreColor,x.idColor,color,tamColor);
    printf("  %4d     %4d     %9s       %6s         %4d\n",x.id, x.patente, nombreMarca, nombreColor, x.anioFabricacion.anio);
}

void mostrarAutos(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor)
{
    int flag = 0;

    printf("                ~~~ LISTADO DE AUTOS~~~ \n\n");
    printf("   ID    PATENTE      MARCA          COLOR       MODELO\n\n");

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarAuto(x[i],marca, tamMarca, color, tamColor);
            flag = 1;
        }
    }

    if(!flag)
    {
        printf("No hay autos para mostrar");
    }

    printf("\n\n");
}

int altaAuto(eAutos x[], int tam, int proximoId, eMarcas marca[], int tamMarca, eColores color[], int tamColor)
{
    eAutos auxiliar;
    int indice;
    int todoOk = 0;

    system("cls");

    printf("~~~ ALTA AUTO ~~~ \n");

    indice = buscarEspacioLibreAutos(x, tam);

    if(indice == -1)
    {
        printf("Sistema completo\n");
    }
    else
    {
        auxiliar.id = proximoId;

        mostrarMarcas(marca,tamMarca);
        mostrarColores(color,tamColor);

        if((utn_getEntero(&auxiliar.patente,3,"Ingrese la patente del auto: ","ERROR. patente invalida (entre 100 y 999)\n",100,999)) == 0 && (utn_getEntero(&auxiliar.idMarca,3,"Ingrese la marca: ","ERROR. Ingrese ID de la marca\n",1000,1004)) == 0 && (utn_getEntero(&auxiliar.idColor,3,"Ingrese el color del auto: ","ERROR. Ingrese el ID del color\n",5000,5004)) == 0 && (utn_getEntero(&auxiliar.anioFabricacion.anio,3,"Ingrese el anio de fabricacion: ","ERROR. Anio invalido\n",1940,2020)) == 0)
        {
            todoOk = 1;

            auxiliar.isEmpty = 0;

            x[indice] = auxiliar;

            printf("\nAlta realizada con exito\n\n");
        }
        else
        {
            printf("Debe ingresar los datos correctamente. \n");
        }
    }

    return todoOk;
}

int menuModificarAuto()
{
    int opcion;

    printf("\n*** QUE DESEA MODIFICAR? ***\n\n");
    printf("1. COLOR\n");
    printf("2. MODELO\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ","ERROR. Opcion ingresada invalida",1,2);

    return opcion;
}

int modificarAuto(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor)
{
    int indice;
    int id;
    char confirma;
    int todoOk;

    system("cls");
    printf("~~~ MODIFICAR AUTO ~~~\n\n");
    utn_getEntero(&id,3,"Ingrese ID del auto a modificar:", "ERROR. ID no valido: ",1000,2000);

    indice = buscarAutoPorId(x,tam,id);

    if(indice == -1)
    {
        printf("\nNo hay ningun auto en el sistema con el ID ingresado");
    }
    else
    {
        printf("\n~~~ AUTO A MODIFICAR ~~~\n\n");
        printf("ID          PATENTE          MARCA     COLOR        MODELO   FECHA DE INGRESO\n\n");
        mostrarAuto(x[indice],marca, tamMarca,color, tamColor);
        printf("\n\n Desea modificar este auto? ");
        fflush(stdin);
        scanf("%c",&confirma);
            if(confirma=='s')
            {
                switch(menuModificarAuto())
                {
                case 1:
                    do
                    {
                        printf("Modificando color...\n");
                    }while((utn_getEntero(&x[indice].idColor,3,"\nIngrese el id del color: ", "ERROR. ID invalido.\n",5000,5004) == -1));
                    break;
                case 2:
                    do
                    {
                        printf("Modificando modelo...\n");

                    }while((utn_getEntero(&x[indice].anioFabricacion.anio,3,"Ingrese el anio: ","ERROR. Anio invalido\n",1950,2020)) == -1);
                    break;
                }
                todoOk = 1;
                printf("\nModificacion de auto realizada con exito\n");
            }
            else
            {
                printf("\nModificacion de auto cancelada\n");
            }
        }

    return todoOk;
}

int bajaAuto(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor)
{
    int indice;
    int id;
    char confirma;
    int todoOk;

    system("cls");
    printf("~~~ BAJA AUTO ~~~\n\n");
    utn_getEntero(&id,3,"Ingrese id del auto a dar de baja:", "ERROR. ID no valido: ",1000,2000);

    indice = buscarAutoPorId(x,tam,id);

    if(indice == -1)
    {
        printf("\nNo hay ningun auto con el ID ingresado");
    }
    else
    {
        printf("\n~~~ AUTO A ELIMINAR ~~~\n\n");
        printf("ID     PATENTE      MARCA     COLOR     MODELO   \n\n");
        mostrarAuto(x[indice],marca,tamMarca,color,tamColor);
        printf("\n\n Desea eliminar a este auto? ");
        fflush(stdin);
        scanf("%c",&confirma);
            if(confirma=='s')
            {
                x[indice].isEmpty = 1;
                todoOk = 1;
                printf("\n\nBaja de auto realizada con exito\n");
            }
            else
            {
                printf("\n\nBaja de auto cancelada\n");
            }
        }

    return todoOk;
}


void cargarDescripcionMarca(char descripcion[],int id, eMarcas marca[], int tamColor)
{
    for(int i = 0; i < tamColor; i++)
    {
        if(marca[i].id == id)
        {
            strcpy(descripcion, marca[i].descripcion);
        }
    }
}


void cargarDescripcionColor(char descripcion[],int id, eColores color[], int tamColor)
{
    for(int i = 0; i < tamColor; i++)
    {
        if(color[i].id == id)
        {
            strcpy(descripcion, color[i].nombreColor);
        }
    }
}
