#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "empleados.h"

typedef struct _nodo2{
    stEmpleado dato;
    struct nodo2* anterior;
    struct nodo2* siguiente;
}nodo2;



#endif // LISTA2_H_INCLUDED
