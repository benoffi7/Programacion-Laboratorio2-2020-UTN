#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
#include "empleados.h"

typedef struct _nodo{
    stEmpleado dato;
    struct _nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void agregarAlPrincipioPD(nodo** lista, nodo* nuevoNodo);
void agregarAlPrincipioPDPro(nodo** lista, nodo* nuevoNodo);
void muestraNodo(nodo* aMostrar);
void muestraLista(nodo* lista);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo);
nodo* borrarLista(nodo* lista);
int cuentaLista(nodo* lista);
nodo* eliminaUltimoNodo(nodo* lista);
nodo* eliminaPrimerNodo(nodo* lista);
void eliminaPrimerNodoPD(nodo** lista);

#endif // LISTAEMPLEADOS_H_INCLUDED
