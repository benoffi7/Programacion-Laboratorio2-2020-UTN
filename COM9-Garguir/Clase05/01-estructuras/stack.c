#include "stack.h"


void initStack(Stack * p){
    int *aux;
    aux = malloc(sizeof(int) * 50);
    //p->valores = malloc(sizeof(int) * 50);
    p->valores = aux;  /// (*p).valores
    p->validos = 0;
    p->dim = 50;
}

void push(Stack * p, int valor){
    if(p->validos==p->dim){
        p->dim+=50; /// p->dim = p->dim + 50;
        p->valores = realloc(p->valores, sizeof(int) * p->dim);
    }
    p->valores[p->validos] = valor;
    p->validos++;
}

int pop(Stack * p){
    int dato = p->valores[p->validos-1];
    p->validos--; /// p->validos = p->validos - 1;  decremento validos
    return dato;
}

int top(Stack * p){
    return p->valores[p->validos-1];
}

/*
int emptyStack(Stack * p){
    int pilavacia = 0;
    if(p->validos==0){
        pilavacia = 1;
    }
    return pilavacia;
}
*/

int emptyStack(Stack * p){
    return (p->validos==0)?1:0;
}

int countStack(Stack * p){
    return p->validos;
}
