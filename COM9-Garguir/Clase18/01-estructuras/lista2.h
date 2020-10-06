#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "cliente.h"

typedef struct _nodo2{
    stCliente dato;
    struct _nodo2 *anterior;
    struct _nodo2 *siguiente;
}nodo2;

nodo2* inicLista2();
nodo2* crearNodo2(stCliente dato);
nodo2* agregarAlPrincipio2(nodo2* lista, nodo2* nuevoNodo);
void muestraNodo2(nodo2* lista);
void muestraLista2(nodo2* lista);
stCliente verPrimero2(nodo2* lista);
nodo2* borrarPrimero2(nodo2* lista);
#endif // LISTA2_H_INCLUDED
