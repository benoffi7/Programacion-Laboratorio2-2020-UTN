#ifndef ARBOLPERSONA_H_INCLUDED
#define ARBOLPERSONA_H_INCLUDED

#include "persona.h"

typedef struct
{
    persona p;
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;

///Funciones arbol
nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (persona p);
nodoArbol * insertarEnArbol (nodoArbol * arbol, nodoArbol * nuevo);
void mostrarArbol (nodoArbol * arbol);
nodoArbol * borrarNodo (nodoArbol * arbol, int dni);

#endif // ARBOLPERSONA_H_INCLUDED
