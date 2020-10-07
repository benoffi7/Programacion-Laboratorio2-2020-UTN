#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dato;
    struct nodo2 * ste;
    struct nodo2 * ante;
} nodo2;

nodo2 * inicLista();

nodo2 * crearNodo(int dato);

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevoNodo);
// recursivo
nodo2 * buscarUltimoR(nodo2 * lista);

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo);

nodo2 * insertarNodo(nodo2 * lista, nodo2 * nuevoNodo);

nodo2 * borrarNodo(nodo2 * lista, int dato);

int verPrimero (nodo2 * lista);

nodo2 * borrarPrimero (nodo2 * lista);

void mostrarNodo(nodo2 * aux);

void recorrerYmostrar(nodo2 * lista);

nodo2 * cargarLista(nodo2 * lista);


#endif // LISTADOBLE_H_INCLUDED
