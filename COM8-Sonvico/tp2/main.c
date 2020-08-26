#include <stdio.h>
#include <stdlib.h>

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



int main()
{
    printf("Hello world!\n");

    return 0;
}
