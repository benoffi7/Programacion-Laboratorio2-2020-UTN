#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

#define AR_CLIENTES "clientes.dat"

int ultimoIdCliente();

int main()
{
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


        }
        getch(); /// es una pausa
    }while(opcion!=27);

    printf("Hello world!\n");
    return 0;
}

void muestraMenu(){
    printf("\n\t\t\t Menu Principal \n\n");
    printf("\n 1 - Carga archivo de Clientes");
    printf("\n 2 - Muestra archivo de Clientes");
    printf("\n 3 - ");
    printf("\n 4 - ");
    printf("\n 5 - ");

    printf("\n\n    ESC para salir.....");
}
