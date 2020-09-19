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

    lista= cargaListaRandom(lista, 10);

    mostrarRecursiva(lista);

    return 0;
}


void mostrarRecursiva(nodo * lista)
{
    if(lista)
    {
        mostrar(lista);
        mostrarRecursiva(lista->siguiente);
    }
}

int sumaRecursiva(nodo * lista)
{
    int suma;
    if(lista==NULL) /// cc
    {
        suma=0; /// st
    }else
    {
        /// ejemplo de como lo haciamos con arreglos (para comparar)
        /// suma=A[i]+sumarecursivaArreglo(A, i+1, validos);

        suma=lista->dato+sumaRecursiva(lista->siguiente);

    }
    return suma;
}

nodo * cargaListaRandom(nodo * lista, int cant)
{
    for(int i=0;i<cant; i++)
    {
        lista=agregarEnOrden(lista, crearNodo(rand()%100));
    }

    return lista;
}
