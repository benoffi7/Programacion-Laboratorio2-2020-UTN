#include "lista.h"


nodo* crearNodo(int dato)
{
    nodo* nuevo= (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=NULL;
    return nuevo;
}

