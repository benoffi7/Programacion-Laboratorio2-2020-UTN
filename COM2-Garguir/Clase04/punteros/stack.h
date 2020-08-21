#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct{
     int *valores;
     int validos;
     int dim;
}Stack;

void initStack(Stack * p);
void push(Stack * p, int valor);
int pop(Stack * p);
int top(Stack * p);
int emptyStack(Stack * p);

#endif // STACK_H_INCLUDED
