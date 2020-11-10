#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct
{
    char nomAlumno[20];
    int edad;
}Alumno;



typedef struct nodo
{
    float nota;
    Alumno a;
    struct nodo* sig;
}nodo;



#endif // LISTA_H_INCLUDED
