#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "cliente.h"
#include "archivoClientes.h"
#include "pila.h"
#include "stack.h"

#define AR_CLIENTES "clientes.dat"
#define DIM_CLI 100

void muestraMenu();
void cargaPila(Stack *s, int cantidad);
void muestraPila(Stack s);


int main()
{
    Stack s;
    initStack(&s);

    cargaPila(&s, 101);
    muestraPila(s);


    system("pause");
    stCliente *pArreglo=NULL;
    int vPA=0;

    stCliente clientes[DIM_CLI];
    int vCli = 0;
    Pila a;
    Pila b;
    inicpila(&a);
    inicpila(&b);
    apilar(&a,5);
    apilar(&a,6);
    apilar(&a,8);
    apilar(&a,1);
    copiaPila(a, &b);

    char opcion;

    do{
        system("cls");
        muestraMenu();

        opcion=getch();

        switch(opcion){
            case 49:
                cargaClientesArchivo();
                break;
            case 50:
                muestraClientesArchivo(AR_CLIENTES);
                break;
            case 51:
                vCli = cargaClientesArreglo(clientes, vCli, DIM_CLI);
                break;
            case 52:
                muestraClientesArreglo(clientes, vCli);
                break;
            case 53:
                vCli = archivoClientes2Arreglo(AR_CLIENTES, clientes, vCli, DIM_CLI);
                break;
            case 54:
                vCli = archivoCompletoClientes2Arreglo(AR_CLIENTES, clientes, DIM_CLI);
            case 55:
                pArreglo = archivoCompletoClientes2Arreglo1(AR_CLIENTES, pArreglo, &vPA);
                muestraClientesArreglo(pArreglo, vPA);
            case 56:
                vPA = archivoCompletoClientes2Arreglo2(AR_CLIENTES, &pArreglo, vPA);
                muestraClientesArreglo(pArreglo, vPA);
        }
        ///getch(); /// es una pausa
        system("pause");
    }while(opcion!=27);

    printf("Hello world!\n");
    return 0;
}

void muestraMenu(){
    printf("\n\t\t\t Menu Principal \n\n");
    printf("\n 1 - Carga archivo de Clientes");
    printf("\n 2 - Muestra archivo de Clientes");
    printf("\n 3 - Carga Arreglo de Clientes");
    printf("\n 4 - Muestra Arreglo de Clientes");
    printf("\n 5 - Copia Clientes del archivo en el Arreglo");
    printf("\n 6 - Copia todos los Clientes del archivo en el Arreglo");
    printf("\n 7 - Copia todos los Clientes del archivo en el Arreglo retornando el puntero");
    printf("\n 8 - Copia todos los Clientes del archivo en el Arreglo por refencia y retorna validos");

    printf("\n\n    ESC para salir.....");
}


void intercambio(stCliente *a, stCliente *b){
    stCliente aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

void copiaPila(Pila origen, Pila *destino){
    while(!pilavacia(&origen)){
        apilar(destino, desapilar(&origen));
    }
}

void cargaPila(Stack *s, int cantidad){
    for(int i=0;i<cantidad;i++){
        push(s, rand()%10);
    }
}

void muestraPila(Stack s){
    Stack aux;
    initStack(&aux);
    int i=0;

    while(!emptyStackPro(s)){
        if(i%10==0){
            printf("\n");
        }
        printf(" %d - ", topPro(s));
        i++;
        push(&aux, pop(&s));
    }
}

void muestraPilaPro(Stack s){
    Stack aux;
    initStack(&aux);
    int i=0;

    while(!emptyStackPro(s)){
        printf("%c %d ", (i%10==0) ? '\n' : '-',topPro(s));
        i++;
        push(&aux, pop(&s));
    }
}
