#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarcas;

#endif // MARCA_H_INCLUDED

void mostrarMarcas(eMarcas marca[], int tamMarca);
