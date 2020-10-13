#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(int nro){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->dato = nro;
    nuevo->der = NULL;
    nuevo->izq = NULL;
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

void mostrarNodoArbol(nodoArbol* arbol){
    printf(" %d -", arbol->dato);
}

void preOrder(nodoArbol* arbol){
    if(arbol){
        mostrarNodoArbol(arbol);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(nodoArbol* arbol){
    if(arbol){
        inOrder(arbol->izq);
        mostrarNodoArbol(arbol);
        inOrder(arbol->der);
    }
}

void postOrder(nodoArbol* arbol){
    if(arbol){
        postOrder(arbol->izq);
        postOrder(arbol->der);
        mostrarNodoArbol(arbol);
    }
}
