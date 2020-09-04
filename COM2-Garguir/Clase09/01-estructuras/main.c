#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "archivoEmpleados.h"
#include "listaEmpleados.h"

#define DIM_EMP 150
#define AR_EMPLEADOS "empleados.dat"

void muestraMenu();
nodo* archivo2lista(char nombreArchivo[], nodo* lista);

int main()
{
    stEmpleado empleados[DIM_EMP];
    int vEmp=0;

    nodo* lista = inicLista();


    char opcion;

    do{
        muestraMenu();
        opcion=getch();

        switch(opcion){
            case 49:
                ingresaEmpleadosArchivo();
                break;
            case 50:
                muestraArchivoDeEmpleados(AR_EMPLEADOS);
                getch();
                break;
            case 51:
                lista = archivo2lista(AR_EMPLEADOS, lista);
                mostrarLista(lista);
                getch();
                break;
        }

        system("cls");
    }while(opcion!=27);

    printf("Hello world!\n");
    return 0;
}

void muestraMenu(){
    printf("\n\t\t\t Menu Principal \n\n");
    printf("\n 1 - Carga archivo de Empleados");
    printf("\n 2 - Muestra archivo de Empleados");
    printf("\n 3 - Carga arreglo de Empleados");
    printf("\n 4 - Muestra arreglo de Empleados");
    printf("\n 5 - Pasa archivo a arreglo de Empleados");
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
        }

        fclose(archi);
    }

    return lista;
}

