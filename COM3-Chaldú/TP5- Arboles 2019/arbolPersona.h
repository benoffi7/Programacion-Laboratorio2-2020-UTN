#ifndef ARBOLPERSONA_H_INCLUDED
#define ARBOLPERSONA_H_INCLUDED
#include <string.h>
#include "persona.h"

typedef struct {
     persona dato;
     struct nodoArbolPersona * izq;
     struct nodoArbolPersona * der;
} nodoArbolPersona;

/// funciones basicas
nodoArbolPersona * inicArbolPersona();
nodoArbolPersona * crearNodoArbolPersona(persona dato);
nodoArbolPersona * insertarPersona (nodoArbolPersona * arbol, persona dato);
void inorderPersona(nodoArbolPersona * arbol);
void preorderPersona(nodoArbolPersona * arbol);
void postorderPersona(nodoArbolPersona * arbol);
void mostrarNodoPersona(nodoArbolPersona * arbol);

nodoArbolPersona * buscarPersona(nodoArbolPersona * arbol, int legajo);
nodoArbolPersona * buscarEnpreorder(nodoArbolPersona * arbol, char nombre[]);

int alturaDelArbol (nodoArbolPersona* arbol);
int mayor (int izquierdo, int derecho);
int cuentaHojas(nodoArbolPersona * arbol);
int esHoja(nodoArbolPersona * arbol);
int contarNodosArbol(nodoArbolPersona * arbol);


nodoArbolPersona * crearArbol(nodoArbolPersona * arbol);


#endif // ARBOLPERSONA_H_INCLUDED
