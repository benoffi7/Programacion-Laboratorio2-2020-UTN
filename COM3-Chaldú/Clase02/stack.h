#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct{
    int *valores;
    int v; /// son los validos del arreglo
    int dim;
}Stack;

void push(Stack *p, int valor);
int pull(Stack *p);
int top(Stack p);
int emptyStack(Stack p);
void initStack(Stack *p);

#endif // STACK_H_INCLUDED
