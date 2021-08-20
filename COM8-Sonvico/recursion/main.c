#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Hello world!\n");

    int rta=primerEjemplo(0,5);
    printf("rta en el main= %d\n", rta);

    return 0;
}

int primerEjemplo(int acercamiento, int corte)
{
    int rta=0;
    if (acercamiento<corte)
    {
        printf("rta en la fn= %d\n", rta);
        rta=primerEjemplo(acercamiento+1,corte);
    }
    else
    {
        rta=1;
    }
    return rta;
}
