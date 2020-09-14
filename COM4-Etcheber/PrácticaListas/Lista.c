#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>



nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int valor)
{
    nodo * nuevo = malloc(sizeof(nodo));
    nuevo->dato = valor;
    nuevo->sig = NULL;
    return nuevo;
}

nodo * agregarAlPrincipio (nodo * lista, nodo * nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo ->sig = lista;
        lista = nuevo;
    }
    return lista;
}

nodo * buscarUltimo (nodo * l)
{
    while (l->sig != NULL)
    {
        l = l->sig;
    }
    return l;
}

nodo * agregarAlFinal (nodo * lista, nodo * nuevo)
{
    nodo * ult=lista;
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        ult = buscarUltimo(lista);
        ult ->sig = nuevo;
    }
    return lista;
}


nodo * deArchivoALista (nodo * lista, char nombreArchivo [])
{
    FILE * archi = fopen (nombreArchivo,"rb");
    int aux;
    nodo * nuevo = inicLista();
    if(archi)
    {
        while (fread(&aux,sizeof(int),1,archi)>0)
        {
            nuevo = crearNodo(aux);
            lista = agregarAlFinal(lista,nuevo);
        }

        fclose(archi);
    }

    return lista;
}

void mostrarLista (nodo * lista)
{
    while (lista)
    {
        printf(" %d ",lista->dato);
        lista = lista ->sig;
    }
}

nodo * buscarPorValor (nodo * lista, int valor)
{
    while (lista != NULL && lista->dato != valor)
        lista = lista->sig;

    return lista;
}
