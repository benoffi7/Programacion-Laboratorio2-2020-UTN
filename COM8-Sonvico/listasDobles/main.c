#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;
} nodoDoble;

nodoDoble * inicListaDoble()
{
    return NULL;
}

nodoDoble * crearNodoDoble(int dato)
{
    nodoDoble * aux= (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato=dato;

    aux->siguiente=NULL;

    aux->anterior=NULL;

    return aux;
}

nodoDoble * agregarPpioDoble(nodoDoble * lista, nodoDoble * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;

        lista->anterior=nuevo;

        lista=nuevo;
    }

    return lista;
}

nodoDoble * agregaFinalDoble(nodoDoble * lista, nodoDoble * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodoDoble * ultimo=lista;

        while(ultimo->siguiente!=NULL)
        {
            ultimo=ultimo->siguiente;
        }

        ultimo->siguiente=nuevo;

        nuevo->anterior=ultimo;
    }

    return lista;
}

nodoDoble * agregarEnOrdenDoble(nodoDoble * lista, nodoDoble * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato<lista->dato)
        {
            lista=agregarPpioDoble(lista, nuevo);
        }
        else
        {
            nodoDoble * seg=lista->siguiente;

            while(seg!=NULL && seg->dato<nuevo->dato)
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL) /// estoy agregando al medio de dos nodos
            {
                nodoDoble * ante=seg->anterior;

                /// esto es igual a lista simple
                ante->siguiente=nuevo;
                nuevo->siguiente=seg;

                /// nuevos enlaces de la lista doble
                nuevo->anterior=ante;
                seg->anterior=nuevo;
            }
            else /// tengo que agregar al final
            {
                lista=agregaFinalDoble(lista, nuevo);
            }
        }
    }
    return lista;
}


int main()
{
    printf("Hello world!\n");

    nodoDoble * listaDoble=inicListaDoble();


    return 0;
}
