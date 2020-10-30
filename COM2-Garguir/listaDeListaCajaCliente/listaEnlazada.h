#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int nroCliente;
    char nombre_apellido [30];
    int cantProductos;
}persona;

typedef struct
{
    persona dato;
    struct nodo * siguiente;
}nodo;

///DECLARACION DE FUNCIONES:

///FUNCIONES BASICAS PARA EL MANEJO DE LISTAS:
nodo * inicLista();
nodo * crearNodo(persona dato); /// hace uso de la estrucutra persona... pero es de funcionamiento básico del tda
nodo * agregarPpio(nodo * lista, nodo * nuevoNodo);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * borrarTodaLaLista(nodo * lista);
nodo * eliminaUltimoNodo(nodo * lista);
nodo * eliminaPrimerNodo(nodo * lista);
void recorrerYmostrarClientes(nodo * lista);

/// funciones que hacen uso de la estructura persona
void mostrarNodo(nodo * aux);
nodo * buscarNodo(nodo * lista, char nombre[20]);
nodo * borrarNodo(nodo * lista, char nombre[20]);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);


#endif // LISTAENLAZADA_H_INCLUDED
