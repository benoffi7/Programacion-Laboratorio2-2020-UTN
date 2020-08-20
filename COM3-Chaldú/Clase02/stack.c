#include "stack.h"

void initStack(Stack *p){
    int *aux;
    aux = (int*) malloc(sizeof(int)*50);
    p->valores = aux;  /// es lo mismo que (*p).valores = aux;
    p->v = 0;
    p->dim = 50;
}

void push(Stack *p, int valor){
    if(p->v == p->dim){
        p->dim+=50; /// p->dim = p->dim + 20;
        p->valores = realloc(p->valores, sizeof(int)*p->dim);
    }
    p->valores[p->v]=valor;
    p->v++;
}

int pop(Stack *p){
    int aux = p->valores[p->v-1];
    p->v--;
    return aux;
}

int top(Stack p){

}

int emptyStack(Stack p){

}
