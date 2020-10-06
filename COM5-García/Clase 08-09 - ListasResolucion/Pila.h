#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


typedef struct nodo
{
   int dato;
   struct nodo* sig;
}nodo;

typedef struct nodo* Pila;


void inicPila(Pila*);
void apilar(Pila*,int);
int desapilar(Pila*);
int pilavacia(Pila);
int tope(Pila);
void mostrar(Pila);

#endif // PILA_H_INCLUDED
