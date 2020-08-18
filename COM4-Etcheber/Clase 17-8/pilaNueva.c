#include "pilanueva.h"


void inicPila(Pila * p)
{
    // (*p).posTope = 0;
    p->posTope = 0;
}


void apilar(Pila * p, int valor)
{
    if(p->posTope < 100)
    {
        p->valores[ p->posTope ] = valor;
        p->posTope ++;
    }
    else
        printf("\n La pila está llena. \n");


}
