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

#define DIM 60000

int main()
{
/*
    int i=10;
    int j=0;

    printf("\n i=%d - j=%d", i, j); /// 11 - 10

    j=i++; /// primer asigna i a j y luego incremente i
    j=++i; /// primero incrementa i y luego asigna i a j

*/


    int a[DIM];
    int vA=0;
    int f=5;


    printf("\n El factorial de %d es %d \n", f, factorialPro(f));

    vA = cargaArregloRandom(a,vA,DIM);
/*
    printf("\n Muestra arreglo iterativo........ \n");
    muestraArregloIterativo(a,vA);

    printf("\n Muestra arreglo recursivo........ el menor es %d\n", buscaMenorPro(a,vA,0));
    muestraArregloRecursivo(a,vA,0);
*/


//   printf("\n %d", sumaArregloIterativo(a,vA));
//  printf("\n %d", sumaArregloRecursivo(a,vA,0));
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
    return (x==0) ? 1 : x*factorialPro(x-1);
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
    return (i<v) ? a[i]+sumaArregloRecursivoPro(a,v,i+1) : 0;
}


int capicua(int a[], int i, int u){
    int rta=1;
    if(i<u){
        if(a[i]==a[u]){
            rta=capicua(a,i+1,u-1);
        }else{
            rta=0;
        }
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
        menor=buscaMenor(a, v, i+1);
        if(a[i]<menor){
            menor = a[i];
        }
    }
    return menor;
}

int buscarMenor(int array[],int validos,int i,int menor){
    if(i<validos){
        if(array[i] <= menor){
            menor = array[i];
        }
        menor = buscarMenor(array,validos,i+1,menor);
    }
    return menor;
}

int buscaMenorPro(int a[], int v, int i){
    return (i==v-1) ? a[i] : menor(buscaMenorPro(a,v,i+1), a[i]);
}


int menorEnArchivo (FILE *arch)
{
    int menor;
    int aux;
    if(fread(&aux,sizeof(int),1,arch)==0) /// cuando llego al final del archivo
    {
        /// me muevo uno para atras
        fseek(arch, -1*sizeof(int), SEEK_END);
        /// lo leo
        fread(&menor, sizeof(int),1,arch); /// leo el ultimo elemento para retornarlo
    }
    else
    {
        menor = menorEnArchivo(arch);

        if(aux<menor)
        {
            menor=aux;
        }
    }
    return menor;
}

int cuentaRegistroArchivo(FILE * arch)
{
    int cant=0;

    fseek(arch, 0, SEEK_END);
    cant=ftell(arch)/sizeof(int);

    return cant;
}

int leer(FILE * arch)
{
    int aux;
    fread(&aux, sizeof(int),1,arch);
    return aux;
}

void escribir(FILE *arch, int valor)
{
    fwrite(&valor, sizeof(int), 1, arch);
}

void invierteArchivo(FILE *arch, int i, int u)
{
    /// la condicion de corte con su solucion final no queda explicita
    /// pero la idea es: contar la cantidad de registros en el archivo
    /// e ir leyendo, intercambiando y escribiendo desde el ppio hacia el final y
    /// viceversa
    int ppio;
    int fin;
    if(i<u)
    {
        /// posiciono el cursor en el extremo inferior del archivo
        fseek(arch,i*sizeof(int),SEEK_SET);
        /// leemos el primer dato
        ppio=leer(arch);

        /// ahora en el extremo superior del archivo
        fseek(arch, u*sizeof(int),SEEK_SET);
        /// ahora el segundo
        fin=leer(arch);

        /// y ahora hacemos el intercambio

        /// posiciono el cursor en el extremo inferior del archivo
        fseek(arch,i*sizeof(int),SEEK_SET);
        /// escribo el dato del final en el ppio
        escribir(arch, fin);

        /// ahora en el extremo superior del archivo
        fseek(arch, u*sizeof(int),SEEK_SET);
        /// y el del ppio en el final
        escribir(arch, ppio);

        /// ahora hacemos la llamada recursiva
        /// con la aproximacion a la condicion de corte
        invierteArchivo(arch, i+1, u-1);
    }
}

void ingresaPorTecladoYMuestra()
{
    char valor;
    printf("\nIngrese un caracter: ");
    fflush(stdin);
    scanf("%c", &valor);

    /* if(valor=='*')
     {
         printf("%c ",valor);
     }
     else
     {
         ingresaPorTecladoYMuestra();
         printf("%c ",valor);
     }*/

    // esta tambien es valida... no se ve de forma explicita la cond. de corte

    if(valor!='*')
    {
        ingresaPorTecladoYMuestra();
        printf("%c ",valor);
    }
}

// 12. Determinar si un arreglo contiene un determinado elemento.
// la funcion retorna 0 si no lo encuentra, 1 si el elemento esta

int determinaElementoEnArreglo(int A[], int cant, int i, int valor)
{
    int rta=0; // supongo que el elemento no esta
    if(i<cant)
    {
        if(A[i]==valor)
        {
            rta=1;
        }
        else
        {
            rta=determinaElementoEnArreglo(A, cant,i+1, valor);
        }
    }
    return rta;
}

int determinaElementoEnArregloPro(int A[], int cant, int i, int valor)
{
    int rta=0; // supongo que el elemento no esta
    if(i<cant)
    {
        rta = (A[i]==valor) ? 1 : determinaElementoEnArregloPro(A, cant,i+1, valor);
    }
    return rta;
}


int impar (int num)
{
    if (num==0)
    {
        return 0;
    }
    else
    {
        return par(num-1);
    }
}

int par (int num)
{
    if (num==0)
    {
        return 1;
    }
    else
    {
        return impar(num-1);
    }
}
