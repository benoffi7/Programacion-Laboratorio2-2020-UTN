#include <stdio.h>
#include <stdlib.h>


int factorial (int x)
{

    int rta;

    if(x==0)
    {
        rta=1;
    }
    else
    {
        rta=x*factorial(x-1);
    }
    return rta;
}

void mostrarArregloRecursivo(int A[], int validos, int i)
{
    if(i==validos-1)
    {
        printf("%d ", A[i]);
    }
    else
    {
        printf("%d ", A[i]);
        mostrarArregloRecursivo(A, validos, i+1);

    }
}

void mostrarArregloRecursivoInvertido(int A[], int validos, int i)
{
    if(i==validos-1)
    {
        printf("%d ", A[i]);
    }
    else
    {
        mostrarArregloRecursivoInvertido(A, validos, i+1);
        printf("%d ", A[i]);
    }
}

///   int unArreglo[5]= {10,20,30,40,50};

int sumarArregloRecursivo(int A[], int validos, int i)
{
    int rta;

    if(i==validos) ///cc
    {
        rta=0;   /// st
    }else
    {
        rta=A[i]+sumarArregloRecursivo(A, validos, i+1);
    }

    return rta;


}

int sumarArregloRecursivo(int A[], int validos, int i)
{
    int rta=0;   /// si no hay arreglo, la suma es cero
    /// cond. de corte y sol trivial implicita

    if(i<validos)
    {
        rta=A[i]+sumarArregloRecursivo(A, validos, i+1);
    }
    return rta;
}




/// ojo con el parametro viajero...
/// no utilizar
int sumarRecursivo (int a[],int cant,int i,int suma)
{
    if(i<cant){
        suma=a[i] + sumarRecursivo(a,cant,i+1,suma);
    }
    return suma;
}




int main()
{
    printf("Hello world!\n");

    int valorFactorizado=factorial(15);

    int unArreglo[5]= {10,20,30,40,50};

    mostrarArregloRecursivoInvertido(unArreglo, 5, 0);

    system("pause");

    printf("%d", valorFactorizado);
    return 0;
}
