#include "lista.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int nota, char alumno[])
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->nota = nota;
    strcpy(aux->alumno,alumno);
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

nodo * buscarNodo(int nota, nodo * lista)

{
    nodo * seg;
    seg = lista;

    while ((seg != NULL) && (seg->nota!=nota))
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

nodo * borrarNodoBuscado(int nota, nodo * lista)
{
    nodo * seg;
    nodo * ante;
    if((lista != NULL) && (lista->nota==nota))
    {
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (seg->nota!=nota))
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

        if(nuevoNodo->nota < lista->nota)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {

            nodo * ante = lista;
            nodo * seg = lista;
            while(seg != NULL && nuevoNodo->nota > seg->nota)
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
        suma = suma + seg->nota;
        seg = seg->siguiente;
    }
    return suma;
}

void mostrar(nodo * aux)
{
    printf("\nAlumno: %s ",aux->alumno);
    printf("\n  Nota: %d ",aux->nota);
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

nodo * IngresarnotasAlFinal(nodo * lista)
{
    int nota;
    char alumno[20];
    int cant;
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("ingrese un nota: ");
        scanf("%d",&nota);
        printf("\ningrese un alumno: ");
        fflush(stdin);
        scanf("%s",&alumno);
        aux=crearNodo(nota, alumno);
        lista=agregarFinal(lista,aux);
        cant--;
    }
    return lista;
}

nodo * IngresarnotasAlPpio(nodo * lista)
{
    int nota;
    char alumno[20];
    int cant;
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("\ningrese un nota: ");
        fflush(stdin);
        scanf("%d",&nota);
        printf("\ningrese un alumno: ");
        fflush(stdin);
        scanf("%s",&alumno);
        aux=crearNodo(nota, alumno);
        lista=agregarPpio(lista,aux);
        cant--;
    }
    return lista;
}

nodo * AgregarUnNodoEnOrden(nodo * lista)
{
    int nota;
     char alumno[20];
    nodo * aux=lista;
    printf("ingrese un nota: ");
    scanf("%d",&nota);
    printf("\ningrese un alumno: ");
    fflush(stdin);
    scanf("%s",&alumno);
    aux=agregarEnOrden(lista,crearNodo(nota, alumno));
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
    int nota;
    printf("ingrese nota a buscar: ");
    scanf("%d",&nota);
    nodo * aux=inicLista();
    aux=buscarNodo(nota,lista);
    if(aux!=NULL)
        printf("%d",aux->nota);
}

nodo * BorrarNodo(nodo * lista){
    int nota;
    printf("ingrese nota a borrar de la lista: ");
    scanf("%d",&nota);
    lista=borrarNodoBuscado(nota,lista);
    return lista;
}
