#include "listaEmpleados.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stEmpleado dato){
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

void mostrarNodo(nodo* aMostrar){
    mostrarUnEmpleado(aMostrar->dato);
}

void mostrarLista(nodo* lista){
    nodo* seg = lista;
    while(seg){                 /// while(seg!=NULL)
        mostrarNodo(seg);
        seg = seg->siguiente;
    }
}
