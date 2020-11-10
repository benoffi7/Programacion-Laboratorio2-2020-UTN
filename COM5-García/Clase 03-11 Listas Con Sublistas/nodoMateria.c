#include "nodoMateria.h"


nodoMateria* crearNodoMateria(char* materia)
{
    nodoMateria* nuevo = (nodoMateria*)malloc(sizeof(nodoMateria));
    strcpy(nuevo->materia,materia);
    nuevo->sig = NULL;
    nuevo->listaAlumnos = NULL;

    return nuevo;
}
