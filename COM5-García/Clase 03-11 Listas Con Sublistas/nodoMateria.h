#ifndef NODOMATERIA_H_INCLUDED
#define NODOMATERIA_H_INCLUDED
#include "nodoAlumno.h"

typedef struct nodoMateria {
    char materia[30];
    nodoAlumno * listaAlumnos;
    struct nodoMateria* sig;
}nodoMateria;




#endif // NODOMATERIA_H_INCLUDED
