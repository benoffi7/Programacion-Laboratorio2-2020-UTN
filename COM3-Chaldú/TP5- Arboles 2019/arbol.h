#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/// estructura de datos
typedef struct nodoArbol
{
    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

/// funciones basicas
nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * insertar (nodoArbol * arbol, int dato);
void inorder(nodoArbol * arbol);
void preorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
void mostrarNodoInt(nodoArbol * arbol);
nodoArbol * buscar(nodoArbol * arbol, int dato);

/// funciones extras
int sumarValoresArbol(nodoArbol * arbol);

/// funciones que dibujan el arbol (de enteros nada mas..)
int dibujarArbolLinea(nodoArbol * arbol, int esIzq, int inicia, int nivel, char s[20][255]);
int dibujarArbol(nodoArbol * arbol);

#endif // ARBOL_H_INCLUDED
