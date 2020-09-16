#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;
}nodoDoble;

nodoDoble* inicListaDoble()
{
    return NULL;
}

nodoDoble * crearNodoDoble(int dato)
{
    nodoDoble * aux = (nodoDoble *)malloc(sizeof(nodoDoble));

    aux->dato=dato;
    aux->siguiente=NULL;
    aux->anterior=NULL;

    return aux;
}

nodoDoble * agregarPpioDoble(nodoDoble * lista, nodoDoble * nuevo)
{
    if(lista==NULL)  /// !lista
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

/// tipear la fn agregar al fina y buscar ultimo

nodoDoble * agregaEnOrden(nodoDoble * lista, nodoDoble * nuevo)
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

            while(seg!=NULL&&seg->dato<nuevo->dato)
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL)
            {
                nodoDoble * ante=seg->anterior;

                ante->siguiente=nuevo;
                nuevo->anterior=ante;

                nuevo->siguiente=seg;
                seg->anterior=nuevo;
            }
            else
            {
                lista=agregaAlFinal(lista,nuevo);
            }
        }
    }
    return lista;
}

nodoDoble * borrarUnNodo(nodoDoble * lista, int dato)
{
    nodoDoble * aux;
    if(lista)
    {
        if(lista->dato==dato)
        {

            /// elimina primer nodo (la que hizo Tomas)
            aux=lista;
            lista=lista->siguiente;
            if(lista)
            {
                lista->anterior=NULL;
            }
            free(aux);
        }
        else
        {
            /// buscar el nodo a borrar (se puede hacer una fn)
            /// y redireccionar los enlaces segun caso






        }
    }

    return lista;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
