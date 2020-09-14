#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "Lista.h"

typedef struct
{
    nodo * datos;
}Pila;

void inicPila (Pila *);
int tope (Pila );
int pilaVacia (Pila);
void mostrar (Pila);
void apilar (Pila *, int);
int desapilar (Pila *);

#endif // PILA_H_INCLUDED
