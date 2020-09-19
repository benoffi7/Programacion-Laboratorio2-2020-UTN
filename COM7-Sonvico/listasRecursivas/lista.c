#include "lista.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
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

nodo * buscarNodo(int dato, nodo * lista)

{
    nodo * seg;
    seg = lista;

    while ((seg != NULL) && (seg->dato!=dato))
    {
        seg=seg->siguiente;
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

nodo * borrarNodoBuscado(int dato, nodo * lista)
{
    nodo * seg;
    nodo * ante;
    if((lista != NULL) && (lista->dato==dato))
    {
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (seg->dato!=dato))
        {
            ante = seg;
            seg = seg->siguiente;
        }

        if(seg!=NULL)
        {
            ante->siguiente = seg->siguiente;

            free(seg);
        }
    }
    return lista;
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)

{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {

        if(nuevoNodo->dato < lista->dato)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {

            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while(seg != NULL && nuevoNodo->dato > seg->dato)
            {
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
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
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodo * borrarPrimerNodo(nodo * lista)
{
    nodo * aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

nodo * borrarUltimoNodo(nodo * lista)
{
    nodo * aux=lista;
    nodo * ante;
    while(aux->siguiente!=NULL)
    {
        ante=aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}

int sumarEdadesLista(nodo * lista)
{
    int suma = 0;
    nodo * seg = lista;
    while (seg != NULL)
    {
        suma = suma + seg->dato;
        seg = seg->siguiente;
    }
    return suma;
}

void mostrar(nodo * aux)
{
    printf("%d ",aux->dato);
}

void recorrerYmostrar(nodo * lista)
{
    nodo * aux=lista;
    while(aux!=NULL)
    {
        mostrar(aux);
        aux=aux->siguiente;
    }
    puts("\n");
}

nodo * IngresarDatosAlFinal(nodo * lista)
{
    int dato;
    int cant;
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("ingrese un dato: ");
        scanf("%d",&dato);
        aux=crearNodo(dato);
        lista=agregarFinal(lista,aux);
        cant--;
    }
    return lista;
}

nodo * IngresarDatosAlPpio(nodo * lista)
{
    int dato;
    int cant;
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("ingrese un dato: ");
        scanf("%d",&dato);
        aux=crearNodo(dato);
        lista=agregarPpio(lista,aux);
        cant--;
    }
    return lista;
}

nodo * AgregarUnNodoEnOrden(nodo * lista)
{
    int dato;
    nodo * aux=lista;
    printf("ingrese un dato: ");
    scanf("%d",&dato);
    aux=agregarEnOrden(lista,crearNodo(dato));
    return aux;
}

nodo * CrearListaOrdenada(nodo * lista)
{
    int cant;
    nodo * aux=lista;
    printf("ingrese cantidad a ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        aux=AgregarUnNodoEnOrden(aux);
        cant--;
    }
    return aux;
}

void BusquedaDeUnNodo(nodo * lista)
{
    int dato;
    printf("ingrese dato a buscar: ");
    scanf("%d",&dato);
    nodo * aux=inicLista();
    aux=buscarNodo(dato,lista);
    if(aux!=NULL)
        printf("%d",aux->dato);
}

nodo * BorrarNodo(nodo * lista){
    int dato;
    printf("ingrese dato a borrar de la lista: ");
    scanf("%d",&dato);
    lista=borrarNodoBuscado(dato,lista);
    return lista;
}
