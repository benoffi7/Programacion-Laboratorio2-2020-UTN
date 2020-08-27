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




int buscaMenorEnArreglo(int A[], int validos, int i)
{
    int menor;

    if(i==validos-1)
    {
        menor=A[i];
    }else
    {
        menor=buscaMenorEnArreglo(A, validos, i+1);

        if(A[i]<menor)
        {
            menor=A[i];
        }
    }

    return menor;

}

///From Bruno Iván Fabrizio to Everyone:  09:17 PM
int arregloCapicua(int A[], int i, int u)
{
    int flag=1;  /// lo supone capicua

    if(i<u)
    {
        if(A[i]!=A[u])
        {
            flag=0
        }
        else
        {
            flag=arregloCapicua(A, i+1, u-1);

        }
    }

    return flag;
}

///From Nico Tesone to Everyone:  09:22 PM

int ArrayCapicua_Recursivo (int a[], int validos,int i)
{
    //fn que determian si un arreglo es capicua o no de forma recursiva y devuelve, 1 capicua | 0 no es capicua.

    int rta=1;

    if(i<=validos/2)
    {

        if(a[i]==a[validos-1-i])
        {
            rta=ArregloCapicua_Recursivo(a,validos,i+1);
        }
        else
        {
            rta=0;
        }
    }
    return rta;
}

/// 5 Determinar en forma recursiva si un arreglo es capicúa
int capicua (int A[], int i, int u)
{
    int rta;
    if(i<u)
    {
        if(A[i]==A[u])
        {
            rta=capicua(A,i+1,u-1);
        }
        else
        {
            rta=0;  /// A[i]!=A[u]   no es capicua
        }
    }
    else  /// i>=u
    {
        rta=1; /// es capicua
    }
    return rta;
}

int otrocapicua(int A[], int i, int u)
{
    int rta=1;
    if(i<u)
    {
        if(A[i]==A[u])
        {
            rta=otrocapicua(A,i+1,u-1);
        }
        else
        {
            rta=0;
        }
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
