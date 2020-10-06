#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "persona.h"

typedef struct _nodo2{
    stPersona dato;
    struct _nodo2 *anterior;
    struct _nodo2 *siguiente;
}nodo2;

nodo2* inicLista2();
nodo2* crearNodo2(stPersona dato);
nodo2* agregarAlPrincipio2(nodo2* lista, nodo2* nuevoNodo);
void muestraNodo2(nodo2* lista);
void muestraLista2(nodo2* lista);
stPersona verPrimero2(nodo2* lista);
nodo2* borrarPrimero2(nodo2* lista);
#endif // LISTA2_H_INCLUDED
