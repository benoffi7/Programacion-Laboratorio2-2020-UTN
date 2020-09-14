#include "listaClientes.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stCliente dato){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo){
    if(lista==NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void muestraNodo(nodo *nodo){
    printf("\n--------------------------------------------------------------------------------------------");
    muestraUnCliente(nodo->dato);
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraNodo(seg);
        seg = seg->siguiente;
    }
}
