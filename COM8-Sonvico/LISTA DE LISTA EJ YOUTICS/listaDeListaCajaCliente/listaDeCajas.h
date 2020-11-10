#ifndef LISTADECAJAS_H_INCLUDED
#define LISTADECAJAS_H_INCLUDED
#include "listaEnlazada.h"

typedef struct
{
    int nroCaja;
    char medio_Pago [30];
}caja;

typedef struct
{
    nodo * listaClientes;
    struct nodoCaja * siguiente;
}nodoCaja;

///DECLARACION DE FUNCIONES:

///FUNCIONES BASICAS PARA EL MANEJO DE LISTAS:
nodoCaja * inicListaCaja();
nodoCaja * crearNodoCaja(); /// hace uso de la estrucutra persona... pero es de funcionamiento básico del tda
nodoCaja * agregarPpioCaja(nodoCaja * lista, nodoCaja * nuevoNodo);

#endif // LISTADECAJAS_H_INCLUDED
