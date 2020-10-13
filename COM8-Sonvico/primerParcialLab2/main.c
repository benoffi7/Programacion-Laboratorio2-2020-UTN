#include <stdio.h>
#include <stdlib.h>
#include "listaEstudiantes.h"
#include "Pila.h"


/// 3.c
void subProgramaPorcentaje(nodoEstudiante * lista);

/// 4.c
int subProgramaDiezMejores(nodoEstudiante ** plista, estudiante A[], int dim);

/// 5
void mostrarArregloEstudiantesR(estudiante A[], int validos, int i);

/// 6.b
void copiarDeLista2Pila(nodoEstudiante * lista, Pila * pilita);

int main()
{
    printf("Hello world primer parcial!\n");

    /// 1
    nodoEstudiante * listita=inicLista();
    listita=archivo2lista(listita);

    printf("\nSe paso el archivo a la lista!\n");
    system("pause");

    ///2
    printf("\nContenido de la lista: \n");
    muestraListaRecursiva(listita);

    printf("\n");
    system("pause");

    /// 3
    printf("\nVemos las cantidades y el porcentaje!\n");

    subProgramaPorcentaje(listita);
    system("pause");

    /// 4
    estudiante MisAyudantes[10];
    int valid=0;

    printf("\nBuscando ayudantes... Ojo Sergio que viene el serrucho!\n");
    valid=subProgramaDiezMejores(&listita, MisAyudantes, 10);
    system("pause");

    /// 5
    printf("\nLos nuevos ayudantes: \n");
    mostrarArregloEstudiantesR(MisAyudantes, valid, 0);
    system("pause");

    printf("\nContenido de la lista sin los ayudantes: \n");
    muestraListaRecursiva(listita);
    system("pause");

    /// 6

    Pila pilita;
    inicPila(&pilita);

    printf("\nCopiando estudiantes a la pila\n");
    copiarDeLista2Pila(listita, &pilita);
    system("pause");

    printf("Contenido de la pila de estudiantes: \n");
    mostrar(&pilita);
    system("pause");

    return 0;
}

void subProgramaPorcentaje(nodoEstudiante * lista)
{
    int total, filtro;
    float valor=0, porcent;
    printf("\n Ingrese el valor para filtrar: ");
    scanf("%f", &valor);

    total=contarRecursivoLista(lista);
    filtro=contarRecursivoListaAplazos(lista, valor);

    porcent=((float) filtro*100)/(float)total;

    printf("\n El total de estudiantes en la lista es %d\n", total);
    printf("\n La cantidad de estudiantes con un promedio con aplazos superior a % .2f en la lista es %d\n",valor, filtro);
    printf("\n Y corresponde a un %.2f %% del total de la lista\n", porcent);
}

int subProgramaDiezMejores(nodoEstudiante ** plista, estudiante A[], int dim)
{
    int i=0, legajo;
    estudiante aux;

    while(*plista && i<10)
    {
        legajo=mejorPromedioSinAplazos(*plista);

        aux=borrarEstudianteSegunLegajo(plista, legajo);

        A[i]=aux;

        i++;
    }
    return i;
}

void mostrarArregloEstudiantesR(estudiante A[], int validos, int i)
{
    if(i<validos)
    {
        mostrarArregloEstudiantesR(A, validos, i+1);
        muestraUnEstudiante(A[i]);
    }
}

void copiarDeLista2Pila(nodoEstudiante * lista, Pila * pilita)
{
    estudiante aux;
    nodoEstudiante * seg=lista;

    while(seg)
    {
        if(seg->dato.cantMateriasAprobadas>10&&seg->dato.promedioSinAplazos>8)
        {
            aux=seg->dato;

            apilar(pilita, aux);
        }
        seg=seg->siguiente;
    }
}
