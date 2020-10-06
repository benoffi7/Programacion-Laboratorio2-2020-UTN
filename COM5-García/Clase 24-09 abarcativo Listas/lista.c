#include "lista.h"


nodo* crearNodo(NotaFinal dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=NULL;
    return nuevo;
}

void insertarEnOrden(nodo** lista, NotaFinal dato)
{
    nodo* nuevo = crearNodo(dato);
    nodo* seg,*ante;
    if (!*lista)
    {
        *lista = nuevo;
    }
    else
    {
        if (strcmp((*lista)->dato.asignatura,dato.asignatura) >= 0)
        {
            nuevo->sig = *lista;
            *lista = nuevo;
        }
        else
        {
            ante= *lista;
            seg= (*lista)->sig;
            while (seg != NULL && strcmp(seg->dato.asignatura,dato.asignatura) < 0)
            {
                ante=seg;
                seg=seg->sig;
            }
            ante->sig = nuevo;
            nuevo->sig = seg;
        }
    }
