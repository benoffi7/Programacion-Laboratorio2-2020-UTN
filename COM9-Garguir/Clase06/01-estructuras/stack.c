#include "stack.h"

void initStack(Stack *p){
    int *aux;
    p->dim = 50;
    aux = malloc(sizeof(int) * p->dim);
    p->datos = aux;  /// (*p).datos
    ///p->datos = malloc(sizeof(int) * 50); /// Esta línea reemplaza a las tres anteriores
    p->validos = 0;
}

void push(Stack *p, int dato){
    if(p->validos==p->dim){
        p->dim+=10; /// p->dim = p->dim + 50;
        p->datos = realloc(p->datos, sizeof(int) * p->dim);
    }
    p->datos[p->validos] = dato;
    p->validos++;
}

int pop(Stack *p){
    int dato = p->datos[p->validos-1];
    p->validos--; /// p->validos = p->validos - 1;  decremento validos
    return dato;
}

int top(Stack p){
    int dato;
    dato = p.datos[p.validos-1];
    return dato;
}

int topPro(Stack p){
    return p.datos[p.validos-1];
}

int emptyStack(Stack p){
    int pilavacia = 0;
    if(p.validos<=0){
        pilavacia = 1;
    }
    return pilavacia;
}

int emptyStackPro(Stack p){
    return (p.validos <= 0) ? 1 : 0;
}

int countStack(Stack p){
    return p.validos;
}
