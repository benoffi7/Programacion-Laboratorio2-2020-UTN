#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct nodo* sig;

} nodo;



nodo* crearNodo(int dato)
{
    nodo* nuevo= (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=NULL;

    return nuevo;
}

//void intercambio(int *a, int* b) //entendiendo punteros
//{
//    int c;
//    c = *b;
//    *b=*a;
//    *a=c;
//}

void insertarAlPrincipio(nodo** lista, int dato)
{
    nodo* nuevo = crearNodo(dato);
    nuevo->sig= (*lista);
    (*lista)= nuevo;
}

void insertarAlFinal(nodo** lista, int dato)
{
    nodo* nuevo = crearNodo(dato);
    nodo* seg;
    if ((*lista) == NULL)
    {
        (*lista)= nuevo;
    }
    else
    {
        seg=(*lista);
        while (seg->sig != NULL)
        {
            seg=seg->sig;
        }
        seg->sig=nuevo;
    }
}


void insertarEnOrden(nodo** lista, int dato)
{
    nodo* nuevo = crearNodo(dato);
    nodo* seg,ante;
    if ((*lista)==NULL)
    {
        (*lista)=nuevo;
    }
    else
    {
        if ((*lista)->dato > nuevo->dato)
        {
            nuevo->sig= (*lista);  ///insertarAlPrincipio(lista,dato);
            (*lista)=nuevo;
        }
        else
        {
            ante=(*lista);
            seg=(*lista)->sig;
            while (seg != NULL && seg->dato < nuevo->dato)
            {
                ante=seg;
                seg=seg->sig;
            }
            ante->sig=nuevo;
            nuevo->sig=seg;

        }

    }

}

void mostrar(nodo* lista)
{
    while (lista != NULL)
    {
        printf("%d ",lista->dato);
        lista=lista->sig;
    }
}

int busqueda(nodo* lista, int valor)
{
//    int busca=0;
    while (lista != NULL && lista->dato != valor)
    {
        lista=lista->sig;
    }
//    if (lista != NULL)
//    {
//        busca=1;
//    }
    return (lista!=NULL); // return busca;
}

int main()
{
    nodo* lista=NULL;
    insertarAlPrincipio(&lista,6);
    insertarAlPrincipio(&lista,7);
    insertarAlPrincipio(&lista,3);
    mostrar(lista);
    return 0;
}
