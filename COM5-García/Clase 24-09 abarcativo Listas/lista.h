#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct
{
    char dni[9];
    char asignatura[20]; //Matematica,Quimica,Lengua
    float nota;
} NotaFinal;

typedef struct nodo
{
    NotaFinal dato;
    struct nodo* sig;
} nodo;



#endif // LISTA_H_INCLUDED
