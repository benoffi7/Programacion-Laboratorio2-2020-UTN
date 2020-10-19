#include <stdio.h>
#include <stdlib.h>
#include "arbolABB.h"



int main()
{
   nodoA* A=NULL;
   insertarABB(&A,3);
   insertarABB(&A,5);
   insertarABB(&A,1);
   insertarABB(&A,7);
   printf("%d",minimoABB(A));
   eliminarGrado1uHoja(&A,7);
    return 0;
}
