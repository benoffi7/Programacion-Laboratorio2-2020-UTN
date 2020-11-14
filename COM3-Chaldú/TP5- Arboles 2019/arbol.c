#include "arbol.h"


nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));

    aux->dato=dato;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

/// 1. Hacer una función que sume el contenido de un árbol binario de números enteros.
/// Considerar que la suma del árbol será igual a la suma del dato de la Raíz más la
/// suma del subárbol izquierdo más la suma del subárbol derecho.

int sumarValoresArbol(nodoArbol * arbol)
{
    int rta;
    if(arbol==NULL)
    {
        rta=0;
    }
    else
    {
        rta=arbol->dato+sumarValoresArbol(arbol->izq)+sumarValoresArbol(arbol->der);
    }
    return rta;
}


nodoArbol * insertar (nodoArbol * arbol, int dato)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato>arbol->dato)
        {
            arbol->der=insertar(arbol->der, dato);
        }
        else
        {
            arbol->izq=insertar(arbol->izq, dato);
        }
    }
    return arbol;
}

void inorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        mostrarNodoInt(arbol);
        inorder(arbol->der);
    }
}

void preorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        mostrarNodoInt(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarNodoInt(arbol);
    }
}

void mostrarNodoInt(nodoArbol * arbol)
{
    /// como es dato primitivo, no hacemos una fn mostrar int
    printf("%d ", arbol->dato);
}

nodoArbol * buscar(nodoArbol * arbol, int dato)
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {
        if(dato == arbol->dato)
            rta = arbol;
        else if(dato>arbol->dato)
            rta = buscar(arbol->der, dato);
        else
            rta = buscar(arbol->izq, dato);
    }
    return rta;
}

/// funciones que dibujan el arbol (de enteros nada mas..)

int dibujarArbolLinea(struct nodoArbol * arbol, int esIzq, int inicia, int nivel, char s[20][255])
{
    char b[10];
    int ancho = 4; //es el ancho del nodo que dibujo
    int i;

    if (!arbol)
        return 0;

    sprintf(b, "(%d)", arbol->dato); // agrego valor de nodo a la matriz

    int izq  = dibujarArbolLinea(arbol->izq,  1, inicia, nivel + 1, s);
    int der = dibujarArbolLinea(arbol->der, 0, inicia + izq + ancho, nivel + 1, s);

    //dibujo nodo
    for (i = 0; i < ancho; i++)
        s[2 * nivel][inicia + izq + i] = b[i];

    //dibujo lineas .----+----.
    if (nivel && esIzq)
    {

        for (i = 0; i < ancho + der; i++)
            s[2 * nivel - 1][inicia + izq + ancho/2 + i] = '-';

        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia + izq + ancho + der + ancho/2] = '+';

    }
    else if (nivel && !esIzq)
    {

          for (i = 0; i < ancho + der; i++)
            s[2 * nivel - 1][inicia + izq + ancho/2 + i] = '-';

        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia + izq + ancho + der + ancho/2] = '+';
    }

    //Cerebros quemados everywere!!
    return izq + ancho + der;
}

int dibujarArbol(struct nodoArbol * arbol)
{
    char s[20][255];
    int i;
    //creo una matriz de char para hacer mi "dibujo"
    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    //Hago magia
    dibujarArbolLinea(arbol, 0, 0, 0, s);

    //Imprimo matris
    for (i = 0; i < 10; i++)
        printf("%s\n", s[i]);
}
