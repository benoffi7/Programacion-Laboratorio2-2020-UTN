#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define nomArch "archivo.bin"

///el archivo esta conformado por datos de tipo notaFinal

void lecturaDeArchivo(nodo** lista)
{
    NotaFinal nota;
    FILE* arch = fopen(nomArch,"rb");
    if (arch)
    {
        while (fread(&nota,sizeof(notaFinal),1,arch) > 0)
        {
            insertarEnOrden(lista,nota);
        }

        fclose(arch);
    }
}
/**
(Recursivo) Verificar si existe un determinado DNI en una asignatura
dada(Es dato).
**/
matematica
38

quimica teologia teologia teologia zoologia zoologia

int verificarDNI(nodo* lista,char* dni, char* asignatura)
{
    if (lista != NULL)
    {
        if (strcmp(lista->dato.asignatura, asignatura) == 0 && strcmp(lista->dato.dni,dni) == 0)
            return 1;
        else
        {
            if (strcmp(lista->dato.asignatura,asignatura) <= 0) ///SSE QUE ESTA ORDENADO
            {
                return verificarDNI(lista->sig,dni,asignatura);
            }
            else
                return 0;
        }

    }
    else
        return 0;

}

//(Recursivo) Mostrar todos los nodos con DNI y Nota de una
//asignatura en particular



///(Recursivo) Mostrar cantidad de alumnos de cada asignatura.
/// La primer asignatura de la lista
/// 0
void mostrarCantidad(nodo* lista, char* asignatura, int cant)
{
    if (lista != NULL)
    {
        if (strcmp(lista->dato.asignatura,asignatura)==0)
        {
            if (lista->sig != NULL)
                mostrarCantidad(lista->sig,asignatura,cant+1);
            else
            {
                cant++;
                printf("%s : %d\n",asignatura,cant);
            }
        }
        else
        {
            printf("%s : %d\n",asignatura,cant);
            mostrarCantidad(lista->sig,lista->dato.asignatura,1);

        }

    }
}

/**
Eliminar de la lista los nodos correspondientes a la asignatura
“Matematica” e insertar las notas(float) en una lista doblemente
enlazada “listaMate”.
**/
botanica botanica botanica lengua lengua matematica matematica matematica quimica quimica teologia
//las consideraciones son de una lista ordenada
//hacer el de la lista desordenada
void pasarAListaMate(nodo** lista, nodoD** listaMate, char* asignatura)
{
    nodo* seg,*ante;
    if (*lista != NULL)
    {
        if (strcmp((*lista)->dato.asignatura,asignatura) == 0)
        {
            while ((*lista) != NULL && strcmp((*lista)->dato.asignatura,asignatura) == 0)
            {
                aux=*lista;
                insertarAlPrincipio(listaMate,aux->dato.nota);
                (*lista) = (*lista)->sig;
                free(aux);
            }
        }
        else
        {
            ante= *lista;
            seg= (*lista)->sig;
            while (seg != NULL && strcmp(seg->dato.asignatura,asignatura) < 0)
            {
                ante=seg;
                seg=seg->sig;
            }
            while (seg != NULL && strcmp(seg->dato.asignatura,asignatura)==0)
            {
                aux=seg;
                seg=seg->sig;
                insertarAlPrincipio(listaMate,aux->dato.nota);
                ante->sig = seg;
                free(aux);

            }
        }

    }

}



int main()
{


    return 0;
}
