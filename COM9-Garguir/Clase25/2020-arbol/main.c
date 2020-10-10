#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"


int main()
{
    int a[10]= {1,10,2,45,9,15,46,33,25,20};

    nodoArbol* arbol = inicArbol();

    for(int i=0; i < 10; i++){
        arbol = agregarNodoArbol(arbol, crearNodoArbol(a[i]));
    }


    printf("Nuestro primer arbol \n");
    printf("\n PreOrder \n");
    preOrder(arbol);

    printf("\n InOrder \n");
    inOrder(arbol);

    printf("\n PostOrder \n");
    postOrder(arbol);

    return 0;
}
