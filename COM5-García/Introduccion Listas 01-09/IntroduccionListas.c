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
    nodo* ante,*seg;
    if ((*lista)==NULL)
    {
        (*lista)=nuevo;
    }
    else
    {
        if ((*lista)->dato > nuevo->dato)
        {
            nuevo->sig= (*lista);
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
    //int busca=0;
    while (lista != NULL && lista->dato != valor)
    {
        lista=lista->sig;
    }
//    if (lista != NULL)
//    {
//        busca=1;
//    }
    return (lista!=NULL);
}

//valor=5
//1 3 4 6 7
int busquedaOrdenada(nodo* lista, int valor)
{
    int busca=0;
    while (lista != NULL && lista->dato < valor)
    {
        lista=lista->sig;
    }
    if (lista != NULL && lista->valor==valor)
        busca=1;

    return busca;

//return (lista != NULL && lista->dato==valor) // ->utilizando operadores relacionales devuelve el mismo resultado

}


void cargarDatos(nodo** lista)
{
    FILE* fp; //...
    //..mientras...leo de archivo un dato
    //..
    insertarEnOrden(lista,dato);
    //...itero
}



//eliminar de una lista NO ordenada
void eliminar(nodo** lista,int dato)
{
    nodo* aux;
    nodo* ante;
    nodo* seg;
    if((*lista)!=NULL && (*lista)->dato==dato)
    {
        aux=(*lista);
        (*lista)=(*lista)->sig;
        free(aux);
    }
    else
    {
        ante=(*lista);
        seg=(*lista)->sig;
        while (seg != NULL && seg->dato != dato)
        {
            ante=seg;
            seg=seg->sig;
        }
        if (seg != NULL) //if (seg)  -> es lo mismo que decir: si tengo datos en seg, entro en el if
        {
            ante->sig = seg->sig;
            aux=seg;
            free(aux);
        }
    }
}


int main()
{
    nodo* lista=NULL;
    insertarAlPrincipio(&lista,6);
    insertarAlPrincipio(&lista,7);
    insertarAlPrincipio(&lista,3);
    insertarEnOrden(&lista,8);
    insertarEnOrden(&lista,8);
    //cargarDatos(&lista);
    mostrar(lista);
    return 0;
}
