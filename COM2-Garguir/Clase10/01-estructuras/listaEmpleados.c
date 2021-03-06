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

void muestraNodo(nodo* aMostrar){
    printf("\n Mi direccion: %p - Direccion del siguiente: %p", aMostrar, aMostrar->siguiente);
    mostrarUnEmpleado(aMostrar->dato);
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){                 /// while(seg!=NULL)
        muestraNodo(seg);
        seg = seg->siguiente;
    }
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente){
         seg = seg->siguiente;
    }
    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

nodo* agregarEnOrdenApellido(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        if(strcmp(nuevo->dato.persona.apellido, lista->dato.persona.apellido)<0){
            lista = agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && strcmp(nuevo->dato.persona.apellido, seg->dato.persona.apellido)>0){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo* borrarLista(nodo* lista){
    nodo* proximo;
    nodo* seg = lista;
    while(seg){
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
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
