#ifndef LISTADEARBOLES_H_INCLUDED
#define LISTADEARBOLES_H_INCLUDED

#include "arbolPersona.h"

typedef struct
{
    int anioNacimiento;
    nodoArbol * arbolPersonas;
    struct nodoListaDeArbol * sig;
}nodoListaDeArbol;

typedef struct
{
    int dni;
    char nombre[30];
    int anioNacimiento;
}registroArchivo;


///Funciones Lista de Arboles
nodoListaDeArbol * inicLista ();
nodoListaDeArbol * crearNodoLista (int anio);
nodoListaDeArbol * agregarEnOrden (nodoListaDeArbol * lista, nodoListaDeArbol * nuevo);
void mostrarLista (nodoListaDeArbol * lista);
nodoListaDeArbol * buscarNodoAnio (nodoListaDeArbol * lista, int anio);

nodoListaDeArbol * leerDatosArchivo (char nombreArchivo[]);

#endif // LISTADEARBOLES_H_INCLUDED
