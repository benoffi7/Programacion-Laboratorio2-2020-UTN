#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    int a[]= {50,25,75,12,62,37,87,6,31,1,51,38,36,35,39,61,63,86,89,90,55};
    //int a[] = {1, 2, 3};

    int vA = sizeof(a)/sizeof(int);
    printf("\n sizeof a = %d - sizeof int = %d - validos =  %d\n", sizeof(a), sizeof(int), vA);

    nodoArbol* arbol = inicArbol();

    for(int i=0; i<vA; i++){
        arbol = insertar(arbol, crearNodoArbol(a[i]));
    }

    printf("\n Muestro arbol preOrder..... \n");
    preOrder(arbol);

    printf("\n Muestro arbol inOrder..... \n");
    inOrder(arbol);

    printf("\n Muestro arbol postOrder..... \n");
    postOrder(arbol);
    return 0;
}
