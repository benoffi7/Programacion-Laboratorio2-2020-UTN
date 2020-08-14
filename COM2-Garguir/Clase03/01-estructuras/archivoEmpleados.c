#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#include "archivoEmpleados.h"

#define AR_EMPLEADOS "empleados.dat"



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
            id=e.id;
        }
        fclose(archi);
    }
    return id;
}

int existeDNIEmpleado(char dni[])
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
        guardaEmpleadoArchivo(AR_EMPLEADOS, e);

        printf("\n ESC para salir..... ");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=27);
}

void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado e)
{
    FILE *archi=fopen(archivoEmpleados,"ab");
    if(archi)
    {
        fwrite(&e,sizeof(stEmpleado),1,archi);
        fclose(archi);
    }
}

void muestraArchivoDeEmpleados(char archivoEmpleados[])
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

int archivoEmpleados2arreglo(char archivo[], stEmpleado e[], int v, int dim){
    FILE *pArch = fopen(archivo, "rb");
    if(pArch){
        while(v < dim && fread(&e[v],sizeof(stEmpleado), 1, pArch)>0){
            v++;
        }
        fclose(pArch);
    }
    return v;
}

int archivoCompletoEmpleados2arreglo(char archivo[], stEmpleado e[], int dim){
    int v = cuentaRegistros(archivo, sizeof(stEmpleado));
    ///v=(v>dim)?dim:v;
    if(v>dim){
        v = dim;
    }

    FILE *pArch = fopen(archivo, "rb");
    if(pArch){
        fread(e, sizeof(stEmpleado), v, pArch);
        fclose(pArch);
    }
    return v;
}


int cuentaRegistros(char file, int dataSize){

}
