#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "listaEmpleados.h"
#define Pila nodo*

void inicPila(Pila* p);
int pilaVacia(Pila* p);
int pilaVaciaPro(Pila* p);
void apilar(Pila* p, stEmpleado e);
void apilarPD(Pila* p, stEmpleado e);
stEmpleado desapilar(Pila* p);
stEmpleado tope(Pila* p);

#endif // PILA_H_INCLUDED
