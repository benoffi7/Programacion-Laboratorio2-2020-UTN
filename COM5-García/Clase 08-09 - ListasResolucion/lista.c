#include "lista.h"


void insertarNodoAlFinal(nodo** lista, nodo* nuevo)
{
    nodo *seg=*lista;

    if (*lista)
    {
        while (seg->sig != NULL)
        {
            seg=seg->sig;
        }
        seg->sig=nuevo;
    }
    else
        *lista=nuevo;
}
