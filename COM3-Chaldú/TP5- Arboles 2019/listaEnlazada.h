#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"


typedef struct _nodo
{
    persona dato;
    struct _nodo * siguiente;
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
void recorrerYmostrar(nodo * lista);

/// funciones que hacen uso de la estructura persona
void mostrarNodo(nodo * aux);
nodo * buscarNodo(nodo * lista, char nombre[20]);
nodo * borrarNodo(nodo * lista, char nombre[20]);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);

nodo * crearLista(nodo * lista);

#endif // LISTAENLAZADA_H_INCLUDED
