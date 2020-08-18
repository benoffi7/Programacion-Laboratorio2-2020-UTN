#ifndef PILANUEVA_H_INCLUDED
#define PILANUEVA_H_INCLUDED


typedef struct{
     int valores[100];
     int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;

void apilar(Pila * p, int valor);
int desapilar(Pila * p);
int tope(Pila * p);
int pilavacia(Pila * p);
void mostrar(Pila * p);
void inicPila(Pila * p);


#endif // PILANUEVA_H_INCLUDED
