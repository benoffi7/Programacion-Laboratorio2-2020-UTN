#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(int dato){
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoArbol* agregarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo){
    if(!arbol){
        arbol = nuevo;
    }else{
        if(nuevo->dato > arbol->dato){
            arbol->der = agregarNodoArbol(arbol->der, nuevo);
        }else{
            arbol->izq = agregarNodoArbol(arbol->izq, nuevo);
        }
    }
    return arbol;
}
