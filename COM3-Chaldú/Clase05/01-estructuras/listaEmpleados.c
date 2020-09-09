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
    while(seg->siguiente){   /// es lo mismo que esto while(seg->siguiente!=NULL)
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

nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        if(atoi(nuevo->dato.persona.dni) < atoi(lista->dato.persona.dni)){
            lista = agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && (atoi(nuevo->dato.persona.dni) > atoi(seg->dato.persona.dni))){
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
listaA: 5  7 8 9
listaB:
listaC: 1 2 3 4 5 7 8 9
nodo* intercalarListasId(nodo* listaA, nodo* listaB, nodo* listaC){
    nodo* aux;
    while(listaA && listaB){
        if(listaA->dato.id < listaB->dato.id){
            aux=listaA;
            listaA = listaA->siguiente; // avanzo uno en la lista A...
        }else{
            aux=listaB;
            listaB=listaB->siguiente; // avanzo uno en la lista b...
        }
        aux->siguiente=NULL;
        listaC=agregarFinal(listaC, aux); // agrego al final en lista C

    }

    if(listaA){
        listaC = agregarAlFinal(listaC, listaA);
    }
    if(listaB){
        listaC = agregarAlFinal(listaC, listaB);
    }

    return listaC;
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
