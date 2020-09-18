#include "lista2.h"

nodo2* inicLista2(){
    return NULL;
}

nodo2* crearNodo2(stEmpleado e){
    nodo2* nuevo = (nodo2*) malloc(sizeof(nodo2));
    nuevo->dato = e;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo2* agregarAlPrincipio2(nodo2* lista, nodo2* nuevo){
    nuevo->siguiente = lista;
    if(lista){
        lista->anterior = nuevo;
    }

    return nuevo;
}

nodo2* buscarUltimo2(nodo2* lista){
    nodo2* seg = lista;
    while(seg->siguiente){  /// esto es igual a while(seg->siguiente != NULL)
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
    mostrarUnEmpleado(lista->dato);
}

void muestraLista2(nodo2* lista){
    nodo2* seg = lista;
    while(seg){
        muestraNodo2(seg);
        seg = seg->siguiente;
    }
}
