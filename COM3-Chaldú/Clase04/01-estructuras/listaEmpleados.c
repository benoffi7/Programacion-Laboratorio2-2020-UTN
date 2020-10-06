#include "listaEmpleados.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stEmpleado dato){
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
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

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){   /// while(seg!=NULL)
        mostrarUnEmpleado(seg->dato);
        seg = seg->siguiente;
    }
}
