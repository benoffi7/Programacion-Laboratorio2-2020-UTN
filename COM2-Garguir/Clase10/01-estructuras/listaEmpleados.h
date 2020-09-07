#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
#include "empleados.h"

typedef struct _nodo{
    stEmpleado dato;
    struct _nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void muestraNodo(nodo* aMostrar);
void muestraLista(nodo* lista);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenApellido(nodo* lista, nodo* nuevo);
nodo* borrarLista(nodo* lista);

#endif // LISTAEMPLEADOS_H_INCLUDED
