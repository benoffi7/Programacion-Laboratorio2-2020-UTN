#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"

typedef struct{
    nodo2* inicio;
    nodo2* fin;
}Fila;

void inicFila(Fila* fila);
void agregar(Fila* fila, stCliente dato);
stCliente primero(Fila* fila);
stCliente extraer(Fila* fila);
int filaVacia(Fila* fila);
int filaVaciaPro(Fila* fila);
void muestraFila(Fila* fila);


#endif // FILA_H_INCLUDED
