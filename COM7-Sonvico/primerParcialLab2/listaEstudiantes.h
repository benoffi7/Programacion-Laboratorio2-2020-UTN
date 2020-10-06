#ifndef LISTAPERSONAS_H_INCLUDED
#define LISTAPERSONAS_H_INCLUDED

#include "estudiante.h"

typedef struct _nodo{
    estudiante dato;
    struct _nodo* siguiente;
}nodoEstudiante;


nodoEstudiante* inicLista();

/// 1
///a
nodoEstudiante* crearnodoEstudiante(estudiante dato);
///b
nodoEstudiante* agregaAlFinalRecursiva(nodoEstudiante * lista, nodoEstudiante *nuevo);
/// c
nodoEstudiante* archivo2lista(nodoEstudiante* lista);


///2
void muestraListaRecursiva(nodoEstudiante* lista);

/// 3
int contarRecursivoLista(nodoEstudiante * lista);
int contarRecursivoListaAplazos(nodoEstudiante * lista, float valor);

/// 4
int mejorPromedioSinAplazos(nodoEstudiante *lista);
estudiante borrarEstudianteSegunLegajo(nodoEstudiante ** lista, int legajo);

/// fns para Pila
nodoEstudiante* agregarAlPrincipio(nodoEstudiante* lista, nodoEstudiante* nuevo);

#endif // LISTAPERSONAS_H_INCLUDED
