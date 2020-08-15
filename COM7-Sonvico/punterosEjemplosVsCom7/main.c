#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void cargaRandom(int A[], int dim);
int cuentaPares(int A[], int val);
void mostrarArreglo(int  A[], int val);
int pasarPares(int original[], int validos, int ** arregloNuevo);

int main()
{
//    printf("Hello world!\n");
//
//
//    int * p = (int *) malloc(sizeof(int));
//
//    printf("contenido  p : % p\n", p);
//
//    /// *p = 126;
//
//    scanf("%d", p);
//
//    printf("contenido  de la variable anonima : % d\n", *p);
//
//
//    int * unArregloDinamico = (int *) calloc(20, sizeof(int));
//
//    printf("donde inicia el array dinamico %p", unArregloDinamico);
//
//    for (int i=0; i<20; i++)
//    {
//        unArregloDinamico[i]=rand()%100;
//    }
//
//    for (int i=0; i<20; i++)
//    {
//        printf(" %d", unArregloDinamico[i]);
//    }


    /// puntero doble
//    int x = 10;
//
//    int z =30;
//
//    int * p;
//
//    int **t;
//
//    p = &x;
//
//    t = &p;
//
//    printf(" %d\n", **t);
//
//    **t=20;
//
//    printf("%d\n", x);
//
//    *t=&z;
//
//

    int validosNuevo=0;
    int unArregloEstatico[100];

    cargaRandom(unArregloEstatico, 100);

    mostrarArreglo(unArregloEstatico, 100);

    int * arrayDinamicoPares=NULL;

    printf("\nCantidad de pares %d\n", cuentaPares(unArregloEstatico, 100));

    validosNuevo=pasarPares(unArregloEstatico, 100, &arrayDinamicoPares);

    mostrarArreglo(arrayDinamicoPares, validosNuevo);

    return 0;
}

void cargaRandom(int * A, int dim)
{
    srand(time(NULL));

    for(int i=0; i<dim; i++)
    {
        A[i]=rand()%100;
    }
}

void mostrarArreglo(int * A, int val)
{

    printf("\nContenido del arreglo:\n");
    for(int i=0; i<val; i++)
    {
        if(i%10==0)
            printf("\n");
        printf("%d ",A[i]);

    }
}

int cuentaPares(int * A, int val)
{
    int rta=0;
    for(int i=0; i<val; i++)
    {
        if(A[i]%2==0)
            rta++;
    }
    return rta;
}

int pasarPares(int original[], int validos, int ** arregloNuevo)
{
    int iOriginal=0, iNuevo=0;
    int cantPares=cuentaPares(original, validos);

    *arregloNuevo=(int *) malloc(sizeof(int)*cantPares);

    for(iOriginal=0; iOriginal<validos; iOriginal++)
    {
        if(original[iOriginal]%2==0)
        {
            (*arregloNuevo)[iNuevo]=original[iOriginal];
            iNuevo++;
        }
    }
    return iNuevo;
}

