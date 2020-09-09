#include "Pila.h"

/// Pila == nodo*

nodo* crearNodo(int dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=NULL;
    return nuevo;
}

void inicPila(Pila* P)
{
    *P = NULL;
}

void apilar(Pila* P,int dato)
{
    nodo* nuevo = crearNodo(dato);
    nuevo->sig = *P;
    *P = nuevo;
}
2 3 4
int desapilar(Pila* P)
{
    nodo* aux;
    int dato;
    if (*P != NULL)
    {
        aux = *P;
        *P = (*P)->sig;
        dato=aux->dato;
        free(aux);
    }
    return dato;

}

int pilavacia(Pila P)
{
    int ver=0;
    if (P == NULL)
        ver=1;

    return ver;

//    return (P==NULL);
}

int tope(Pila P)
{
    return P->dato;

}
// TOPE --- 1 2 3 4 5 8 16 ---BASE

void mostrar(Pila P);
{
    printf("TOPE----")
    while (P)
    {
        printf("%d ", P->dato);
        P=P->sig;
    }
    printf("---BASE");

}
