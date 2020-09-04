#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
#include "empleados.h"

typedef struct{
    stEmpleado dato;
    struct nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void muestraLista(nodo* lista);

#endif // LISTAEMPLEADOS_H_INCLUDED
