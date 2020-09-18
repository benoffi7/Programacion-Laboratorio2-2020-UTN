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
    for(int i=0;i<cant; i++)
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

int sumaRecursivaTernaria(nodo * lista)
{
    int suma=0;
    return (!lista) ? suma : lista->dato+sumaRecursivaTernaria(lista->siguiente);
}

