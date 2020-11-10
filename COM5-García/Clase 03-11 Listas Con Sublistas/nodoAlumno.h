#ifndef NODOALUMNO_H_INCLUDED
#define NODOALUMNO_H_INCLUDED

typedef struct {
   int legajo;
   char nombreApe[30];
}Alumno;


typedef struct _nodo {
   Alumno dato;
   struct _nodo *siguiente;
}nodoAlumno;




#endif // NODOALUMNO_H_INCLUDED
