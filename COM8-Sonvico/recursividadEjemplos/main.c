#include <stdio.h>
#include <stdlib.h>


int factorial(int x)
{
    int rta;

    if(x==0)  /// condicion de corte
    {
        rta=1;              /// solucion trivial
    }
    else
    {
        rta= x * factorial(x-1);
    }
    return rta;
}

int sumaArregloIterativo(int A[], int validos)
{
    int suma;

    int i=0;

    if(i==validos)
    {
        suma=0;
    }
    else
    {
        for(i=0; i<validos; i++)
        {
            suma=suma+A[i];
        }
    }
    return suma;
}

int sumaArregloRecursivo(int A[], int validos, int i)
{
    int suma;
    int sumaParcial;

    if(i==validos)
    {
        suma=0;
    }
    else
    {
        sumaParcial=sumaArregloRecursivo(A,validos,i+1);

        suma=A[i]+sumaParcial;
    }

    return suma;
}

int sumaArregloRecursivaOtra(int A[], int validos, int i)
{
    int suma=0;

    if(i<validos)
    {
        suma=A[i]+sumaArregloRecursivaOtra(A,validos,i+1);
    }

    return suma;
}

void mostrarArregloRecursivo(int A[], int validos, int i)
{
    if(i<validos)
    {
        printf(" %d", A[i]);
        mostrarArregloRecursivo(A, validos, i+1);
    }
}

void mostrarArreglo(int A[], int validos)
{
    int i;
    for(i=0;i<validos;i++)
    {
        printf(" %d", A[i]);
    }
}

int potencia (int x, int i) /// punto 2
{
    int poten=0;

    if(i==0)
    {
        poten=1;
    }
    else
    {
        poten=x*potencia(x,i-1);

    }
    return poten;
}
/* otra posibilidad de algoritmo
if(exponente==0)
    rta=1;
else if(exponente==1)
    rta=base;
else
    rta=base*fnrecursiva(base, exponente-1);*/

int main()
{
    printf("Hello recursividad!\n");

    int arreglo[]= {1,2,3,4,5,6,7,8,9,10};

 //   mostrarArregloRecursivo(arreglo, 10, 0);
    mostrarArreglo(arreglo, 10);
    return 0;
}
