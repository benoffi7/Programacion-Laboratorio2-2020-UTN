#ifndef NODOCAJA_H_INCLUDED
#define NODOCAJA_H_INCLUDED
#include "listaCliente.h"

typedef struct
{
    int nroCaja;
    char medio_Pago [30];
}caja;

typedef struct
{
    caja c;
    nodo * listaClientes;
    struct nodoCaja * siguiente;
}nodoCaja;

///DECLARACION DE FUNCIONES:

///FUNCIONES BASICAS PARA EL MANEJO DE LISTAS:
nodoCaja * inicListaCaja();
nodoCaja * crearNodoCaja(caja c); /// hace uso de la estrucutra persona... pero es de funcionamiento básico del tda
nodoCaja * agregarPpioCaja(nodoCaja * lista, nodoCaja * nuevoNodo);
nodoCaja * alta (nodoCaja *listaCajas, nodo * nuevoCliente, int nroCaja);
nodoCaja * buscarCaja(nodoCaja * lista, int nroCaja);
caja ingresarCaja(int);
void recorrerYmostrarCajasClientes(nodoCaja * lista);
void mostrarNodoCaja(nodoCaja * c);



#endif // NODOCAJA_H_INCLUDED
