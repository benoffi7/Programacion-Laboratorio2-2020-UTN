#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#include "archivoEmpleados.h"

#define AR_EMPLEADOS "empleados.dat"

/*********************************************************//**
*
* \brief Busca el ultimo Id cargado
* \param string archivoEmpleados - el nombre del archivo
* \return int - el ultimo id
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Busca un DNI en el archivo
* \param string dni - el DNI a buscar
* \return int - 1 si existe - 0 si no existe
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Carga el archivo de empleados usando cargaUnEmpleado() y guardaEmpleadoArchivo()
* \param sin parametros
* \return void
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Guarda un empleado en el archivo
* \param string archivoEmpleados - el nombre del archivo
* \param stEmpleado e - un empleado
* \return void
*
***********************************************************/
void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado e)
{
    FILE *archi=fopen(archivoEmpleados,"ab");
    if(archi)
    {
        fwrite(&e,sizeof(stEmpleado),1,archi);
        fclose(archi);
    }
}

/*********************************************************//**
*
* \brief Muestra el archivo de empleados
* \param string archivoEmpleados - el nombre del archivo
* \return void
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Ingresa empleados a un arreglo
* \param stEmpleado e - el arreglo
* \param int v - sus validos
* \param int dim - su dimension
* \return int v - la cantidad de datos cargados
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Muestra el arreglo de empleados
* \param stEmpleado e - el arreglo
* \param int v sus validos
* \return void
*
***********************************************************/
void muestraArregloEmpleados(stEmpleado e[], int v){
    for(int i=0;i<v;i++){
        mostrarUnEmpleado(e[i]);
    }
}

/*********************************************************//**
*
* \brief Copia empleados del archivo en el arreglo
* \param string archivo - el nombre del archivo
* \param stEmpleado e - el arreglo de empleados
* \param int v - los validos del arreglo
* \param int dim - la dimension del arreglo
* \return int v - los validos del arreglo
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Copia el archivo de empleados completo en el arreglo
* \param string archivo - el nombre del archivo
* \param stEmpleado e - el arreglo de empleados vacio
* \param int dim - la dimension del arreglo
* \return int v - los validos del arreglo
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Retorna la cantidad de registros de un archivo
* \param string file - el nombre del archivo
* \param int dataSize - el tamaño de la estructura
* \return int v - la cantidad de registros
*
***********************************************************/
int cuentaRegistros(char file[], int dataSize){

}
