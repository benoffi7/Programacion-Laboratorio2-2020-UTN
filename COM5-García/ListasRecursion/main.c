#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Insertar un nodo en una lista en forma recursiva (manteniendo el orden de forma creciente).

//forma iterativa
void insertarEnLista(nodo** lista, int dato)
{
    nodo* nuevo= crearNodo(dato);
    nodo*seg,*ante;
    if (*lista != NULL && lista->dato > dato)
    {
        nuevo->sig=*lista;
        (*lista)=nuevo;
    }
    else
    {
        ante=*lista;
        seg=(*lista)->sig;
        while (seg && seg->dato < dato)
        {
            ante=seg;
            seg=seg->sig;
        }
        nuevo->sig=seg;
        ante->sig=nuevo;
    }
}
//forma recursiva
void insertarEnOrden(nodo** lista, int dato)
{
    nodo* nuevo;
    if (*lista== NULL)
    {
        *lista = crearNodo(dato);
    }
    else
    {
        if ((*lista)->dato > dato)
        {
            nuevo = crearNodo(dato);
            nuevo->sig= *lista;

            *lista=nuevo;
        }
        else
        {
            insertarEnOrden(&(*lista)->sig,dato) //debo enviar dirección del campo "sig", que contiene el valor
                                                //que corresponde al nodo siguiente de la lista.
        }
    }

}


int main()
{
    nodo* lista=NULL;
    insertarEnOrden(&lista,4);
    insertarEnOrden(&lista,5);
    insertarEnOrden(&lista,3);



    return 0;
}
