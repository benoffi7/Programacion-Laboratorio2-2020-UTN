#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaRandom(int A[], int dim);
int cuentaPares(int A[], int val);
void mostrarArreglo(int  A[], int val);

int * pasarPares (int A[], int validos);

int main()
{

//    printf("Hello world!\n");
//
//
//    int x;
//
//    int *p;
//
//    x=10;
//    printf("x: %d\n", x);
//    p=&x;
//
//    x=20;
//    printf("x: %d\n", x);
//    *p=30;
//    printf("x: %d\n", x);


//    int * p_nuevo = malloc(sizeof(int));
//
//    printf("Contenido del puntero : %p\n", p_nuevo);
//
//    printf("Direccion del puntero : %p\n", &p_nuevo);
//
//    printf("Ingrese un valor entero: ");
//    scanf("%d", p_nuevo);
//
//    printf("variable anonima: %d\n", *p_nuevo);
//                   /// dir        // contenido

//    int a=10;       /// 1024      // 10
//    int b=90;        /// 256      // 90
//
//    int * p=&a;     /// 512       // 1024
//
//    int ** pp = &p; /// 128       // 512
//
//    *p=34;
//
//    *pp=&b;
//
//
//    printf("Contenido de a: %d\n\n", a);
//
//    printf("Contenido de lo que apunta p: %d", *p);


///    int unArregloDeInts[100];

    int * unArregloDeInts = calloc(100, sizeof(int));

    cargaRandom(unArregloDeInts, 100);

    mostrarArreglo(unArregloDeInts, 100);

    int pares=cuentaPares(unArregloDeInts, 100);

    printf("\nLa cantidad de elementos pares del arreglo es %d\n",pares );

//    int * unArregloDePares=pasarPares(unArregloDeInts, 100);
//
//    mostrarArreglo(unArregloDePares, pares);


    int * miNuevoArregloDinamico=NULL;

    int validos=pasarParesPorPunteroDoble(unArregloDeInts, 100, &miNuevoArregloDinamico);

    mostrarArreglo(miNuevoArregloDinamico, validos);

    return 0;
}
              ///int * A
void cargaRandom(int A[], int dim)
{
    srand(time(NULL));

    for(int i=0; i<dim; i++)
    {
        A[i]=rand()%100;
    }
}

void mostrarArreglo(int  A[], int val)
{

    printf("\nContenido del arreglo:\n");
    for(int i=0; i<val; i++)
    {
        if(i%10==0)
            printf("\n");
        printf("%d ",A[i]);

    }
}

int cuentaPares(int A[], int val)
{
    int rta=0;
    for(int i=0; i<val; i++)
    {
        if(A[i]%2==0)
            rta++;
    }
    return rta;
}

int * pasarPares (int A[], int validos)
{
    int pares=cuentaPares(A, validos);

    int z=0;
    int * nuevoArreglo = malloc(sizeof(int)* pares);



    for(int i=0; i<validos;i++)
    {
        if(A[i]%2==0)
        {
            nuevoArreglo[z]=A[i];
            z++;
        }
    }

    return nuevoArreglo;
}

int pasarParesPorPunteroDoble(int A[], int validos, int ** pAunArreglo)
{
    int pares=cuentaPares(A, validos);

    int z=0;


    *pAunArreglo=malloc(sizeof(int)*pares);


    for(int i=0; i<validos;i++)
    {
        if(A[i]%2==0)
        {
            (*pAunArreglo)[z]=A[i];
            z++;
        }
    }

    return z;
}

