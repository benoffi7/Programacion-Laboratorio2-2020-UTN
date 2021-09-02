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
    while(seg!=NULL)
    {
        mostrarNodo(seg);
        seg=seg->siguiente;
    }
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodo * agregarAlFinal(nodo * lista, nodo * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodo * ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}

void agregarAlFinalPP(nodo * * pLista, nodo * nuevo)
{
    if(*pLista==NULL)
    {
        *pLista=nuevo;
    }
    else
    {
        nodo * ultimo=buscarUltimo(*pLista);
        ultimo->siguiente=nuevo;
    }
}



nodo * insertarOrdenado(nodo * lista, nodo * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;  /// 1er caso: la lista esta vacia
    }
    else
    {
        if(strcmp(nuevo->dato.nombre, lista->dato.nombre)<0)
        {
            lista=agregarAlPrincipio(lista, nuevo);   /// 2do caso: inserto al ppio porque el nuevo es menor
        }
        else
        {
            nodo * ante=lista;  /// 3er y 4to caso: inserto al medio o al final
            nodo * seg=lista->siguiente;

            while(seg!=NULL && strcmp(nuevo->dato.nombre, seg->dato.nombre)>0)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            ante->siguiente=nuevo;
            nuevo->siguiente=seg;
        }
    }
    return lista;
}

nodo * borrarUnNodoPorNombre(nodo * lista, char nombre[])
{
    if(lista!=NULL)
    {
        if(strcmp(lista->dato.nombre, nombre)==0)  /// 1er caso, borrar el inicio
        {
            nodo * aux = lista;
            lista=lista->siguiente;
            free(aux);
        }
        else   /// 2do y 3er caso, borrar por el medio o el ultimo
        {
            nodo * ante = lista;
            nodo * seg = lista->siguiente;

            while(seg!=NULL && strcmp(nombre, seg->dato.nombre)!=0)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            if(seg!=NULL) /// encontre el nodo a borrar
            {
                ante->siguiente=seg->siguiente;
                free(seg);
            }
        }
    }
    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo *aux;

    nodo *seg=lista;

    while(seg!=NULL)
    {
        aux=seg;

        seg=seg->siguiente;

        free(aux);
    }

    return seg;
}

void punteroDoble(nodo * * pLista)
{
    nodo * primero;

    if((*pLista)!=NULL)
    {
        primero = *pLista;

        *pLista = (*pLista)->siguiente;

        free(primero);
    }
}



int main()
{

    nodo * lista=inicLista();

    persona aux1= {"pepe",23};
    persona aux2= {"maria",24};
    persona aux3= {"lala",24};
    persona aux4= {"lolo",24};

    nodo * nuevo1=crearNodo(aux1);
    nodo * nuevo2=crearNodo(aux2);
    nodo * nuevo3=crearNodo(aux3);
    nodo * nuevo4=crearNodo(aux4);


    lista=agregarAlPrincipio(lista, nuevo1);

    lista=agregarAlPrincipio(lista, nuevo2);

    lista=agregarAlPrincipio(lista, nuevo3);

    lista=agregarAlPrincipio(lista, nuevo4);


    mostrarLista(lista);

    punteroDoble(&lista);

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
