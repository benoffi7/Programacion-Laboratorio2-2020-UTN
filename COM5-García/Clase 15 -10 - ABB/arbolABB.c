#include "arbolABB.h"


nodoA* crearNodoArbol(tipoDato);


void insertarABB(nodoA** arbol, tipoDato dato)
{
    if (*A != NULL)
    {
        if ((*A)->dato > dato)
        {
            insertarABB(&(*A)->izq,dato);
        }
        else
        {
            insertar(&(*A)->der,dato);
        }
    }
    else
    {
        *A = crearNodoArbol(dato);
    }

}

///arbol llega con datos
int minimoABB(nodoA* arbol)
{
    if (A)
    {
        if (A->izq != NULL)
        {
            return minimoABB(arbol->izq);
        }
        else
        {
            return arbol->dato;
        }

    }

}

///arbol llega con datos
int maximoABB(nodoA* arbol)
{
    if (arbol)
    {
        if(arbol->der != NULL)
        {
            return maximoABB(arbol->der);
        }
        else
        {
            return arbol->dato;
        }
    }

}

void eliminarGrado1uHoja(nodoA** arbol,tipoDato dato)
{
    nodoA* aux;
    if (*arbol)
    {
        if ((*arbol)->dato == dato)
        {
            if ((*arbol)->der != NULL && (*arbol)->izq == NULL)
            {
                aux = *arbol;
                (*arbol) = (*arbol)->der;
                free(aux);
            }
            else
            {
                if ((*arbol)->der == NULL && (*arbol)->izq != NULL)
                {
                    aux = *arbol;
                    (*arbol) = (*arbol)->izq;
                    free(aux);
                }
                else
                {
                    if ((*arbol)->der == NULL && (*arbol)->izq == NULL)
                    {
                        free(*arbol);
                        *arbol=NULL;
                    }
                }
            }

        }
        else
        {
            if ((*arbol)->dato < dato)
            {
                eliminarGrado1uHoja(&(*arbol)->der,dato);
            }
            else
            {
                eliminarGrado1uHoja(&(*arbol)->izq,dato);
            }
        }

    }


}






