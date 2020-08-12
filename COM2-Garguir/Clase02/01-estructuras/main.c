#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"


int ultimoIdEmpleado(char archivoEmplados[])
int existeDNIEmpleado();
void guardaEmpleadoArchivos(stEmpleado e, char archivoEmpleados[])

int main()
{
    printf("Hello world!\n");
    return 0;
}



int ultimoIdEmpleado(char archivoEmplados[])
{
    stEmpleado e;
    int id = 0;
    FILE *archi=fopen(archivoEmplados, "rb");

    if(archi)   /// if(archi != NULL)
    {
        fseek(archi, sizeof(stEmpleado)*(-1),SEEK_END);
        if(fread(&e,sizeof(stEmpleado),1,archi) > 0)
        {
            id=e.persona.id;
        }
        fclose(archi);
    }
    return id;
}

int existeDniEmpleado(char dni[])
{
    stEmpleado e;
    int flag=0;

    FILE*archi=fopen(AR_EMPLEADOS,"rb");
    if(archi)
    {
        while(flag==0 && fread(&e,sizeof(stEmpleado),1,archi)>0)
        {
            if(strcmpi(dni,e.persona.dni)==0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    return flag;
}


void ingresaEmpleadosArchivo()
{
    stEmpleado e;
    char opcion;

    do
    {
        e = cargaUnEmpleado();
        guardaEmpleadoArchivo(e, AR_EMPLEADOS);

        printf("\n ESC para salir..... ");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=27);
}

void guardaEmpleadoArchivos(stEmpleado e, char archivoEmpleados[])
{
    FILE *archi=fopen(archivoEmpleados,"ab");
    if(archi)
    {
        fwrite(&e,sizeof(stEmpleado),1,archi);
        fclose(archi);
    }
}

void mostrarArchivoDeEmpleados(char archivoEmpleados[])
{
    stEmpleado e;
    FILE*archi=fopen(archivoEmpleados,"rb");

    printf("\n\tListado de Empleados\n");
    if(archi)
    {
        while(fread(&e,sizeof(stEmpleado),1,archi)>0)
        {
            mostrarUnEmpleado(e);
        }
        fclose(archi);
    }
}

int ingresaEmpleadosArray(stEmpleado e[], int v, int dim)
{
    char opcion=0;

    while(opcion!=27 && v < dim)
    {
        e[v] = cargaUnEmpleado();
        v++;

        printf("\n ESC para salir..... ");
        fflush(stdin);
        opcion=getch();
    }
    return v;
}

void muestraArregloEmpleados(stEmpleado e[], int v){
    for(int i=0;i<v;i++){
        mostrarUnEmpleado(e[i]);
    }
}

