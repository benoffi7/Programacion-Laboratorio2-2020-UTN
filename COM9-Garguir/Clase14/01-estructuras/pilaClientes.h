#ifndef PILACLIENTES_H_INCLUDED
#define PILACLIENTES_H_INCLUDED

#include "listaClientes.h"

#define PilaCli nodo*

void inicPila(PilaCli* p);
int pilaVacia(PilaCli* p);
int pilaVaciaPro(PilaCli* p);
void apilarCliente(PilaCli* p, stCliente c);
void apilarClientePD(PilaCli* p, stCliente c);
stCliente desapilarCliente(PilaCli* p);
stCliente topeCliente(PilaCli* p);


#endif // PILACLIENTES_H_INCLUDED
