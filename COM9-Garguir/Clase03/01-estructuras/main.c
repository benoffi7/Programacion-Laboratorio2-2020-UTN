#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "cliente.h"
#include "archivoClientes.h"

#define AR_CLIENTES "clientes.dat"
#define DIM_CLI 100

void muestraMenu();

int main()
{
    stCliente clientes[DIM_CLI];
    int vCli = 0;

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

    printf("\n\n    ESC para salir.....");
}
