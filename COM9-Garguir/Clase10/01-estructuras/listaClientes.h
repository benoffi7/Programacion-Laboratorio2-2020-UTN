#ifndef LISTACLIENTES_H_INCLUDED
#define LISTACLIENTES_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
#include "cliente.h"

typedef struct {
    stCliente dato;
    struct nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stCliente dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void mostrarLista(nodo* lista);

#endif // LISTACLIENTES_H_INCLUDED
