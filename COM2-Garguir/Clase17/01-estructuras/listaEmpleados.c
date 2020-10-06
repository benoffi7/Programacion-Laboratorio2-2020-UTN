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

void agregarAlPrincipioPD(nodo** lista, nodo* nuevoNodo){
    if((*lista)==NULL){
        (*lista) = nuevoNodo;
    }else{
        nuevoNodo->siguiente = (*lista);
        (*lista) = nuevoNodo;
    }
}

void agregarAlPrincipioPDPro(nodo** lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = (*lista);
    (*lista) = nuevoNodo;
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

void muestraListaRecursiva(nodo* lista){
    if(lista){
        muestraNodo(lista);
        muestraListaRecursiva(lista->siguiente);
    }
}

void muestraListaInvertidaRecursiva(nodo* lista){
    if(lista){
        muestraListaRecursiva(lista->siguiente);
        muestraNodo(lista);
    }
}

int sumaListaRecursiva(nodo* lista){
    int suma;
    if(!lista){
        suma=0;
    }else{
        suma=lista->dato.sueldo+sumaListaRecursiva(lista->siguiente);
    }
    return suma;
}

int sumaListaRecursivaPro(nodo* lista){
    int suma=0;
    if(lista){
        suma=lista->dato.sueldo+sumaListaRecursivaPro(lista->siguiente);
    }
    return suma;
}

int sumaListaRecursivaSuperPro(nodo* lista){
    return (lista)?lista->dato.sueldo+sumaListaRecursivaSuperPro(lista->siguiente):0;
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

nodo* borrarNodoListaApellido(nodo* lista, char apellido[]){
    nodo* seg;
    nodo* ante;
    if(lista && strcmp(lista->dato.persona.apellido, apellido)==0){
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else{
        seg = lista;
        while(seg && strcmp(seg->dato.persona.apellido,apellido)!=0){
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

int cuentaLista(nodo* lista){
    nodo* seg = lista;
    int cont=0;
    while(seg){                 /// while(seg!=NULL)
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}

nodo* eliminaUltimoNodo(nodo* lista){
    nodo* aux = lista;
    nodo* ante;
    while(aux->siguiente){
        ante = aux;
        aux = aux->siguiente;
    }
    free(aux);
    ante->siguiente = NULL;

    return lista;
}

nodo* eliminaPrimerNodo(nodo* lista){
    nodo* aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

void eliminaPrimerNodoPD(nodo** lista){
    nodo* aux = (*lista);
    (*lista) = (*lista)->siguiente;
    free(aux);
}

stEmpleado verPrimero(nodo* lista){
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
