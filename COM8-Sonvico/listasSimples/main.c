#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"

typedef struct _nodo
{
    persona dato;
    struct _nodo * siguiente;
} nodo;

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato= dato;
    aux->siguiente = NULL;
    return aux;
}

nodo * agregarPpio(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;

        lista = nuevoNodo;
    }
    return lista;
}

nodo * agregarPpioOtro(nodo * lista, nodo * nuevoNodo)
{

    nuevoNodo->siguiente = lista;

    return nuevoNodo;
}



void agregarPpioPunteroDoble(nodo ** plista, nodo * nuevo)
{
    if(*plista!=NULL)
    {
        *plista=nuevo;
    }
    else
    {
        nuevo->siguiente = *plista;
        *plista = nuevo;
    }
}


void mostrarNodo(nodo * aux)
{
    printf("\n %p ----->siguiente: %p\n ", aux, aux->siguiente);
    mostrarPersona(aux->dato);
}

void recorrerYmostrar(nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
}

///#define Lista nodo *

void recorrerYmostrarConPunteroDoble(nodo * * plista)
{
    nodo * seg = *plista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo * buscarNodo( nodo * lista, char nombre[20])
///busca un nodo por nombre y retorna su posici¢n de memoria
///si no lo encuentra retorna NULL.
{
    nodo * seg;		//apunta al nodo de la lista que est  siendo leido.
    seg = lista;  	//con esto evito cambiar el valor de la variable
    //lista, que contiene un puntero al primer nodo de la
    //lista vinculada
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 ))
        //busco mientras me quede lista por recorrer y no haya encontrado el nombre
    {
        seg=seg->siguiente;	//avanzo hacia el siguiente nodo.
    }
    //en este punto puede ha fallado alguna de las dos condiciones del while
    //si fallo la primera es debido a que no encontro lo que buscaba (seg es NULL)
    //si fall la segunda es debido a que se encontro el nodo buscado.
    return seg;
}

nodo * borrarNodo(nodo * lista, char nombre[20])
{
    nodo * seg;
    nodo * ante;	//apunta al nodo anterior que seg.

    if(lista!=NULL)
    {
        if(strcmp(nombre, lista->dato.nombre)==0 )
        {
            nodo * aux = lista;
            lista = lista->siguiente; //salteo el primer nodo.
            free(aux); //elimino el primer nodo.
        }
        else
        {
            seg = lista;
            while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 ))
            {
                ante = seg;	//adelanto una posicion la var ante.
                seg = seg->siguiente; //avanzo al siguiente nodo.
            }

            if( seg!= NULL)
            {
                ante->siguiente = seg->siguiente; //salteo el nodo que quiero eliminar.
                free(seg); //elimino el nodo.
            }
        }
    }
    return lista;
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(lista->dato.edad>nuevoNodo->dato.edad)
        {
            lista=agregarPpio(lista, nuevoNodo);
        }
        else
        {
            nodo * seg = lista->siguiente;
            nodo * ante= lista;

            while(seg!=NULL && seg->dato.edad<nuevoNodo->dato.edad)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            ante->siguiente=nuevoNodo;

            nuevoNodo->siguiente=seg;
        }
    }
    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;  //tomo la dir del siguiente.
        free(seg);                 //borro el actual.
        seg = proximo;             //actualizo el actual con la dir del
        //siguiente, para avanzar.
    }
    return seg; // retorna NULL a la variable lista del main()
}

nodo * subprogramaIngresaPersonaEnLista(nodo * lista, persona p)
{
    lista = agregarEnOrden(lista, crearNodo(p));

    return lista;
}

nodo * cargarListaDesdeArchivo(char nombre[], nodo * lista)
{
    FILE * archi =fopen(nombre, "rb");
    persona aux;

    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(persona), 1, archi)>0)
        {
            lista=subprogramaIngresaPersonaEnLista(lista, aux);
        }

        fclose(archi);
    }
    return lista;
}

nodo * desvincularPrimero(nodo * * plista)
{
    nodo * primero=NULL;

    if(*plista!=NULL)
    {
        primero=*plista;

        *plista=(*plista)->siguiente;

        primero->siguiente=NULL;
    }

    return primero;
}


/// funcion de ejemplo vista en clases

void punteroDoble(nodo * * plista)
{
    nodo * primero;
    if(*plista!=NULL)
    {
        primero=*plista;
        *plista=(*plista)->siguiente;
        free(primero);
    }
}



int main()
{
    printf("Hello listas!\n");

    nodo * lista;

    char nombreArchivo[]="personas.dat";

    persona aux1= {"pepe", 23};
    persona aux2= {"maria", 34};
    persona aux3= {"jose", 30};


    lista=inicLista();

    lista=cargarListaDesdeArchivo(persona, lista);

    nodo * libre=desvincularPrimero(&lista);

    recorrerYmostrar(lista);


    return 0;
}
