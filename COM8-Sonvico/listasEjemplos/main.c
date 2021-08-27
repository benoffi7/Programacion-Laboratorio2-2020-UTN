#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

void mostrarPersona(persona dato)
{
    printf("Nombre: %s\n", dato.nombre);
    printf("Edad  : %d\n", dato.edad);
}

typedef struct
{
    persona dato;
    struct nodo * siguiente;
} nodo;

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux=(nodo *) malloc(sizeof(nodo));

    aux->dato=dato;

    aux->siguiente=NULL;

    return aux;
}

nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo)
{
    if(lista==NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}

void mostrarNodo(nodo * aux)
{
    mostrarPersona(aux->dato);
}

void mostrarLista(nodo * lista)
{
    nodo * seg=lista;

    printf("Contenido de la lista\n");

    puts("Inicio");
    while(seg!=NULL)
    {
        mostrarNodo(seg);
        seg=seg->siguiente;
    }
    puts("Fin");
}


int main()
{

    nodo * lista=inicLista();

    persona aux1={"pepe",23};
    persona aux2={"maria",24};
    persona aux3={"lala",24};
    persona aux4={"lolo",24};

    nodo * nuevo1=crearNodo(aux1);
    nodo * nuevo2=crearNodo(aux2);
    nodo * nuevo3=crearNodo(aux3);
    nodo * nuevo4=crearNodo(aux4);


    lista=agregarAlPrincipio(lista, nuevo1);

    lista=agregarAlPrincipio(lista, nuevo2);

    lista=agregarAlPrincipio(lista, nuevo3);

    lista=agregarAlPrincipio(lista, nuevo4);


    mostrarLista(lista);
/// Jugando con la me mmoria dinamica
    /*
    int arrayEstatico[10];

    char * arrayDinamico = (char*) malloc(10 * sizeof(char));

    int * otroArrayDinamico = (int *) calloc(10, sizeof(int));

    printf("El arreglo vive en %p\n", otroArrayDinamico);

    for(int i =0; i<10; i++)
    {
        otroArrayDinamico[i]=i;
    }

    for (int i=0; i<10; i++){
         printf("%d ", otroArrayDinamico[i]);
    }

    system("pause");

    otroArrayDinamico=realloc(otroArrayDinamico, 30*sizeof(int));

    printf("El arreglo vive en %p\n", otroArrayDinamico);

    for(int i =10; i<30; i++)
    {
        otroArrayDinamico[i]=i;
    }

    for (int i=0; i<30; i++){
         printf("%d ", otroArrayDinamico[i]);
    }*/

    return 0;
}
