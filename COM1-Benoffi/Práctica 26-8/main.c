#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[] = {1,8,95,64,15};

    //mostrarArreglo(arreglo,5,0);

    printf("El número 3 es impar: %d\n", impar(3) );

    printf("El número 3 es par: %d\n", par(3) );

    printf("El número 4 es impar: %d\n", impar(4) );

    printf("El número 4 es par: %d\n", par(4) );


    if (x%2 == 0)
        printf("Es par");
    else

        printf("Es impar");
}


void mostrarArreglo (int a[], int validos, int i)
{
    if (i < validos)
    {
        printf("[ %i ]", a[i]);
        mostrarArreglo(a,validos,i+1);
    }
}
void mostrarArregloInvertido (int a[], int validos, int i)
{
    if (i < validos)
    {
        mostrarArreglo(a,validos,i+1);
        printf("[ %i ]", a[i]);
    }
}

int factorial (int x)
{
    int rta;
    if (x==1)
        rta = 1;
    else
        rta = x * factorial(x-1);

    return rta;
}

int sumarArreglo (int a[], int validos, int i)
{
    int suma = 0;
    if (i < validos)
    {
        suma = a[i] + sumarArreglo(a,validos,i+1);
    }
    return suma;
}

int par (int x)
{
    int rta;
    if (x == 0)
        rta = 1;
    else
        rta = impar (x-1);

    return rta;
}

int impar (int x)
{
    int rta;
    if (x == 0)
        rta = 0;
    else
        rta = par (x-1);

    return rta;

}

