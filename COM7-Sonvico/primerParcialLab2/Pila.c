#include "Pila.h"

void inicPila (Pila * pila)
{
    (*pila)=inicLista();
}

void apilar (Pila * pila, estudiante dato)
{
    nodoEstudiante * nuevo=crearnodoEstudiante(dato);
    *pila=agregarAlPrincipio(*pila, nuevo);
}

void mostrar (Pila * pila)
{
    printf("\nTope ");
    replicante('-',50);
    muestraListaRecursiva(*pila);
    printf("\nBase\n");
}
