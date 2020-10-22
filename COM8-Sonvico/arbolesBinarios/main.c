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

nodoArbol * buscarNodo(nodoArbol * a, int dato)
{
    nodoArbol * rta=NULL;
    if(a !=NULL)
    {
        if(a->dato==dato)
        {
            rta=a;
        }
        else
        {
            if(dato<a->dato)
            {
                rta=buscarNodo(a->izquierda, dato);
            }
            else
            {
                rta=buscarNodo(a->derecha, dato);
            }
        }
    }
    return rta;
}

nodoArbol * insertaOrdenadoArbolDistintos(nodoArbol * a, nodoArbol * nuevo)
{
    if(a==NULL)
    {
        a=nuevo;
    }
    else
    {
        if(nuevo->dato<a->dato)
        {
            a->izquierda=insertaOrdenadoArbolDistintos(a->izquierda, nuevo);

        }
        else if(nuevo->dato>a->dato)
        {
            a->derecha=insertaOrdenadoArbolDistintos(a->derecha, nuevo);
        }
    }

    return a;
}

nodoArbol * insertaOrdenadoArbolCreandoNodo(nodoArbol * a, int dato)
{
    if(a==NULL)
    {
        a=crearNodoArbol(dato);
    }
    else
    {
        if(dato<a->dato)
        {
            a->izquierda=insertaOrdenadoArbolCreandoNodo(a->izquierda, dato);
        }
        else
        {
            a->derecha=insertaOrdenadoArbolCreandoNodo(a->derecha, dato);
        }
    }
    return a;
}

void preOrden (nodoArbol * a)  /// R I D
{
    if(a!=NULL)
    {
        printf(" %d", a->dato);
        preOrden(a->izquierda);
        preOrden(a->derecha);
    }
}

void inOrden (nodoArbol * a)  ///  I R D
{
    if(a!=NULL)
    {
        inOrden(a->izquierda);
        printf(" %d", a->dato);
        inOrden(a->derecha);
    }
}

void postOrden (nodoArbol * a)  ///  I D R
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

int sumarArbolValoresPares(nodoArbol * arbol)
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
            rta=arbol->dato+sumarArbolValoresPares(arbol->izquierda)+sumarArbolValoresPares(arbol->derecha);
        }
        else
        {
            rta=sumarArbolValoresPares(arbol->izquierda)+sumarArbolValoresPares(arbol->derecha);
        }
    }
    return rta;
}

/// este código lo hizo en parte Mati Mercado
/*
tree * searchLimb(tree * t, int legajo)
{

    tree * found = initTree();

    if(t)
    {
        if(t->data.legajo == legajo) /// proceso raiz
        {
            found = t;
        }
        else
        {
           if(legajo > t->data.legajo)
           {
               found = searchLimb(t->right, legajo);
           }
           else
           {
               found = searchLimb(t->left, legajo);
           }
        }
    }
    return found;
}
*/
/// estoy simulando la busqueda de un nombre

nodoArbol * buscarPorNombre(nodoArbol * arbol, int nombre)
{
    nodoArbol * buscado = NULL;
    if(arbol)
    {
        if(arbol->dato==nombre)  /// proceso raiz
        {
            buscado=arbol;
        }
        else
        {
            buscado=buscarPorNombre(arbol->izquierda, nombre);  /// me voy izq
            if (!buscado)
            {
                buscado=buscarPorNombre(arbol->derecha, nombre);  /// me voy der
            }
        }
    }
    return buscado;
}


int cantidadDeNodos(nodoArbol *arbol)
{
    int rta;
    if(!arbol)
    {
        rta=0;
    }
    else
    {
        rta=1+cantidadDeNodos(arbol->izquierda)+cantidadDeNodos(arbol->derecha);
    }
}

int nodeQuant(tree * t)
{
    int total = 0;

    if(t)
    {
        if(!t->left && !t->right)
        {
            total = 1;
        }
        else
        {
            if(t->left)
            {
                total = total + nodeQuant(t->left);
            }
            if(t->right)
            {
                total = total + nodeQuant(t->right);
            }
        }


    }

    return total;
}




int main()
{
    printf("Hello arboles!\n");

    nodoArbol * arbolito=inicArbol();

    arbolito=insertaOrdenadoArbolCreandoNodo(arbolito, 40);
    arbolito=insertaOrdenadoArbolCreandoNodo(arbolito, 20);
    arbolito=insertaOrdenadoArbolCreandoNodo(arbolito, 60);
    arbolito=insertaOrdenadoArbolCreandoNodo(arbolito, 10);
    arbolito=insertaOrdenadoArbolCreandoNodo(arbolito, 30);
    arbolito=insertaOrdenadoArbolCreandoNodo(arbolito, 50);
    arbolito=insertaOrdenadoArbolCreandoNodo(arbolito, 70);

    printf("\n\nMostrando pre orden\n");
    preOrden(arbolito);

    printf("\n\nMostrando in orden\n");
    inOrden(arbolito);


    printf("\n\nMostrando post orden\n");
    postOrden(arbolito);

    return 0;
}
