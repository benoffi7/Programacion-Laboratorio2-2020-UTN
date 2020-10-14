#include "arbolBinario.h"


nodoA* crearNodoA(tipoDato dato)
{
    nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
    nuevo->dato=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;

}
