#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "marca.h"
#include "color.h"

typedef struct
{
    int anio;
}eFecha;


typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int isEmpty;
    eFecha anioFabricacion;
}eAutos;

#endif // AUTO_H_INCLUDED

void inicializarAutos(eAutos x[], int tam);

int buscarEspacioLibreAutos(eAutos x[], int tam);

int buscarAutoPorId(eAutos x[], int tam, int id);

void mostrarAuto(eAutos x,eMarcas marca[], int tamMarca, eColores color[], int tamColor);

void mostrarAutos(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor);

int menuMarcas();

int altaAuto(eAutos x[], int tam, int proximoId, eMarcas marca[], int tamMarca, eColores color[], int tamColor);

int menuModificarAuto();

int modificarAuto(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor);

int bajaAuto(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor);

void cargarDescripcionMarca(char descripcion[],int id, eMarcas marca[], int tamColor);

void cargarDescripcionColor(char descripcion[],int id, eColores color[], int tamColor);


