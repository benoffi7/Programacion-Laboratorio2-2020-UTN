#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct{
     int *datos;
     int validos;
     int dim;
}Stack;

void initStack(Stack *p);
void push(Stack *p, int valor);
int pop(Stack *p);
int top(Stack p);
int topPro(Stack p);
int emptyStack(Stack p);
int emptyStackPro(Stack p);
int countStack(Stack p);

#endif // STACK_H_INCLUDED
