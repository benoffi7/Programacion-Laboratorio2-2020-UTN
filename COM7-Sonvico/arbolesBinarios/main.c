#include <stdio.h>
#include <stdlib.h>

typedef struct _nodoA
{
    int dato;
    struct _nodoA * izquierda;
    struct _nodoA * derecha;
} nodoArbol;

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol * nuevo = (nodoArbol *) malloc(sizeof(nodoArbol));

    nuevo->dato=dato;
    nuevo->izquierda=NULL;
    nuevo->derecha=NULL;

    return nuevo;
}

nodoArbol * buscarUnNodo(nodoArbol * a, int dato)
{
    nodoArbol * buscado=NULL;
    if(a)
    {
        if(a->dato==dato) /// procesa la raiz
        {
            buscado=a;
        }
    }
    else
    {
        if(dato>a->dato)   /// evalua la jeraquia
        {
            buscado=buscarUnNodo(a->derecha, dato);
        }
        else
        {
            buscado=buscarUnNodo(a->izquierda, dato);
        }
    }
    return buscado;
}

/// esta fn no agregará nodos con valor repetidos
nodoArbol * insertarEnOrdenDistintos(nodoArbol * a, nodoArbol * nuevo)
{
    if(a==NULL)
    {
        a=nuevo;
    }
    else
    {
        if(nuevo->dato<a->dato)
        {
            a->izquierda=insertarEnOrdenDistintos(a->izquierda, nuevo);
        }
        else if(nuevo->dato>a->dato)
        {
            a->derecha=insertarEnOrdenDistintos(a->derecha, nuevo);
        }
    }
    return a;
}

nodoArbol * insertarEnOrdenCreandoNodo(nodoArbol * a, int dato)
{
    if(a==NULL)
    {
        a=crearNodoArbol(dato);
    }
    else
    {
        if(dato<a->dato)
        {
            a->izquierda=insertarEnOrdenCreandoNodo(a->izquierda, dato);
        }
        else if(dato>a->dato)
        {
            a->derecha=insertarEnOrdenCreandoNodo(a->derecha, dato);
        }
    }
    return a;
}
void preOrden(nodoArbol * a)  /// R I D
{
    if(a!=NULL)
    {
        printf(" %d", a->dato);
        preOrden(a->izquierda);
        preOrden(a->derecha);
    }
}

void inOrden(nodoArbol * a)  /// I R D
{
    if(a!=NULL)
    {
        inOrden(a->izquierda);
        printf(" %d", a->dato);
        inOrden(a->derecha);
    }
}

void postOrden(nodoArbol * a)  ///  I D R
{
    if(a!=NULL)
    {
        postOrden(a->izquierda);
        postOrden(a->derecha);
        printf(" %d", a->dato);
    }
}

int sumarArbol(nodoArbol * arbol)
{
    int rta;
    if(!arbol)
    {
        rta=0;
    }
    else
    {
        rta=arbol->dato+sumarArbol(arbol->izquierda)+sumarArbol(arbol->derecha);
    }
    return rta;
}

int sumarArbolNodosPares(nodoArbol * arbol)
{
    int rta;
    if(!arbol)
    {
        rta=0;
    }
    else
    {
        if(arbol->dato%2==0)
        {
             rta=arbol->dato+sumarArbolNodosPares(arbol->izquierda)+sumarArbolNodosPares(arbol->derecha);
        }
        else
        {
             rta=sumarArbolNodosPares(arbol->izquierda)+sumarArbolNodosPares(arbol->derecha);
        }
    }
    return rta;
}


int main()
{
    printf("Hello arboles!\n");

    nodoArbol * arbolito=inicArbol();

    arbolito=insertarEnOrdenCreandoNodo(arbolito, 40);
    arbolito=insertarEnOrdenCreandoNodo(arbolito, 20);
    arbolito=insertarEnOrdenCreandoNodo(arbolito, 60);
    arbolito=insertarEnOrdenCreandoNodo(arbolito, 10);
    arbolito=insertarEnOrdenCreandoNodo(arbolito, 30);
    arbolito=insertarEnOrdenCreandoNodo(arbolito, 50);
    arbolito=insertarEnOrdenCreandoNodo(arbolito, 70);

    printf("\n\nMostrando pre order\n");
    preOrden(arbolito);

    printf("\n\nMostrando in order\n");
    inOrden(arbolito);

    printf("\n\nMostrando post order\n");
    postOrden(arbolito);

    return 0;
}
