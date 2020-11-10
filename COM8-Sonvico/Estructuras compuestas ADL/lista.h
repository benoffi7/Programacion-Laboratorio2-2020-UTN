#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo
{
    int nota; // es la nota
    char alumno[20];
    struct _nodo * siguiente;
} nodo;

nodo * inicLista();
nodo * crearNodo(int nota, char alumno[]);
nodo * agregarPpio(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * buscarNodo(int nota, nodo * lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * borrarNodoBuscado(int nota, nodo * lista);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodo * borrarTodaLaLista(nodo * lista);
nodo * borrarPrimerNodo(nodo * lista);
nodo * borrarUltimoNodo(nodo * lista);
int sumarEdadesLista(nodo * lista);
void mostrar(nodo * aux);
void recorrerYmostrar(nodo * lista);
nodo * IngresarnotasAlFinal(nodo * lista);
nodo * IngresarnotasAlPpio(nodo * lista);
nodo * AgregarUnNodoEnOrden(nodo * lista);
nodo * CrearListaOrdenada(nodo * lista);
void BusquedaDeUnNodo(nodo * lista);
nodo * BorrarNodo(nodo * lista);


#endif // LISTA_H_INCLUDED
