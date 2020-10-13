#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoArbol{
    int dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(int nro);
nodoArbol* agregarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo);
void mostrarNodoArbol(nodoArbol* arbol);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);

#endif // ARBOL_H_INCLUDED
