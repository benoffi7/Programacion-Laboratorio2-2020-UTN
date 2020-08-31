#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

typedef struct
{
    persona dato;
    struct nodo * siguiente;
} nodo;


nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo (persona dato)
{
///crea un puntero de tipo nodo
    nodo * aux = (nodo*) malloc(sizeof(nodo));

///asigna valores a sus campos de información
    aux->dato = dato;

///asigna valor NULL al campo que contiene la dirección de memoria del //siguiente nodo
    aux->siguiente = NULL;

///retorna la dirección de memoria del nuevo nodo, que deberá ser asignada a una variable de tipo "puntero a nodo".
    return aux;
}


nodo * agregarPpio (nodo * lista, nodo * nuevoNodo)
{
///si la lista está vacía, ahora apuntará al nuevo nodo.
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
///si la lista no está vacía, inserta el nuevo nodo al comienzo de la //misma, y el viejo primer nodo pasa a ser el segundo de la lista.
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


    persona aux1= {"pepe grillo", 23};
    persona aux2= {"maria perez", 31};
    persona aux3= {"bart simpson", 10};

    ///  variable estática definida en el main()
    nodo * lista=inicLista();


    lista=agregarPpio(lista, crearNodo(aux1));
    lista=agregarPpio(lista, crearNodo(aux2));
    lista=agregarPpio(lista, crearNodo(aux3));




    recorrerYmostrar(lista);

    return 0;
}
