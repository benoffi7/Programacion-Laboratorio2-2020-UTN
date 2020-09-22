#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "cliente.h"
#include "archivoClientes.h"
#include "registroArchivo.h"
#include "pila.h"
#include "fila.h"
#include "stack.h"
#include "listaClientes.h"
#include "pilaClientes.h"
#include "lista2.h"

#define AR_CLIENTES "clientes.dat"
#define DIM_CLI 100

void muestraMenu();
void cargaPila(Stack *s, int cantidad);
void muestraPila(Stack s);
void copiaPila(Pila origen, Pila *destino);
nodo* arreglo2lista(stCliente a[], int v, nodo* lista);
nodo* archivo2lista(char arClientes[], nodo* lista);
nodo* intercalarLista(nodo* listaA, nodo* listaB, nodo* listaC);
nodo* invertirLista(nodo* lista);
nodo* arreglo2listaPD(stCliente a[], int v, nodo* lista);
void archivo2listaPDBis(char arClientes[], nodo** lista);
void archivo2pilaCli(char arClientes[], PilaCli* p);
void muestraPilaCli(PilaCli* p);
void borrarNodosMenorA(nodo** lista, int limite);
nodo* borrarNodosSegunParametro(nodo * lista, int filtro);
nodo2* archivo2lista2(char arClientes[], nodo2* lista);
void pila2lista(PilaCli p, nodo** lista);

int main()
{
/*    Stack s;
    initStack(&s);

    cargaPila(&s, 101);
    muestraPila(s);


    system("pause");
*/
    stCliente *pArreglo=NULL;
    int vPA=0;
    PilaCli pila;
    inicPila(&pila);

    Fila filaClientes;
    inicFila(&filaClientes);


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
    nodo* listaClientes = inicLista();
    nodo* invertida = inicLista();

    nodo2* listaDoble = inicLista2();
    char opcion;

    do{
        system("cls");
        muestraMenu();

        opcion=getch();

        switch(opcion){
            case 48:
                generaArchivoRandom(10);
                break;
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
                break;
            case 55:
                pArreglo = archivoCompletoClientes2Arreglo1(AR_CLIENTES, pArreglo, &vPA);
                muestraClientesArreglo(pArreglo, vPA);
                break;
            case 56:
                vPA = archivoCompletoClientes2Arreglo2(AR_CLIENTES, &pArreglo, vPA);
                muestraClientesArreglo(pArreglo, vPA);
                break;
            case 57:
                listaClientes = archivo2lista(AR_CLIENTES, listaClientes);
                muestraLista(listaClientes);
                break;
            case 97:
                if(listaClientes){
                    invertida = invertirLista(listaClientes);
                    printf("\n Lista Invertida :\n");
                    muestraLista(invertida);
                    printf("\n Lista :\n");
                    muestraLista(listaClientes);
                }else{
                    printf("\n La lista de clientes esta vacia, no puede invertirse\n");
                }
                break;
            case 98:
                listaClientes = arreglo2listaPD(clientes, vCli, listaClientes);
                muestraLista(listaClientes);
                break;
            case 99:
                archivo2listaPDBis(AR_CLIENTES, &listaClientes);
                muestraLista(listaClientes);
                system("pause");
                borrarNodosMenorA(&listaClientes,10000000);
                muestraLista(listaClientes);
                break;
            case 100:
                archivo2pilaCli(AR_CLIENTES, &pila);
                muestraPilaCli(&pila);
                printf("\n ________________ Segundo mostrar ________________ \n");
                muestraPilaCli(&pila);
                break;
            case 101:
                listaDoble = archivo2lista2(AR_CLIENTES, listaDoble);
                muestraLista2(listaDoble);
                break;
            case 102:
                if(!pilaVacia(&pila)){
                    pila2lista(pila, &listaClientes);
                    muestraLista(listaClientes);
                }else{
                    printf("\n La pila esta vacia.......... \n");
                }
                break;
            case 103:
                    archivo2fila(AR_CLIENTES, &filaClientes);
                    muestraFila(&filaClientes);
        }
        ///getch(); /// es una pausa
        system("pause");
    }while(opcion!=27);

    printf("Hello world!\n");
    return 0;
}

void muestraMenu(){
    printf("\n\t\t\t Menu Principal \n\n");
    printf("\n 0 - Genera 100 registros aleatorios en el archivo de Clientes");
    printf("\n 1 - Carga archivo de Clientes");
    printf("\n 2 - Muestra archivo de Clientes");
    printf("\n 3 - Carga Arreglo de Clientes");
    printf("\n 4 - Muestra Arreglo de Clientes");
    printf("\n 5 - Copia Clientes del archivo en el Arreglo");
    printf("\n 6 - Copia todos los Clientes del archivo en el Arreglo");
    printf("\n 7 - Copia todos los Clientes del archivo en el Arreglo retornando el puntero");
    printf("\n 8 - Copia todos los Clientes del archivo en el Arreglo por refencia y retorna validos");
    printf("\n 9 - Copia el archivo de Clientes en una lista");
    printf("\n a - Invierte una lista");
    printf("\n b - Copia arreglo en lista pasando *");
    printf("\n c - Copia archivo en lista pasando **");
    printf("\n d - Copia archivo en pila implementada con lista");
    printf("\n e - Copia archivo en una lista doble de clientes");
    printf("\n f - Copia la pila a una lista");
    printf("\n g - Copia el archivo a una fila");

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

nodo* arreglo2lista(stCliente a[], int v, nodo* lista){
    for(int i=0;i<v;i++){
        /** nodo* nuevo = crearNodo(a[i]);
        lista=agregarAlPrincipio(lista, nuevo);*/

        ///lista=agregarAlPrincipio(lista, crearNodo(a[i]));
        lista=agregarAlFinal(lista, crearNodo(a[i]));
    }
    return lista;
}

nodo* arreglo2listaPD(stCliente a[], int v, nodo* lista){
    for(int i=0;i<v;i++){
        agregarAlPrincipioPD(&lista, crearNodo(a[i]));
    }
    muestraLista(lista);
    return lista;
}

void archivo2listaPDBis(char arClientes[], nodo** lista){
    FILE *pArchi = fopen(arClientes, "rb");
    stCliente c;
    if(pArchi){
        while(fread(&c, sizeof(stCliente), 1, pArchi)>0){
            (*lista)=agregarEnOrdenDNI((*lista), crearNodo(c));
        }
        fclose(pArchi);
    }
}

nodo* archivo2lista(char arClientes[], nodo* lista){
    FILE *pArchi = fopen(arClientes, "rb");
    stCliente c;
    if(pArchi){
        while(fread(&c, sizeof(stCliente), 1, pArchi)>0){
            lista=agregarEnOrdenDNI(lista, crearNodo(c));
        }
        fclose(pArchi);
    }
    return lista;
}

nodo2* archivo2lista2(char arClientes[], nodo2* lista){
    FILE *pArchi = fopen(arClientes, "rb");
    stCliente c;
    if(pArchi){
        while(fread(&c, sizeof(stCliente), 1, pArchi)>0){
            lista=agregarAlFinal2(lista, crearNodo2(c));
        }
        fclose(pArchi);
    }
    return lista;
}

nodo* intercalarLista(nodo* listaA, nodo* listaB, nodo* listaC){
    nodo* aux;
    while(listaA && listaB){
        if(strcmp(listaA->dato.persona.apellido,listaB->dato.persona.apellido)<0){
            aux=listaA;
            listaA = listaA->siguiente; // avanzo uno en la lista A...
            aux->siguiente=NULL;
            listaC=agregarAlFinal(listaC, aux); // agrego al final en lista C
        }else{
            aux=listaB;
            listaB=listaB->siguiente; // avanzo uno en la lista b...
            aux->siguiente=NULL; // lo desvinculo
            listaC=agregarAlFinal(listaC, aux); // agrego al final en lista C
        }
    }
    if(listaA){
        listaC=agregarAlFinal(listaC,listaA);
    }
    if(listaB){
        listaC = agregarAlFinal(listaC, listaB);
    }
    return listaC;
}

nodo* invertirLista(nodo* lista){
    nodo* invertida = inicLista();
    nodo* aux;
    while(lista){
        aux = lista;
        lista=lista->siguiente;
        aux->siguiente = NULL;
        invertida = agregarAlPrincipio(invertida, aux);
    }
    return invertida;
}

void archivo2pilaCli(char arClientes[], PilaCli* p){
    FILE *pArchi = fopen(arClientes, "rb");
    stCliente c;
    if(pArchi){
        while(fread(&c, sizeof(stCliente), 1, pArchi)>0){
            apilarCliente(p, c);
        }
        fclose(pArchi);
    }
}

void archivo2fila(char arClientes[], Fila* f){
    FILE *pArchi = fopen(arClientes, "rb");
    stCliente c;
    if(pArchi){
        while(fread(&c, sizeof(stCliente), 1, pArchi)>0){
            agregar(f, c);
        }
        fclose(pArchi);
    }
}

void muestraPilaCli(PilaCli* p){
    PilaCli aux;
    inicPila(&aux);
    while(!pilaVacia(p)){
        muestraUnCliente(topeCliente(p));
        apilarCliente(&aux, desapilarCliente(p));
    }
    while(!pilaVacia(&aux)){
        apilarCliente(p, desapilarCliente(&aux));
    }
}

void borrarNodosMenorA(nodo** lista, int limite){
    nodo* seg = (*lista);
    nodo* aux;
    nodo* ante = seg;
    int flag = 1;

    while(seg){
        if(atoi(seg->dato.persona.dni) < limite){
            aux=seg;
            ante->siguiente=seg->siguiente;
            seg=seg->siguiente;
            free(aux);
        }else{
            if(flag){  /// es igual if(flag==1)
                (*lista) = seg;
                flag = 0;
            }
            ante=seg;
            seg=seg->siguiente;
        }
    }
}

nodo * borrarNodosSegunParametro(nodo * lista, int filtro){
    nodo* aux;
    nodo* seg;
    nodo* ante;

    if(lista){
        while (lista!=NULL && atoi(lista->dato.persona.dni)<filtro){
            aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        seg=lista->siguiente;
        ante=lista;
        while(seg!=NULL){ /// tenemos que recorrer toda la lista
            if(atoi(seg->dato.persona.dni)<filtro){
                aux=seg;
                ante->siguiente=seg->siguiente;
                seg=seg->siguiente;
                free(aux);
            }else{
                ante=seg;
                seg=seg->siguiente;
            }
        }
    }
    return lista;
}

void pila2lista(PilaCli p, nodo** lista){
    PilaCli aux;
    inicPila(&aux);
    stCliente c;
    while(!pilaVacia(&p)){
        c = topeCliente(&p);
        if(atoi(c.persona.dni)%2==0){
            (*lista)=agregarAlFinal((*lista), crearNodo(c));
        }
        apilarCliente(&aux, desapilarCliente(&p));
    }
}

/**
void pila2lista(PilaCli p, nodo** lista){
    PilaCli aux;
    inicPila(&aux);
    stCliente c;
    while(!pilaVacia(&p)){
        c = topeCliente(&p);
        nodo* nuevo = crearNodo(c);
        (*lista)=agregarAlFinal((*lista), nuevo);
        apilarCliente(&aux, desapilarCliente(&p));
    }
    while(!pilaVacia(&aux)){
        apilarCliente(&p, desapilarCliente(&aux));
    }
}
*/
