#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"


void mostrarRecursiva(nodo * lista);
int sumaRecursiva(nodo * lista);
nodo * cargaListaRandom(nodo * lista, int cant);

int main()
{
    printf("Hello world!\n");

    srand(time(NULL));

    nodo * lista=inicLista();

    lista= cargaListaRandom(lista, 20);

    mostrarRecursiva(lista);

    printf("\nLa suma es %d ", sumaRecursiva(lista));
    printf("\nLa suma es %d ", sumaRecursivaTernaria(lista));

    return 0;
}

nodo * cargaListaRandom(nodo * lista, int cant)
{
    for(int i=0; i<cant; i++)
    {
        lista=agregarEnOrden(lista, crearNodo(rand()%1000));
    }

    return lista;
}

void mostrarRecursiva(nodo * lista)
{
    if(lista!=NULL)
    {
        mostrar(lista);
        mostrarRecursiva(lista->siguiente);
    }

}

int sumaRecursiva(nodo * lista)
{
    int suma;
    if(!lista) ///cc
    {
        suma=0; /// st
    }
    else
    {
        /// ejemplo de lo que haciamos en arreglos recursivos
        /// suma=A[i] + sumaRecursivaDelArreglo(A, validos, i+1);
        suma=lista->dato+sumaRecursiva(lista->siguiente);
    }
    return suma;
}

/// codigo de Ana
int sumarLista(nodo* lista)
{
    int suma = 0;

    if(lista != NULL)
    {
        suma = lista->dato + sumarLista(lista->siguiente);
    }

    return suma;
}


int sumaRecursivaTernaria(nodo * lista)
{
    int suma=0;
    return (!lista) ? suma : lista->dato+sumaRecursivaTernaria(lista->siguiente);
}

/// codigo de samuel
void mostrarPosParRecursivo(nodo*lista)
{
    nodo*aux=lista;
    if(aux!=NULL)
    {
        printf("%i -",aux->dato);
        aux=aux->siguiente;
        if(aux!=NULL)
        {
            mostrarPosParRecursivo(aux->siguiente);
        }
    }
}

nodo* borrarNodoRec (nodo*lista, int dato)
{
    if (lista)
    {
        if (lista->dato == dato)
        {
            nodo* aux = lista;
            lista = lista->siguiente;
            free (aux);
        }
        else
        {
            lista->siguiente = borrarNodoRec (lista->siguiente,dato);
        }
    }
    return lista;
}

nodo * agregarEnOrdenRec(nodo * lista, nodo * nuevo)
{
    if(!lista)  /// lista==NULL
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato<lista->dato)
        {
            nuevo->siguiente=lista;
            lista=nuevo;
        }
        else
        {
            lista->siguiente=agregarEnOrdenRec(lista->siguiente, nuevo);
        }
    }

    return lista;
}

nodo * invertirListaRecursivoPosta (nodo*lista)
{
    nodo * aux;
    if(lista)
    {
        aux=lista;

        lista=lista->siguiente;

        aux->siguiente=NULL;

        lista=agregarFinal(invertirListaRecursivoPosta(lista), aux);
    }

    return lista;
}


nodo * invertirListaRecursivoFafafa(nodo*lista)
{
    nodo*aux;
    nodo*invertida=NULL;
    if(lista!=NULL)
    {
        aux=lista;


        aux->siguiente=NULL;///aislamiento social del primer nodo.

        invertida=agregarAlPrincipio(invertida,aux);
        ///falta la llamada recursiva.
    }
    return invertida;
}

