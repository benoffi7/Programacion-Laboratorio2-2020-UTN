#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

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

void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre);
    printf("  Edad: %d \n", dato.edad);
    printf("-----------------------\n");
}

void mostrarNodo(nodo * aux)
{
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

int main()
{
    printf("Hello listas!\n");

    nodo * lista;

    persona aux1={"pepe", 23};
    persona aux2={"maria", 34};
    persona aux3={"jose", 30};


    lista=inicLista();

    lista=agregarPpio(lista, crearNodo(aux1));
    lista=agregarPpio(lista, crearNodo(aux2));
    lista=agregarPpio(lista, crearNodo(aux3));


    recorrerYmostrar(lista);


    return 0;
}
