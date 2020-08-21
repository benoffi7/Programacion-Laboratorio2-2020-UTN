#include "stack.h"


void initStack(Stack * p){
    int *aux;
    aux = malloc(sizeof(int)*50);
    p->valores = aux; /// (*p).valores = aux
    p->validos = 0;
    p->dim = 50;
}

void push(Stack * p, int valor){
    if(p->validos==p->dim){
        p->dim+=50; /// p->dim = p->dim +50;
        p->valores = realloc(p->valores, sizeof(int) * p->dim);
    }
    p->valores[p->validos] = valor;
    p->validos++;
}

int pop(Stack * p){
    int aux = p->valores[p->validos-1];
    p->validos--;
    return aux;
}

int top(Stack * p){

}

int emptyStack(Stack * p){

}
