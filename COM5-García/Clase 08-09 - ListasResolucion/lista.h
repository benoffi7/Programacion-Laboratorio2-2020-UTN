#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
///modularizacion del código para listas simplmenete enlazadas (NO ES TDA)
struct nodo{
    int dato;
    struct nodo* sig;
}nodo;

//typedef struct nodo* Lista;

void insertarNodoAlFinal(nodo** lista, nodo* nuevo);
void ...


#endif // LISTA_H_INCLUDED
