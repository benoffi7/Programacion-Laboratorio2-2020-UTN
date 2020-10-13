#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

typedef struct nodoArbol{
    stCliente dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stCliente c);
nodoArbol* agregarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo);
void mostrarNodoArbol(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);


#endif // ARBOL_H_INCLUDED
