#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef Persona tipoDato;

typedef struct nodoD
{
    tipoDato dato;
    nodoD* ant;
    nodoD* sig;
}nodoD


typedef struct Fila
{
    nodoD* pri;
    nodoD* ult;
}Fila;

void inicFila(Fila *);
void poneFila(Fila*, tipoDato);
tipoDato sacaFila(Fila*);
int Filavacia(Fila);
tipoDato frente(Fila);
#endif // FILA_H_INCLUDED
