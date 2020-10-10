#include <stdio.h>
#include <stdlib.h>
#include "listaEstudiantes.h"


nodoEstudiante* inicLista()
{
    return NULL;
}
///1
nodoEstudiante* crearnodoEstudiante(estudiante dato)
{
    nodoEstudiante* nuevonodoEstudiante = (nodoEstudiante*)malloc(sizeof(nodoEstudiante));
    nuevonodoEstudiante->dato = dato;
    nuevonodoEstudiante->siguiente = NULL;
    return nuevonodoEstudiante;
}

nodoEstudiante* agregaAlFinalRecursiva(nodoEstudiante * lista, nodoEstudiante *nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        lista->siguiente=agregaAlFinalRecursiva(lista->siguiente, nuevo);
    }
    return lista;
}

nodoEstudiante* archivo2lista(nodoEstudiante* lista)
{
    estudiante p;

    FILE * pArchEstu = fopen(arEstudiantes,"rb");

    if(pArchEstu)
    {
        while(fread(&p,sizeof(estudiante),1,pArchEstu)>0)
        {
            nodoEstudiante* nuevo = crearnodoEstudiante(p);
            lista = agregaAlFinalRecursiva(lista,nuevo);
        }
        fclose(pArchEstu);
    }
    return lista;
}


/// 2
void muestraListaRecursiva(nodoEstudiante* lista)
{
    if(lista)
    {
        muestraUnEstudiante(lista->dato);
        muestraListaRecursiva(lista->siguiente);
    }
}

/// 3
int contarRecursivoLista(nodoEstudiante * lista)
{
    int cant=0;
    if(lista)
    {
        cant=1+contarRecursivoLista(lista->siguiente);
    }
    return cant;
}
int contarRecursivoListaAplazos(nodoEstudiante * lista, float valor)
{
    int cant=0;
    if(lista)
    {
        if(lista->dato.promedioConAplazos>valor)
        {
            cant=1+contarRecursivoListaAplazos(lista->siguiente, valor);
        }
        else
        {
            cant=contarRecursivoListaAplazos(lista->siguiente, valor);
        }
    }
    return cant;
}

/// 4
int mejorPromedioSinAplazos(nodoEstudiante *lista)
{
    nodoEstudiante * mejor;
    nodoEstudiante * seg;

    if(lista)
    {
        mejor=lista; ///supongo el primero como el mejor

        seg=lista->siguiente; /// cargo el siguiente para iterar

        while(seg)
        {
            if(seg->dato.promedioSinAplazos>mejor->dato.promedioSinAplazos)
            {
                mejor=seg;
            }
            seg=seg->siguiente;
        }
    }

    return mejor->dato.legajo;
}

estudiante borrarEstudianteSegunLegajo(nodoEstudiante ** lista, int legajo)
{

    estudiante e;
    if(*lista)
    {
        if((*lista)->dato.legajo==legajo)
        {
            nodoEstudiante * aBorrar=*lista;
            *lista=(*lista)->siguiente;

            e=aBorrar->dato;

            free(aBorrar);
        }
        else
        {
            nodoEstudiante *ante=*lista;
            nodoEstudiante *seg=(*lista)->siguiente;

            while(seg && seg->dato.legajo!=legajo)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            if(seg)
            {
                ante->siguiente = seg->siguiente;

                e=seg->dato;

                free(seg);
            }
        }
    }

    return e;
}

/// fns para Pila
nodoEstudiante* agregarAlPrincipio(nodoEstudiante* lista, nodoEstudiante* nuevo)
{
    nuevo->siguiente = lista;
    return nuevo;
}



