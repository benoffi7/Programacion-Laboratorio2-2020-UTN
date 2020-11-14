#include "arbolPersona.h"

nodoArbolPersona * inicArbolPersona()
{
    return NULL;
}

nodoArbolPersona * crearnodoArbolPersona(persona dato)
{
    nodoArbolPersona * aux = (nodoArbolPersona *) malloc(sizeof(nodoArbolPersona));

    aux->dato=dato;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}


/// 1. Hacer una funci�n que permita ingresar nuevos nodos manteniendo el �rbol ordenado (por legajo).

nodoArbolPersona * insertarPersona (nodoArbolPersona * arbol, persona dato)
{
    if(arbol==NULL)
    {
        arbol = crearnodoArbolPersona(dato);
    }
    else
    {
        if(dato.legajo>arbol->dato.legajo)
        {
            arbol->der=insertarPersona(arbol->der, dato);
        }
        else
        {
            arbol->izq=insertarPersona(arbol->izq, dato);
        }
    }
    return arbol;
}

/// 2. Hacer tres funciones, una funci�n que recorra
/// y muestre la informaci�n del �rbol en inorder, otra en posorder y otra en preorder.

void inorderPersona(nodoArbolPersona * arbol)
{
    if(arbol!=NULL)
    {
        inorderPersona(arbol->izq);
        mostrarNodoPersona(arbol);
        inorderPersona(arbol->der);
    }
}

void preorderPersona(nodoArbolPersona * arbol)
{
    if(arbol!=NULL)
    {
        mostrarNodoPersona(arbol);
        preorderPersona(arbol->izq);
        preorderPersona(arbol->der);
    }
}

void postorderPersona(nodoArbolPersona * arbol)
{
    if(arbol!=NULL)
    {
        postorderPersona(arbol->izq);
        postorderPersona(arbol->der);
        mostrarNodoPersona(arbol);
    }
}


void mostrarNodoPersona(nodoArbolPersona * arbol)
{
    mostrarPersona(arbol->dato);
}


/// fn 3 en el main (no tiene pertenencia a ningun tda)

/// 4. Hacer una funci�n que busque un nodo por legajo y lo retorne.

nodoArbolPersona * buscarPersona(nodoArbolPersona * arbol, int legajo)
{
    nodoArbolPersona * rta=NULL;
    if(arbol!=NULL)
    {
        if(legajo == arbol->dato.legajo)
            rta = arbol;
        else
        {
            if(legajo>arbol->dato.legajo)
                rta = buscarPersona(arbol->der, legajo);
            else
                rta = buscarPersona(arbol->izq, legajo);
        }
    }
    return rta;
}

/// 5. Hacer una funci�n que busque un nodo por nombre. Ojo!! El �rbol est� ordenado por legajo.


nodoArbolPersona * buscarEnpreorder(nodoArbolPersona * arbol, char nombre[])
{
    nodoArbolPersona * rta = NULL;
    if(arbol!=NULL)
    {
        if(strcmpi(arbol->dato.nombre, nombre)==0)
        {
            rta=arbol;
        }
        else
        {
            rta=buscarEnpreorder(arbol->izq, nombre);
            if(!rta)
                rta=buscarEnpreorder(arbol->der, nombre);
        }
    }
    return rta;
}

/// 6. Hacer una funci�n que cuente la cantidad de nodos del �rbol.

int contarNodosArbol(nodoArbolPersona * arbol)
{
    int rta;
    if(arbol==NULL)
    {
        rta=0;
    }
    else
    {
        rta=1+contarNodosArbol(arbol->izq)+contarNodosArbol(arbol->der);
    }
    return rta;
}

/// 7. Hacer una funci�n que cuente la cantidad de hojas del �rbol.
/// tenemos que evaluar si el nodo en que estoy parado es hoja o no

int esHoja(nodoArbolPersona * arbol)
{
    int rta=0;
    if(arbol)
    {
        if(arbol->izq==NULL&&arbol->der==NULL)
        {
            rta=1;
        }
    }
    return rta;
}

int cuentaHojas(nodoArbolPersona * arbol)
{
    int rta;
    if(arbol==NULL)
    {
        rta=0; /// st
    }
    else
    {
        if(esHoja(arbol))
        {
            rta=1; ///st
        }
        else
        {
            rta=cuentaHojas(arbol->izq)+cuentaHojas(arbol->der);
        }
    }
    return rta;
}

/// 8. Hacer una funci�n que cuente la cantidad de niveles que tiene el �rbol (pensar bastante).
/// para contar la cantidad de niveles, debemos considerar el lado con mas niveles del arbol
/// para eso hacemos una funcion auxiliar que me diga entre dos enteros quien es es mayor
/// esta funcion no es recursiva...

int mayor (int izquierdo, int derecho)
{
    int rta =0;
    if (izquierdo>derecho)
    {
        rta = izquierdo;
    }
    else
    {
        rta=derecho;
    }
    return rta;
}

int alturaDelArbol (nodoArbolPersona* arbol)
{
    int resp;
    if(arbol==NULL)
    {
        resp=0;
    }
    else
    {
        if(esHoja(arbol))
        {
            resp=1;
        }
        else
        {
            resp=1 + mayor( alturaDelArbol(arbol->izq), alturaDelArbol(arbol->der));
        }
    }
    return resp;
}

/// 9. Hacer una funci�n que borre un nodo de un �rbol.

/// es parte del tp final, queda como trabajo para el alumno

/// fn extra

nodoArbolPersona * crearArbol(nodoArbolPersona * arbol)
{
    arbol = insertarPersona(arbol, crearPersona(130, "pepe", 89));
    arbol = insertarPersona(arbol, crearPersona(10, "maria", 23));
    arbol = insertarPersona(arbol, crearPersona(34, "juan", 34));
    arbol = insertarPersona(arbol, crearPersona(294, "laura", 24));
    arbol = insertarPersona(arbol, crearPersona(179, "jose", 28));
    arbol = insertarPersona(arbol, crearPersona(50, "sergio", 55));
    arbol = insertarPersona(arbol, crearPersona(68, "gustavo", 34));
    arbol = insertarPersona(arbol, crearPersona(163, "soledad", 21));

    return arbol;
}
