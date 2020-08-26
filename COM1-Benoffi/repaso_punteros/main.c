#include <stdio.h>
#include <stdlib.h>

int main()
{



    printf("Hello world!\n");
    int a = 10;
    printf(" a es %d\n",a);
    printf("la dirección de memoria de a es %d\n",&a);

    int * puntero ;
    printf("la dirección de memoria de p es %d\n",&puntero);

    puntero = &a;
    printf(" p es %d\n",puntero);

    (*puntero) = 20;

    printf(" a es %d\n",a);

    return 0;
}
