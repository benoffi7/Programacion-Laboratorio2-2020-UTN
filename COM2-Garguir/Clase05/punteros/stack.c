#include "stack.h"


void initStack(Stack * p){
    int *aux;
    aux = malloc(sizeof(int)*50);
    p->datos = aux; /// es lo mismo que (*p).valores = aux
    /// p->datos = malloc(sizeof(int)*50); reemplaza las 3 lineas superiores
    p->validos = 0;
    p->dim = 50;
}

void push(Stack * p, int dato){
    if(p->validos==p->dim){
        p->dim+=50; /// p->dim = p->dim +50;
        p->datos = realloc(p->datos, sizeof(int) * p->dim);
    }
    p->datos[p->validos] = dato;
    p->validos++;
}

int pop(Stack * p){
    int aux = p->datos[p->validos-1];
    p->validos--;
    return aux;
}

int top(Stack p){  /// recibo el arreglo como compia por eso uso el . en vez de ->
    int valorTope;
    valorTope=p.datos[p.validos-1];
    return valorTope;
    ///return p.datos[p.validos-1]; esta linea reemplaza a las 3 anteriores
}

int topPro(Stack p){  /// recibo el arreglo como compia por eso uso el . en vez de ->
    return p.datos[p.validos-1];
}

int emptyStack(Stack * p){
    int flag=1;

    if(p->validos >0)
    {
        flag=0;
    }
    return flag;
}

int emptyStackPro(Stack p){
    return (p.validos > 0) ? 0 : 1;
}
