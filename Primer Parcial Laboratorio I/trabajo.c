#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"
#include "marca.h"
#include "auto.h"
#include "color.h"
#include "servicio.h"
#include "utn.h"


void inicializarTrabajos(eTrabajos x[], int tamTrabajo)
{
    for(int i = 0; i < tamTrabajo; i++)
    {
        x[i].isEmpty = 1;
    }
}

int buscarEspacioLibreTrabajos(eTrabajos x[], int tamTrabajo)
{
    int indice = -1;

    for(int i = 0; i < tamTrabajo; i++)
    {
        if(x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarTrabajo(eTrabajos x,eAutos autos, eServicios servicio[], int tamServicio)
{
    char nombreServicio[21];

    cargarDescripcionServicio(nombreServicio,x.idServicio,servicio,tamServicio);
    printf("%4d     %16d         %10s             %02d/%02d/%4d\n",x.id, autos.patente, nombreServicio, x.fechaTrabajo.dia,x.fechaTrabajo.mes,x.fechaTrabajo.anio);
}


void mostrarTrabajos(eTrabajos x[],int tamTrabajo, eAutos autos[], eServicios servicios[], int tamServicios)
{
    int flag = 0;

    system("cls");
    printf("                ~~~ LISTADO DE TRABAJOS~~~ \n\n");
    printf("  ID          PATENTE DEL AUTO       SERVICIO      FECHA DE TRABAJO\n\n");

    for(int i = 0; i < tamTrabajo; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarTrabajo(x[i],autos[i],servicios,tamServicios);
            flag = 1;
        }
    }

    if(!flag)
    {
        printf("No hay trabajos para mostrar");
    }
}



int altaTrabajo(eAutos x[], int tam, eTrabajos trabajo[], int tamTrabajo, int proximoId, eMarcas marca[], int tamMarca, eColores color[], int tamColor, eServicios servicios[], int tamServicios)
{
    eTrabajos auxiliar;
    int indice;
    int todoOk = 0;
    int idAuto;

    system("cls");

    printf("~~~ ALTA TRABAJO ~~~ \n\n");

    indice = buscarEspacioLibreTrabajos(trabajo, tamTrabajo);

    if(indice == -1)
    {
        printf("Sistema completo\n");
    }
    else
    {
        auxiliar.id = proximoId;

        mostrarAutos(x, tam,marca,tamMarca,color,tamColor);
        mostrarServicios(servicios,tamServicios);
        printf("\n\n");
        if((utn_getEntero(&idAuto,3,"Ingrese el ID de un auto mostrado arriba: ","ERROR. ID invalido\n",1000,10000) == 0))
        {
            if(buscarAutoPorId(x,tam,idAuto) != -1)
            {
                if(utn_getEntero(&auxiliar.idServicio,3,"Ingrese el servicio que desea realizar: ","ERROR. ID invalido\n",20000,20003) == 0)
                {
                    printf("Ingrese la fecha del trabajo: ");

                    utn_getEntero(&auxiliar.fechaTrabajo.dia,3,"Ingrese el dia: ","ERROR. Dia invalido\n",1,31);

                    utn_getEntero(&auxiliar.fechaTrabajo.mes,3,"Ingrese el mes: ","ERROR. Mes invalido\n",1,12);

                    utn_getEntero(&auxiliar.fechaTrabajo.anio,3,"Ingrese el anio: ","ERROR. Anio invalido\n",1900,2020);

                    if(validateDate(auxiliar.fechaTrabajo.dia, auxiliar.fechaTrabajo.mes, auxiliar.fechaTrabajo.anio))
                    {
                        todoOk = 1;

                        auxiliar.isEmpty = 0;

                        trabajo[indice] = auxiliar;
                    }
                    else
                    {
                        printf("\nRevise haber colocado la fecha correctamente\n");
                    }
                }

            }
            else
            {
                printf("No hay ningun auto registrado con ese ID");
            }
        }
    }
    return todoOk;
}

void cargarDescripcionServicio(char descripcion[],int id, eServicios servicio[], int tamServicio)
{
    for(int i = 0; i < tamServicio; i++)
    {
        if(servicio[i].id == id)
        {
            strcpy(descripcion, servicio[i].nombreServicio);
        }
    }
}


int validateDate(int day, int month, int year)
{
    int isLeap;
    int isValid;

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        isLeap = 1;
    }
    if(month == 2)
    {
        if (isLeap && day == 29)
        {
            isValid = 1;
        }
        else if (day > 28)
        {
            isValid = 0;
        }
        else
        {
            isValid = 1;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            isValid = 0;
        }
        else
        {
            isValid = 1;
        }
    }
    else if(day > 31)
    {
        isValid = 0;
    }
    else
    {
        isValid = 1;
    }

    return isValid;
}
