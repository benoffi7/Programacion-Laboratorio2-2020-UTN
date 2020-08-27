#include <stdio.h>
#include <stdlib.h>

int cargaArregloRandom(int a[],int v, int dim);
void muestraArregloIterativo(int a[], int v);
void muestraArregloRecursivo(int a[], int v, int i);
int sumaArregloIterativo(int a[], int v);
int sumaArregloRecursivo(int a[], int v, int i);
int sumaArregloRecursivoPro(int a[], int v, int i);
int menor(int a, int b);
int buscaMenor(int a[], int v, int i);

#define DIM 40000

int main()
{
    /*
    int i=5;
    int j=0;

    j=i++; /// primer asigna i a j y luego incremente i
    j=++i; /// primero incrementa i y luego asigna i a j
    printf("\n %d - %d", i, j); /// 6 - 6
    */

    int a[DIM];
    int vA=0;
    int f=5;


    printf("\n El factorial de %d es %d \n", f, factorial(f));

    vA = cargaArregloRandom(a,vA,DIM);
/*
    printf("\n Muestra arreglo iterativo........ \n");
    muestraArregloIterativo(a,vA);

    printf("\n Muestra arreglo recursivo........ el menor es %d\n", buscaMenor(a,vA,0));
    muestraArregloRecursivo(a,vA,0);
*/


//   printf("\n %d", sumaArregloIterativo(a,vA));
//   printf("\n %d", sumaArregloRecursivo(a,vA,0));
//   printf("\n %d", sumaArregloRecursivoPro(a,vA,0));

    printf("\nHello world!\n");
    return 0;
}

int factorial(int x){
    int rta;
    if(x==0){
        rta=1;
    }else{
        rta=x*factorial(x-1);
    }
    return rta;
}

int factorialPro(int x){
    return (x==0)?1:x*factorial(x-1);
}

int cargaArregloRandom(int a[],int v, int dim){
    for(;v<dim;v++){
        a[v]=rand()%10;
    }
    return v;
}

void muestraArregloIterativo(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%c %d ", (i%10==0)?'\n':'-', a[i]);
    }
}

void muestraArregloRecursivo(int a[], int v, int i){
    if(i<v){
        printf("%c %d ", (i%10==0)?'\n':'-', a[i]);
        muestraArregloRecursivo(a,v,i+1); /// va i+1 NUNCA i++
    }
}

int sumaArregloIterativo(int a[], int v){
    int suma=0;
    for(int i=0;i<v;i++){
        suma+=a[i];   /// suma = suma + a[i]
    }
    return suma;
}

int sumaArregloRecursivo(int a[], int v, int i){
    int suma=0;
    if(i<v){
        suma=a[i]+sumaArregloRecursivo(a,v,i+1);
    }
    return suma;
}

int sumaArregloRecursivoPro(int a[], int v, int i){
    return (i<v) ? a[i]+sumaArregloRecursivo(a,v,i+1) : 0;
}


int capicua(int a[], int i, int u){
    int rta=1;
    if(i==u){
        rta=capicua(a,i+1,u-1);
    }

    return rta;
}



int menor(int a, int b){
    return (a<b)?a:b;
}

int buscaMenor(int a[], int v, int i){
    int menor;
    if(i==v-1){
        menor=a[i];
    }else{
        menor=buscaMenor(a[], v, i+1);
        if(a[i]<menor){
            menor = a[i];
        }
    }
    return menor;
}


int buscaMenor(int a[], int v, int i){
    return (i==v-1)?a[i]:menor(buscaMenor(a,v,i+1), a[i]);
}
