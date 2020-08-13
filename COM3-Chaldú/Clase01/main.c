#include <stdio.h>
#include <stdlib.h>

void inicializoArreglo(int a[], int dim);
void muestraArregloEnteros(int a[], int v);
void cargaArregloEnteros(int a[], int dim);
void muestraArregloValidoEnteros(int a[]);

int main()
{
    int arregloEnteros[100];  /// lowerCamelCase

    inicializoArreglo(arregloEnteros, 100);

    cargaArregloEnteros(arregloEnteros, 100);

    muestraArregloValidoEnteros(arregloEnteros);
    printf("\n");
    muestraArregloEnteros(arregloEnteros, 100);

    printf("Hello world!\n");
    return 0;
}


/********************************************************************//**
/* \brief Esta funcion inicializa un arreglo de enteros con el valor -1
/* \param a[] un arreglo de enteros
/* \param int dim la dimension del arrelgo
/* \return void
/**********************************************************************/

void inicializoArreglo(int a[], int dim){
    for(int i=0;i<dim;i++){
        a[i]=-1;
    }
}

/********************************************************************//**
/* \brief Esta funcion muestra un arreglo de enteros
/* \param a[] un arreglo de enteros
/* \param int v los validos del arrelgo
/* \return void
/**********************************************************************/
void muestraArregloEnteros(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%15 == 0){
            printf("\n");
        }
        printf(" %d", a[i]);
    }
}

/********************************************************************//**
/* \brief Esta funcion muestra un arreglo de enteros validos
/* \param a[] un arreglo de enteros
/* \return void
/**********************************************************************/
void muestraArregloValidoEnteros(int a[]){
    int i=0;
    while(a[i]>-1){
        if(i%10 == 0){
            printf("\n");
        }
        printf(" %d", a[i]);
        i++;
    }
}

/********************************************************************//**
/* \brief Esta funcion suma los elementos de un arreglo de enteros validos
/* \param a[] un arreglo de enteros
/* \return total
/**********************************************************************/
int sumaArregloValidoEnteros(int a[]){
    int i=0;
    int total=0;
    while(a[i]>-1){
        total+=a[i]; /// total = total + a[i]
        i++;
    }
    return total;
}


/********************************************************************//**
/* \brief Esta funcion permite al usuario la carga del arreglo con nros positivos
/* \param a[] un arreglo de enteros
/* \param int dim la dimension del arrelgo
/* \return void
/**********************************************************************/
void cargaArregloEnteros(int a[], int dim){
    int i=0;
    char opcion;

    do{
        system("cls");
        printf("\n Ingrese un nro entero positivo ");
        do{
            scanf("%d",&a[i]);
        }while(a[i]<0);
        i++;

        printf("\n ESC para salir....");
        opcion=getch();
    }while(opcion!=27);
}
