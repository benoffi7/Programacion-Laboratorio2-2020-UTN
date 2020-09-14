#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rta;

    suma(10,15,&rta);

    printf("El resultado de la suma es: %d" , rta);


}

void suma (int a, int b, int * resultado)
{
    *resultado = a + b + 15;
}
