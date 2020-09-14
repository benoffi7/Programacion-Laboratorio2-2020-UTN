#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valor;
    struct nodoLista * sig;
} nodoLista;

int main()
{
    nodoLista * l;
    l = inicLista();
    ////////
    nodo * nuevo = crearNodo(6);

    agregarAlPrincipio(&l,nuevo);


}

nodoLista * inicLista ()
{
    return NULL;
}

nodoLista * crearNodo (int dato)
{
    nodoLista * nuevo = (nodoLista*) malloc(sizeof(nodoLista));

    nuevo->valor = dato;
    nuevo->sig = NULL;

    return nuevo;
}

void agregarAlPrincipio (nodoLista ** plista, nodoLista * nuevo)
{
    if (plista !=NULL)
        nuevo->sig = *plista;

    *plista=nuevo;
}

int suma (int a, int b)
{
    int resultado = a +b ;

    a= 15;
    b= 16;

    return resultado;
}

nodo * buscarUltimo (nodoLista * l)
{
    while (l->sig != NULL)
    {
        l= l ->sig;
    }
    return l;
}

