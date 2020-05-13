#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "servicio.h"
#include "auto.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaT;


typedef struct
{
    int id;
    int patente;
    int idServicio;
    int isEmpty;
    eFechaT fechaTrabajo;
}eTrabajos;

#endif // TRABAJO_H_INCLUDED

void inicializarTrabajos(eTrabajos x[], int tamTrabajo);

int buscarEspacioLibreTrabajos(eTrabajos x[], int tamTrabajo);

void mostrarTrabajo(eTrabajos x,eAutos autos, eServicios servicio[], int tamServicio);

void mostrarTrabajos(eTrabajos x[],int tamTrabajo, eAutos autos[], eServicios servicios[], int tamServicios);

int altaTrabajo(eAutos x[], int tam, eTrabajos trabajo[], int tamTrabajo, int proximoId, eMarcas marca[], int tamMarca, eColores color[], int tamColor, eServicios servicios[], int tamServicios);

void cargarDescripcionServicio(char descripcion[],int id, eServicios servicio[], int tamServicio);

void cargarDescripcionServicio(char descripcion[],int id, eServicios servicio[], int tamServicio);

int validateDate(int day, int month, int year);
