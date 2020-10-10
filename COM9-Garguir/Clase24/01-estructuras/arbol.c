#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stCliente c){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->dato = c;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

nodoArbol* agregarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo){
    if(!arbol){
        arbol = nuevo;
    }else{
        if(atoi(nuevo->dato.persona.dni) > atoi(arbol->dato.persona.dni)){
            arbol->der = agregarNodoArbol(arbol->der, nuevo);
        }else{
            arbol->izq = agregarNodoArbol(arbol->izq, nuevo);
        }
    }

    return arbol;
}

void mostrarNodoArbol(nodoArbol* arbol){
    muestraUnCliente(arbol->dato);
}

void inOrder(nodoArbol* arbol){
    if(arbol){
        inOrder(arbol->izq);
        mostrarNodoArbol(arbol);
        inOrder(arbol->der);
    }
}

