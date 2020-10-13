#include "lista2.h"

nodo2* inicLista2(){
    return NULL;
}

nodo2* crearNodo2(stCliente dato){
    nodo2* nuevo = (nodo2*) malloc(sizeof(nodo2));

    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo2* agregarAlPrincipio2(nodo2* lista, nodo2* nuevo){
    nuevo->siguiente = lista;
    if(lista){
        lista->anterior=nuevo;
    }

    return nuevo;
}

nodo2* agregarPpio(nodo2* lista, nodo2* nuevo){
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        lista->anterior = nuevo;
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

nodo2* buscarUltimo2(nodo2* lista){
    nodo2* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }

    return seg;
}

nodo2* agregarAlFinal2(nodo2* lista, nodo2* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo2* ultimo = buscarUltimo2(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

void muestraNodo2(nodo2* lista){
    printf("\n nodo: %p - nodo->anterior: %p - nodo->siguiente: %p",  lista, lista->anterior, lista->siguiente);
    muestraUnCliente(lista->dato);
}

void muestraLista2(nodo2* lista){
    nodo2* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraNodo2(seg);
        seg = seg->siguiente;
    }
}

stCliente verPrimero2(nodo2* lista){
    return lista->dato;
}

nodo2* borrarPrimero2(nodo2* lista){
    if(lista!=NULL){
        nodo2 * aborrar=lista;
        lista=lista->siguiente;
        if(lista!=NULL){
            lista->anterior=NULL;
            free(aborrar);
        }
    }
    return lista;
}

