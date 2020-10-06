#ifndef LISTACLIENTES_H_INCLUDED
#define LISTACLIENTES_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "cliente.h"

typedef struct _nodo{
    stCliente dato;
    struct _nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stCliente dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
nodo* agregarAlPrincipioPro(nodo *lista, nodo* nuevoNodo);
void agregarAlPrincipioPD(nodo **lista, nodo* nuevoNodo);
void muestraNodo(nodo *nodo);
void muestraLista(nodo* lista);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* borrarLista(nodo* lista);
nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo);
nodo* borrarNodo(nodo* lista, char apellido[]);
nodo* eliminarPrimerNodo(nodo* lista);
int cuentaLista(nodo* lista);
stCliente verPrimero(nodo* lista);

#endif // LISTACLIENTES_H_INCLUDED
