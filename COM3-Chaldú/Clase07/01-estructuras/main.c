#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "archivoEmpleados.h"
#include "listaEmpleados.h"
#include "registroArchivo.h"

#define DIM_EMP 150
#define AR_EMPLEADOS "empleados.dat"

void muestraMenu();
nodo* archivo2lista(char nombreArchivo[], nodo* lista);

int main()
{
    stEmpleado empleados[DIM_EMP];
    int vEmp=0;

    nodo* listaEmpleados = inicLista();


    char opcion;

    do{
        muestraMenu();
        opcion=getch();

        switch(opcion){
            case 48:
                generaArchivoRandom(100);
                break;
            case 49:
                ingresaEmpleadosArchivo();
                break;
            case 50:
                muestraArchivoDeEmpleados(AR_EMPLEADOS);
                break;

            case 57:
                listaEmpleados = archivo2lista(AR_EMPLEADOS, listaEmpleados);
                muestraLista(listaEmpleados);

                printf("\n Ultimo Nodo");
                muestraNodo(buscarUltimo(listaEmpleados));
        }
        system("pause");
        system("cls");
    }while(opcion!=27);

    printf("Hello world!\n");
    return 0;
}

void muestraMenu(){
    printf("\n\t\t\t Menu Principal \n\n");
    printf("\n 0 - Genera 100 registros aleatorios en el archivo de Clientes");
    printf("\n 1 - Carga archivo de Empleados");
    printf("\n 2 - Muestra archivo de Empleados");
    printf("\n 3 - Carga arreglo de Empleados");
    printf("\n 4 - Muestra arreglo de Empleados");
    printf("\n 5 - Pasa archivo a arreglo de Empleados");
    printf("\n 9 - Copia el archivo de Clientes en una lista");
    printf("\n\n          ESC para salir....");

}

nodo* archivo2lista(char nombreArchivo[], nodo* lista){
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi) > 0){
            /*
            nodo* nuevo = crearNodo(e);
            lista = agregarAlPrincipio(lista, nuevo);
            */
            lista = agregarAlPrincipio(lista, crearNodo(e));
            ///lista = agregarEnOrdenDNI(lista, crearNodo(e));
            ///lista = agregarAlFinal(lista, crearNodo(e));
        }

        fclose(archi);
    }

    return lista;
}

nodo* intercalarListasId(nodo* listaA, nodo* listaB, nodo* listaC){
    nodo* aux;
    while(listaA && listaB){
        if(listaA->dato.id < listaB->dato.id){
            aux=listaA;
            listaA = listaA->siguiente; // avanzo uno en la lista A...
        }else{
            aux=listaB;
            listaB=listaB->siguiente; // avanzo uno en la lista b...
        }
        aux->siguiente=NULL;
        listaC=agregarAlFinal(listaC, aux); // agrego al final en lista C

    }

    if(listaA){
        listaC = agregarAlFinal(listaC, listaA);
    }
    if(listaB){
        listaC = agregarAlFinal(listaC, listaB);
    }

    return listaC;
}

invertida = invertiLista(lista);


nodo* invertirLista(nodo* lista){
    nodo* listaInvertida = inicLista();
    nodo* aux;
    while(lista){
        aux = lista;
        lista = lista->siguiente;
        aux->siguiente = NULL;
        listaInvertida = agregarAlPrincipio(listaInvertida, aux);
    }

    return listaInvertida;
}

void borrarNodoMenorA(nodo** lista, int limite){
    nodo* seg = (*lista);
    nodo* ante;
    nodo* aux;
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

nodo * borrarNodosSegunParametro(nodo* lista, int filtro){
    nodo * aux, seg, ante;

    if(lista){
        while (lista!=NULL && atoi(lista->dato.persona.dni)<filtro){
            aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        nodo * seg=lista->siguiente;
        nodo * ante=lista;
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


void invertir(int* a, int* b){
    int aux;
    aux = (*a);
    (*a) = (*b);
}
