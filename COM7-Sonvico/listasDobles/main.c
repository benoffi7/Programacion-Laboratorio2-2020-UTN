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

int capicuaRecursivo(nodoDoble * inicio, nodoDoble * fin)
{
    int capicua;
    if(inicio && fin)  /// inicio!=NULL && fin!=NULL
    {
        if(inicio->dato!=fin->dato) /// 1er cc
        {
            capicua=0; /// 1er st
        }
        else
        {
            if (inicio==fin || inicio==fin->siguiente)/// 2da cc
            {
                capicua=1; /// 2da st
            }
            else
            {
                capicua=capicuaRecursivo(inicio->siguiente, fin->anterior);
            }
        }
    }
    return capicua;
}

/// codificar fn buscarUltimo
nodoDoble * eliminaPuntoMedio(nodoDoble * lista)
{
    nodoDoble * aBorrar;

    if(lista)
    {
        if(lista->siguiente==NULL)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else
        {
            nodoDoble * inicio=lista;
            nodoDoble * fin=buscarUltimo(lista);

            while(inicio!=fin && fin->siguiente!=inicio)
            {
                inicio=inicio->siguiente;
                fin=fin->anterior;
            }

           aBorrar=inicio;

           nodoDoble * ante=aBorrar->anterior;

           ante->siguiente=aBorrar->siguiente;

           if(aBorrar->siguiente!=NULL)
           {
               nodoDoble * sig=aBorrar->siguiente;

               sig->anterior=ante;
           }
           free(aBorrar);
        }
    }
    return lista;
}




int main()
{
    printf("Hello world!\n");
    return 0;
}
