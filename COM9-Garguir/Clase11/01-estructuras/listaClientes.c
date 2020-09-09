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
    printf("\n nodo: %p - nodo->siguiente: %p",  nodo, nodo->siguiente);
    muestraUnCliente(nodo->dato);
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraNodo(seg);
        seg = seg->siguiente;
    }
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }

    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

nodo* borrarLista(nodo* lista){
    nodo* proximo;
    nodo* seg = lista;
    while(seg){   /// esto es igual a while(seg!=NULL)
        proximo = seg->siguiente;   /// tomo la direccion del siguiente nodo
        free(seg);              /// libero la memoria del nodo actual
        seg = proximo;          /// me muevo al siguiente nodo
    }
    return seg;
}

/**
   Pseudocodigo para recorrer una coleccion generica

   mientras (la-coleccion-tenga-datos) entonces
        utilizo el-dato-actual
        me-muevo-al-siguiente-dato
   fin-mientras

                            |   arreglo    |        pila      |    archivo          |     lista           |     arbol    |
la-coleccion-tenga-datos      i < validos     !pilavacia()        fread() > 0          lista!=NULL           ya lo veremos
el-dato-actual                  arreglo[i]         tope()         la variable leida     lista                ya lo veremos
me-muevo-al-siguiente-dato        i++            desapilar()      lo hace fread        lista=lista->sig      ya lo veremos


*/
