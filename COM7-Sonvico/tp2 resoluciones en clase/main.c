#include <stdio.h>
#include <stdlib.h>

/**
1. Dada la estructura struct persona{ char nombre[30]; char genero; int edad;};.
a. Crear un arreglo de 30 elementos de esta estructura y cargarlo mediante una función.
b. Hacer una función que cuente la cantidad de varones o mujeres que hay.
c. Hacer una función que copie los datos de todos los varones del arreglo anterior
en otro arreglo del tamaño justo. Usar malloc dentro de la función y retornarlo o
usar dos parámetros de tipo arreglo y crear el arreglo dinamico antes de la invocación.
*/
typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

int cargarArregloPersonas(persona A[], int dim)
{
    int i=0;
    char control='s';

    printf("\nCargar el arreglo de personas:");

    while(i<dim&&control=='s')
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s",&A[i].nombre);

        printf("\nIngrese genero: ");
        fflush(stdin);
        scanf("%c",&A[i].genero);

        printf("\nIngrese edad: ");
        scanf("%d",&A[i].edad);

        i++;

        printf("\nDesea continuar? ");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}

void muestraArregloPersonas(persona A[], int val)
{
    int i=0;

    printf("\nContenido del arreglo de personas: \n");
    for(i=0; i<val; i++)
    {
        printf("\nNombre: %s", A[i].nombre);
        printf("\ngenero: %c", A[i].genero);
        printf("\nEdad: %d", A[i].edad);
    }
}

int cuentaPorgenero(persona A[], int val, char genero)
{
    int i=0;
    int cantidad=0;

    for(i=0; i<val; i++)
    {
        if(genero==A[i].genero)
        {
            cantidad++;
        }
    }
    return cantidad;
}

void pasaPorgenero(persona A[], int validosA, persona Porgenero[], char genero)
{
    int i=0; /// uno para el arreglo completo
    int x=0; /// uno para el arreglo por genero

    for(i=0; i<validosA; i++)
    {
        if(A[i].genero==genero)
        {
            Porgenero[x]=A[i]; // se pasa la estructura por completo...
            x++;
        }
    }
}

persona * pasaPorgeneroPuntero (persona A[], int validosA, char genero)
{
    int cantidadgenero = cuentaPorgenero(A, validosA, genero);

    persona * lista =  malloc(cantidadgenero * sizeof(persona));

    int i=0;
    int x=0;

    for(i=0; i<validosA; i++)
    {
        if(A[i].genero==genero)
        {
            lista[x]=A[i]; // se pasa la estructura por completo...
            x++;
        }
    }

    return lista;
}
                                                  /// 1024
int otra (persona A[], int validosA, char genero, persona * * listado)
{
    int cantidadgenero = cuentaPorgenero(A, validosA, genero);

    *listado = malloc(cantidadgenero * sizeof(persona));

    int i=0;
    int x=0;

    for(i=0; i<validosA; i++)
    {
        if(A[i].genero==genero)
        {
            (*listado)[x]=A[i]; // se pasa la estructura por completo...
            x++;
        }
    }
    return x;
}

/* 2. codificar el algoritmo de ordenamiento por selección, sobre la estructura
anterior teniendo en cuenta la edad.
*/

int posMenor(persona A[], int validos, int pos)
{
    persona menor=A[pos];
    int posicionMenor=pos;
    int i = pos+1;
    while(i<validos)
    {
        if(menor.edad>A[i].edad)
        {
            menor=A[i];
            posicionMenor=i;
        }
        i++;
    }
    return posicionMenor;
}

void ordenacionPorSeleccion(persona A[], int validos)
{
    int i=0;
    persona aux;
    int pos=0;
    while(i<validos-1)
    {
        pos=posMenor(A, validos, i);
        aux=A[pos];
        A[pos]=A[i];
        A[i]=aux;
        i++;
    }
}

/**

3. simular el uso de una pila de enteros a partir de la siguiente estructura:
a. typedef struct
{   int valores[100];
    int posTope; //posición de nuevo tope, o sea, lugar en donde se
    almacenará el nuevo valor
}Pila;

b. implementar las siguientes funciones:
void apilar(Pila *p; int valor);
int desapilar(Pila *p);
int tope(Pila * p);
int pilavacia(Pila * p);
void mostrar(Pila * p);
void leer (Pila * p);
void inicPila(Pila *p);
*/

/// todo esto se puede escribir en archivos .h y .c, para crear la libreria
typedef struct
{
    int valores[100];
    int posTope; ///posición de nuevo tope, o sea, lugar en donde se almacenará el nuevo valor
} Pila;


void apilar(Pila *p, int valor)
{
    if(p->posTope<100)
    {
        p->valores[p->posTope]=valor;
        p->posTope++;
    }
    else
    {
        printf("\nLa pila esta llena...");
    }

}

void leer(Pila * p)
{
    int dato;
    printf("Ingrese un valor entero: ");
    scanf("%d", &dato);
    apilar(p, dato);
}

int desapilar(Pila *p)
{
    int rta=0;

    rta=p->valores[p->posTope-1];

    p->posTope--;

    return rta;
}

int tope(Pila * p)
{
    int rta=0;

    rta=p->valores[p->posTope-1];

    return rta;
}

int pilavacia(Pila * p)
{
    int rta=0;

    if(p->posTope==0)
    {
        rta=1;
    }

    return rta;
}
void mostrar(Pila * p)
{
    int i=0;

    printf("\nBase..............................................Tope\n");

    while(i<p->posTope)
    {
        printf("| %d ", p->valores[i]);
        i++;
    }

    printf("|\nBase..............................................Tope\n");
}


void inicPila(Pila * p)
{
    p->posTope=0;
   // (*p).posTope=0;
}

/*
4. Dadas dos pilas (como las anteriores) que se supone que tienen sus datos ordenados,
 generar una tercer pila que contenga los datos de las dos anteriores intercalados,
 de forma tal que queden ordenados.
*/

void intercalarPilas(Pila *a, Pila * b, Pila * destino)
{
     while(!pilavacia(a)&&!pilavacia(b))
    {
        if (tope(a)<tope(b))
        {
            apilar(destino, desapilar(a));
        }
        else
        {
            apilar(destino, desapilar(b));
        }
    }

    // ahora evaluo si quedo algo en alguna de las dos pilas

    if(!pilavacia(a))
    {
        while(!pilavacia(a))
            apilar(destino, desapilar(a));
    }
    else
    {
        while(!pilavacia(b))
            apilar(destino, desapilar(b));
    }
}

/*
5. Función insertar en orden en un arreglo.
*/


int agregaEnOrden (int A[], int validos, int dato)
{
    int i = validos-1;
    while (i>=0 && dato<A[i])
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]= dato;
    return validos+1;
}


/// ordenacion por insercion sonbre personas
void agregaEnOrdenPersona (persona A[], int validos, persona dato)
{
    int i = validos-1;
    while (i>=0 && dato.edad<A[i].edad)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]= dato;
}

void ordenacionInsercionPersona (persona A[], int c)
{
    int u = 0;
    while (u<c-1)
    {
        agregaEnOrdenPersona(A,u,A[u+1]);
        u++;
    }
}

/*
6. Algoritmo de ordenamiento por inserción.
*/

void insertar(int A[], int u, int dato)
{
    int i = u;
    while(i>=0 && dato <A[i])
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=dato;
}

void ordenacionInsercion (int A[], int c)
{
    int u = 0;
    while (u<c-1)
    {
        insertar(A,u,A[u+1]);
        u++;
    }
}
/*
7. Función eliminar un elemento de un arreglo.
*/

/// 4  2  1  1  12  35  35

///[0][1][2][3][4][5][6][7][8][9][10]


int eliminaElementoDeArreglo(int A[], int validos, int posAeliminar)
{
    int i=posAeliminar;
    // validamos que la pos ingresada sea valida...
    if(i<validos)
    {
        while(i<validos-1)
        {
            A[i]=A[i+1];
            i++;
        }

        validos--;
    }

    return validos;
}

/// Sistema de notas.... plantearlo en clases y ver resolucion del alumnado...

int main()
{
    printf("Hello practico 2!\n");

    persona Listado[30];
    int validos=0;

    validos=cargarArregloPersonas(Listado,30);
    muestraArregloPersonas(Listado, validos);

    int cantidadgenero= cuentaPorgenero(Listado, validos, 'm'); // voy a pasar los varones
    int cantidadgeneroF= cuentaPorgenero(Listado, validos, 'f'); // voy a pasar los


    printf("\nHay %d varones en el listado grande..", cantidadgenero);

    persona * listaVarones = malloc(cantidadgenero * sizeof(persona));

    pasaPorgenero(Listado,validos, listaVarones, 'm');

    muestraArregloPersonas(listaVarones, cantidadgenero);


      persona * listaMujeres = pasaPorgeneroPuntero(Listado, validos, 'f');

      muestraArregloPersonas(listaMujeres, cantidadgeneroF);


                             /// donde vive   /// contenido
      persona * ultimo=NULL;  /// 1024        /// NULL

      int u = otra(Listado, validos, 'm', &ultimo);

      muestraArregloPersonas(ultimo, u);

    ordenacionPorSeleccion(Listado, validos);

    muestraArregloPersonas(Listado, validos);

    Pila pilita;

    inicPila(&pilita);
    apilar(&pilita, 10);
    apilar(&pilita, 9);
    apilar(&pilita, 7);
    apilar(&pilita, 5);
    apilar(&pilita, 3);
    apilar(&pilita, 1);

    mostrar(&pilita);

     Pila pilota;

    inicPila(&pilota);
    apilar(&pilota, 11);
    apilar(&pilota, 8);
    apilar(&pilota, 6);
    apilar(&pilota, 4);
    apilar(&pilota, 3);
    apilar(&pilota, 2);

    mostrar(&pilota);

    Pila requetepilita;
    inicPila(&requetepilita);

    intercalarPilas(&pilita, &pilota, &requetepilita);

   mostrar(&pilita);
   mostrar(&pilota);
   mostrar(&requetepilita);


    return 0;
}
