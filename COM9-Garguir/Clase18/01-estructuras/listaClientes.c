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

nodo* agregarAlPrincipioPro(nodo *lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = lista;
    lista=nuevoNodo;
    return lista;
}

void agregarAlPrincipioPD(nodo **lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = (*lista);
    (*lista)=nuevoNodo;
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

void muestaListaRecursiva(nodo* lista){
    if(lista){
        muestraNodo(lista->dato);
        muestraListaRecursiva(lista->siguiente);
    }
}

int sumaListaRecursiva(nodo* lista){
    int rta;
    if(!lista){
        rta=0;
    }else{
        rta=lista->dato.id+sumaListaRecursiva(lista->siguiente);
    }

    return rta;
}

int sumaListaRecursivaPro(nodo* lista){
    int rta=0;
    if(lista){
        rta=lista->dato.id+sumaListaRecursivaPro(lista->siguiente);
    }
    return rta;
}

int sumaListaRecursivaSuperPro(){
    return (lista)?lista->dato.id+sumaListaRecursivaSuperPro(lista->siguiente):0;
}



nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }

    return seg;
}

void buscarUltimoPD(nodo** lista){
    nodo* seg = (*lista);
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }
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

nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        if(atoi(nuevo->dato.persona.dni)<atoi(lista->dato.persona.dni)){
            lista=agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && (atoi(nuevo->dato.persona.dni)>atoi(seg->dato.persona.dni))){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo* borrarNodo(nodo* lista, char apellido[]){
    nodo* seg;
    nodo* ante;
    if(lista && strcmp(lista->dato.persona.apellido, apellido)==0){
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else{
        seg = lista;
        while(seg && strcmp(lista->dato.persona.apellido, apellido)!=0){
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo* eliminarUltimoNodo(nodo* lista){
    nodo* aux = lista;
    nodo* ante;
    while(aux->siguiente){    /// es igual a while(aux->siguiente != NULL)
        ante = aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}

nodo* eliminarPrimerNodo(nodo* lista){
    nodo* aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

int cuentaLista(nodo* lista){
    nodo* seg=lista;
    int cont=0;
    while(seg){
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}

stCliente verPrimero(nodo* lista){
    return lista->dato;
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
