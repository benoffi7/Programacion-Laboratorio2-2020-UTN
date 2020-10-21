#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/// archivo de datos desordenado
typedef struct registro
{
    char materia[20];
    char alumno[20];
    int nota;
} registro;

/// arreglo de listas
typedef struct
{
    char materia[20];
    nodo * lista;
} celda;

/// busca posicion en adl
int buscaPosMateria(celda adl[], char materia[], int validos)
{
    int rta=-1;
    int i=0;
    while(i<validos&&rta==-1)
    {
        if(strcmp(adl[i].materia, materia)==0)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}

/// agrega celda en adl
int agregar(celda adl[], char materia [], int validos)
{
    strcpy(adl[validos].materia, materia);
    adl[validos].lista = inicLista();
    validos++;
    return validos;
}

/// alta en el adl
int alta (celda adl[], char materia[], char alumno[],int nota, int validos)
{
    nodo * aux = crearNodo(nota, alumno);
    int pos = buscaPosMateria(adl,materia,validos);

    if(pos==-1)
    {
        validos=agregar(adl,materia,validos);
        pos=validos-1;
    }

    adl[pos].lista=agregarFinal(adl[pos].lista, aux);
    return validos;
}

void mostrarADL (celda adl[], int validos)
{

    int i=0;
    printf("\n Mostrando el arreglo de listas: \n");

    for(i=0;i<validos;i++)
    {
        printf("Materia: %s\n", adl[i].materia);
        printf("Notas cargadas: \n");

        recorrerYmostrar(adl[i].lista);
    }
}


/// pasar de archivo 2 adl
int leerArchivoTup(char nombreArchi[], celda adl[], int dim)
{
    FILE * archi =fopen(nombreArchi, "rb");
    int validos=0;
    registro rg;

    if(archi)
    {
        while(fread(&rg, sizeof(registro), 1, archi)>0 && validos <dim)
        {
            validos=alta(adl, rg.materia, rg.alumno, rg.nota, validos);
        }

        fclose(archi);
    }
    return validos;
}


int main()
{
    printf("Hello Estructuras compuestas!\n");

    celda miArregloDeListas[20];
    int validosADL=0;

    validosADL=leerArchivoTup("registros.dat", miArregloDeListas, 20);

    mostrarADL(miArregloDeListas, validosADL);


    return 0;
}
