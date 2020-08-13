#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 20
#define FIL_MAX 12
#define COL_MAX 31

#define MAX_PARAL 15

/*puntoa*/

void inicializar(int arreglo[])
{
   for (int i =0; i < TAM_MAX ; i++)
   {
       arreglo[i]=-1;
   }
}

/*puntob*/
int ingreso(int arreglo[])
{
    int i=0;
    char continuar='s';
    while (continuar == 's' && i < TAM_MAX)
    {
        printf("ingrese un valor entero\n");
        fflush(stdin);
        scanf("%d",&arreglo[i]);
        printf("desea continuar?s\n");
        fflush(stdin);
        scanf("%c",&continuar);
        i++;
    }
    return i;
}


int suma(int arreglo[], int validos)
{
    int sum=0;
    for (int i =0; i < validos; i++)
        sum = sum + arreglo[i];

    return sum;

}


float promedio(int arreglo[], int validos)
{
   int sum = suma(arreglo,validos);
   float prom = (float)sum / validos;

    return prom;
}

int retMax(int arreglo[],int validos)
{
    int max;
    int posMax=-1;
    if (validos > 0)
    {
        max=arreglo[0];
        posMax=0;
        for (int i=0; i < validos; i ++)
        {
            if (max < arreglo[i])
            {
                max = arreglo[i];
                posMax= i;
            }
        }

    }

     return posMax;
}


int ingresoMatriz(int mat[][COL_MAX])
{
    char continuar='s';
    int i =0;
    while (i < FIL_MAX && continuar == 's')
    {
        for (int j=0; j< COL_MAX; j++)
        {
            printf("Ingrese la precipitacion correspondiente a el mes %d dia %d\n", i,j);
            fflush(stdin);
            scanf("%d", &mat[i][j]);
        }
        i++;
        printf("desea seguir ingresando valores s/n\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }

    return i;
}

void muestraMatriz(int mat[][COL_MAX],int validosF)
{
    for (int i =0; i < validosF; i++)
    {
        for (int j = 0; j < COL_MAX; j++)
            printf("%d ",mat[i][j]);

        printf("\n");
    }
}


int cargaParalelos(char mat[][10],int edad[])
{
    int i=0;
    char continuar='s';
    while (continuar == 's' && i < MAX_PARAL)
    {
        printf("ingrese nombre\n");
        fflush(stdin);
        gets(mat[i]);
        printf("Ingrese edad\n");
        fflush(stdin);
        scanf("%d",&edad[i]);
        i++;
    }

   return i;
}




int main()
{
      char mat[15][10];
      int edad[15];
      int validos=0;

      validos=cargaParalelos(mat,edad);


//    int mat[12][31]={0};
//    int validosF=0;
//    validosF=ingresoMatriz(mat);
//    muestraMatriz(mat,validosF);

//    int arreglo[20] = {0,7,8,9};
//    int validos=0;
//    float prom;
//    inicializar(arreglo);
//    validos=ingreso(arreglo);
//    prom= promedio(arreglo,validos);
//    printf("%.2f", prom);
    return 0;
}
