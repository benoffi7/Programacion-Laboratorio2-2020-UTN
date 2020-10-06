#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"

typedef struct
{
    nodo2 * inicio;
    nodo2 * fin;
}Fila;

void inicFila(Fila * fila);
void agregar(Fila * fila, int dato);
void mostrar(Fila * filita);
int extraer(Fila * filita);
int filavacia(Fila * filita);
void vaciarFila(Fila * filita);
int verPrimeroFila(Fila * filita);


int main()
{
    Fila filita;
    inicFila(&filita);
    agregar(&filita,1);
    agregar(&filita,2);
    agregar(&filita,3);
    mostrar(&filita);
    vaciarFila(&filita);

    mostrar(&filita);
    return 0;
}

void inicFila(Fila * fila)
{
    fila->inicio = inicLista();
    fila->fin = inicLista();
}

void agregar(Fila * fila, int dato)
{
    nodo2 * nuevoNodo = crearNodo(dato);
    fila->fin = agregarAlFinal(fila->fin, nuevoNodo);
    if (fila->inicio == NULL) //que pasa cuando esta vacia??
    {
        fila->inicio=fila->fin;
    }

    fila->fin=nuevoNodo;
}

void mostrar(Fila * filita)
{
    printf("inicio\n");
    recorrerYmostrar(filita->inicio);
    printf("\nfin\n");
}

int extraer(Fila * filita)
{
    int respuesta = 0;

    if (filita->inicio != NULL)
    {
        //copiamos el primer valor!
        respuesta = verPrimeroFila(filita);
        //una vez asegurado el retorno, podemos borrar
        filita->inicio = borrarPrimero(filita->inicio);

        if (filita->inicio == NULL) //si justo borre el unico...
        {
            filita->fin = inicLista();
        }
    }

    return respuesta;
}

int filavacia(Fila * filita)
{
    int resultado = 0;
    if (filita->inicio == NULL) { resultado = 1; }
    return resultado;
}

void vaciarFila(Fila * filita)
{
    while (filavacia(filita) == 0)
    {
        int extraido = extraer(filita);
        printf("el extraido es ...%d\n",extraido);

    }

}

int verPrimeroFila(Fila * filita)
{
    int primero = 0;
    if (!filavacia(&filita)) { primero = verPrimero(filita->inicio); }
    return primero;
}

