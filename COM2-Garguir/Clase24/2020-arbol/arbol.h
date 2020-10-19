#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>

typedef struct nodoArbol{
    int dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(int dato);
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo);
nodoArbol* insertarSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo);

#endif // ARBOL_H_INCLUDED
