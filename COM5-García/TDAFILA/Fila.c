#include "Fila.h"

void inicFila(Fila* F)
{
    (*F).pri=NULL;
    (*F).ult=NULL;
}

void poneFila(Fila* F, tipoDato dato)
{
    nodoD* nuevo = crearNodoD(dato);
    if ((*F).pri == NULL)
    {
        (*F).pri=nuevo;
        (*F).ult=nuevo;
    }
    else
    {
        (*F).ult->sig = nuevo;
         nuevo->ant= (*F).ult;
        (*F).ult=nuevo;

    }
}

tipoDato sacaFila(Fila* F)
{
    nodoD* aux;
    tipoDato dato;
    aux= (*F).pri;
    dato = aux->dato;
    if ((*F).pri == (*F).ult)
    {
        inicFila(F);
    }
    else
    {
        (*F).pri = (*F).pri->sig;
        (*F).pri->ant = NULL;
    }

    free(aux);

    return dato;
}

int Filavacia(Fila F)
{

  return (F.pri == NULL); //1 si es verdadero , 0 si es falso
}

tipoDato frente(Fila F)
{
    return F.pri->dato;
}


