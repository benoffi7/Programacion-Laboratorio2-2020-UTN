#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "archivoEmpleados.h"
#include "listaEmpleados.h"
#include "lista2.h"
#include "fila.h"
#include "pila.h"
#include "registroArchivo.h"

#define DIM_EMP 150
#define AR_EMPLEADOS "empleados.dat"

void muestraMenu();
nodo* archivo2lista(char nombreArchivo[], nodo* lista);
nodo* intercalarLista(nodo* listaA, nodo* listaB, nodo* listaC);
nodo* archivo2listaPD(char nombreArchivo[], nodo* lista);
void archivo2listaConPD(char nombreArchivo[], nodo** lista);
void archivo2pila(char nombreArchivo[], Pila* p);
nodo2* archivo2lista2(char arEmpleados[], nodo2* lista);
void muestraPila(Pila* p);

int main()
{
    stEmpleado empleados[DIM_EMP];
    int vEmp=0;

    nodo* listaEmpleados = inicLista();
    nodo2* listaDoble = inicLista2();

    Pila pila;
    inicPila(&pila);

    Fila filaEmpleados;

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
                //listaEmpleados = archivo2listaPD(AR_EMPLEADOS, listaEmpleados);
                archivo2listaConPD(AR_EMPLEADOS, &listaEmpleados);
                muestraLista(listaEmpleados);

                printf("\n Ultimo Nodo");
                muestraNodo(buscarUltimo(listaEmpleados));
                break;

            case 97:
                archivo2pila(AR_EMPLEADOS, &pila);
                muestraPila(&pila);
           /*     printf("\n -------------------- Segundo Mostrar -------------------- \n");
                muestraPila(pila);*/
                break;

            case 98:
                listaDoble = archivo2lista2(AR_EMPLEADOS, listaDoble);
                muestraLista2(listaDoble);
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
    printf("\n a - Copia el archivo de Clientes en una pila");
    printf("\n b - Copia el archivo de Clientes en una lista doble");
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
            ///lista = agregarAlPrincipio(lista, crearNodo(e));
            lista = agregarEnOrdenDNI(lista, crearNodo(e));
            ///lista = agregarAlFinal(lista, crearNodo(e));
        }

        fclose(archi);
    }

    return lista;
}

nodo* archivo2listaPD(char nombreArchivo[], nodo* lista){
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi) > 0){
            agregarAlPrincipioPD(&lista, crearNodo(e));
        }
        fclose(archi);
    }
    return lista;
}

void archivo2listaConPD(char nombreArchivo[], nodo** lista){
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi) > 0){
            agregarAlPrincipioPD(lista, crearNodo(e));
        }
        fclose(archi);
    }
}

void archivo2pila(char nombreArchivo[], Pila* p){
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi) > 0){
            apilar(p, e);
        }
        fclose(archi);
    }
}

void pila2lista(Pila* p, nodo** lista){
    Pila aux;
    inicPila(&aux);
    stEmpleado e;
    while(!pilaVacia(p)){
        e = tope(p);
        if(atoi(e.persona.dni) %2 == 0){
            (*lista)=agregarAlFinal((*lista), crearNodo(e));
        }
        apilar(&aux, desapilar(p));
    }
    while(!pilaVacia(&aux)){
        apilar(p, desapilar(&aux));
    }
}

void muestraPila(Pila* p){
    Pila aux;
    inicPila(&aux);
    while(!pilaVacia(p)){
        mostrarUnEmpleado(tope(p));
        apilar(&aux, desapilar(p));
    }
    while(!pilaVacia(&aux)){
        apilar(p, desapilar(&aux));
    }
}

nodo* intercalarLista(nodo* listaA, nodo* listaB, nodo* listaC){
    nodo* aux;
    while(listaA && listaB){
        if(listaA->dato.id < listaB->dato.id){
            aux = listaA;
            listaA = listaA->siguiente;
            aux->siguiente = NULL;
            listaC = agregarAlFinal(listaC, aux);
        }else{
            aux = listaB;
            listaB = listaB->siguiente;
            aux->siguiente = NULL;
            listaC = agregarAlFinal(listaC, aux);
        }
    }

    if(listaA){
        listaC = agregarAlFinal(listaC, listaA);
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
        lista = lista->siguiente;
        aux->siguiente = NULL;

        invertida = agregarAlPrincipio(invertida, aux);
    }
    return invertida;
}

nodo2* archivo2lista2(char arEmpleados[], nodo2* lista){
    FILE *pArchi = fopen(arEmpleados, "rb");
    stEmpleado c;
    if(pArchi){
        while(fread(&c, sizeof(stEmpleado), 1, pArchi)>0){
            lista=agregarAlPrincipio2(lista, crearNodo2(c));
        }
        fclose(pArchi);
    }
    return lista;
}
