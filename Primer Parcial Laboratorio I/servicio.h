#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char nombreServicio[25];
    float precio;
}eServicios;

#endif // SERVICIO_H_INCLUDED

void mostrarServicios(eServicios servicios[], int tamServicios);
