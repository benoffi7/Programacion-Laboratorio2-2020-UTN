#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "listaEstudiantes.h"


/// 6.a

#define Pila nodoEstudiante *


void inicPila (Pila * pila);

void apilar (Pila * pila, estudiante dato);

void mostrar (Pila * pila);

#endif // PILA_H_INCLUDED
