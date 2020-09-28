#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD
{
    int dato;
    struct nodoD* ant;
    struct nodoD* sig;
};

/*2. Crear una función recursiva que determine si una lista doblemente
vinculada es capicúa. (Después de ver recursividad)*/
/**Resolución lógica durante la clase, (chequear PNG adjuntado en la misma carpeta de git)**/

/*3. Dada una lista doblemente enlazada ordenada de enteros, eliminar el
nodo que se encuentra en el punto medio de la lista, si la cantidad de
nodos es par, eliminar el inmediatamente superior.*/

nodoD* buscarUltimo(nodoD* lista)
{
    while (lista->sig != NULL)
    {
        lista=lista->sig;
    }
    return lista;
}


void eliminarCentral(nodoD** lista)
{
    nodoD* ult;
    nodoD* pri;
    nodoD* aux;
    if (*lista)
    {
        ult=buscarUltimo(*lista);
        pri=*lista;
        if (pri->sig = NULL) // pri == ult
        {
            aux= *lista;
            (*lista) = NULL;
            free(aux);
        }
        else
        {
            while (pri != ult && ult->ant != pri) /// (pri!=ult || pri->sig != ult)
            {
                pri=pri->sig;
                ult=ult->ant;
            }
            aux=ult;
            if (pri != ult)
            {
                pri->sig = ult->sig;
                if (ult->sig != NULL)
                {
                    ult->sig->ant = pri;
                }
            }
            else
            {

                pri->ant->sig = ult->sig;
                ult->sig->ant = pri->ant;
            }

            free(aux);

        }

    }



}


int main()
{


    return 0;
}
