#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "archivoClientes.h"


#define AR_CLIENTES "clientes.dat"

/*********************************************************//**
*
* \brief Busca un cliente por DNI en el archivo
* \param char dni[] - el dni a buscar
* \return int flag - 1 si lo encuentra - 0 si no lo encuentra
*
***********************************************************/
int existeDNICliente(char dni[])
{
    stCliente aux;
    int flag=0;

    FILE * archi = fopen(AR_CLIENTES,"rb");

    if(archi)  /// if(archi != NULL)
    {
        while(flag==0 && fread(&aux,sizeof(stCliente),1,archi) >0)
        {
            if(strcmp(aux.persona.dni, dni)==0)
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
* \brief Busca el último Id de cliente en el archivo
* \param ninguno
* \return int ultimoId - retorna el último id - 0 si está vacio
*
***********************************************************/
int ultimoIdCliente()
{
    stCliente c;
    int ultimoId =0;

    FILE* bufferCliente = fopen(AR_CLIENTES,"rb");

    if (bufferCliente)
    {
        fseek(bufferCliente, (-1)* sizeof(stCliente),SEEK_END);
        if (fread(&c, sizeof (stCliente),1, bufferCliente)>0)
        {
            ultimoId=c.id;
        }
    }
    return ultimoId;
}

/*********************************************************//**
*
* \brief Carga un archivo de clientes con intervencion del usuario
* \param ninguno
* \return void
*
***********************************************************/
void cargaClientesArchivo(){
    stCliente c;
    char opcion;

    do{
        c = cargaUnCliente();
        guardaClienteArchivo(c);

        printf("\n ESC para salir....");
        opcion=getch();
    }while(opcion!=27);
}

/*********************************************************//**
*
* \brief Guarda un cliente en el archivo
* \param stCliente cliente - un cliente
* \return void
*
***********************************************************/
void guardaClienteArchivo(stCliente cliente){
    FILE * pArch = fopen(AR_CLIENTES, "ab");
    if(pArch){
        fwrite(&cliente, sizeof(stCliente), 1, pArch);
        fclose(pArch);
    }
}

/*********************************************************//**
*
* \brief Muestra un archivo de clientes
* \param char archCli[] - el nombre del archivo
* \return void
*
***********************************************************/
void muestraClientesArchivo(char archCli[]){
    stCliente c;
    FILE *pArch = fopen(archCli, "rb");
    if(pArch){
        while(fread(&c, sizeof(stCliente), 1, pArch) > 0){
            muestraUnCliente(c);
        }
        fclose(pArch);
        printf("\n");
    }
}

/*********************************************************//**
*
* \brief Carga un arreglo de clientes con intervencion del usuario
* \param stCliente c[] - el arreglo de clientes
* \param int v - sus validos
* \param int dim - su dimension
* \return int v - sus validos
*
***********************************************************/
int cargaClientesArreglo(stCliente c[], int v, int dim){
    char opcion=0;

    while(opcion!=27 && v < dim){
        c[v]=cargaUnCliente();
        v++;

        printf("\n ESC para salir....");
        opcion=getch();
    }

    return v;
}

/*********************************************************//**
*
* \brief Muestra un arreglo de clientes
* \param stCliente c[] - el arreglo de clientes
* \param int v - sus validos
* \return void
*
***********************************************************/
void muestraClientesArreglo(stCliente c[], int v){
    for(int i=0; i<v; i++){
        muestraUnCliente(c[i]);
    }
}

/*********************************************************//**
*
* \brief Copia los clientes de una archivo a un arreglo de clientes
* \param char archivo[] - el nombre del archivo
* \param stCliente c[] - el arreglo de clientes
* \param int v - sus validos
* \param int dim - su dimension
* \return int v - sus validos
*
***********************************************************/
int archivoClientes2Arreglo(char archivo[], stCliente c[], int v, int dim){
    FILE *pArch = fopen(archivo, "rb");

    if(pArch){   /// if(pArch!=NULL)
        while(v < dim && fread(&c[v], sizeof(stCliente), 1, pArch) > 0){
            v++;
        }
        fclose(pArch);
    }

    return v;
}

/*********************************************************//**
*
* \brief Copia el archivo completo (si hay lugar) en un arreglo de clientes
* \param stCliente c[] - el arreglo de clientes
* \param int dim - su dimension
* \return int v - los validos
*
***********************************************************/
int archivoCompletoClientes2Arreglo(char archivo[], stCliente c[], int dim){
    FILE *pArch = fopen(archivo, "rb");
    int v = cuentaRegistros(archivo, sizeof(stCliente));

   /// v=(v>dim)?dim:v;

    if(v>dim){
        v=dim;
    }

    if(pArch){   /// if(pArch!=NULL)
        fread(c, sizeof(stCliente), v, pArch);
        fclose(pArch);
    }

    return v;
}

/*********************************************************//**
*
* \brief Copia el archivo completo en un arreglo dinamico de clientes
* \param stCliente *c - el arreglo de clientes sin inicializar - Recuerden que no es una referencia
* \param int *v - puntero a validos
* \return stCliente *c - el arreglo dinamico
*
***********************************************************/
stCliente* archivoCompletoClientes2Arreglo1(char archivo[], stCliente *c, int *v){
    FILE *pArch = fopen(archivo, "rb");
    (*v) = cuentaRegistros(archivo, sizeof(stCliente));

    c = (stCliente*) malloc(sizeof(stCliente)*(*v));

    if(pArch){   /// if(pArch!=NULL)
        fread(c, sizeof(stCliente), (*v), pArch);
        fclose(pArch);
    }

    return c;
}

/*********************************************************//**
*
* \brief Copia el archivo completo en un arreglo dinamico de clientes
* \param stCliente **c - el arreglo de clientes sin inicializar
* \param int v - sus validos
* \return int v - sus validos
*
***********************************************************/
int archivoCompletoClientes2Arreglo2(char archivo[], stCliente **c, int v){
    FILE *pArch = fopen(archivo, "rb");
    v = cuentaRegistros(archivo, sizeof(stCliente));

    (*c) = (stCliente*) malloc(sizeof(stCliente)*v);
    ///(*c) = realloc((*c), sizeof(stCliente)*v+50);
    if(pArch){   /// if(pArch!=NULL)
        fread((*c), sizeof(stCliente), v, pArch);
        fclose(pArch);
    }

    return v;
}


/*********************************************************//**
*
* \brief Cuenta la cantidad de registra de un archivo
* \param char archivo[] - el nombre del archivo
* \param int dataSize - el sizeof del tipo de dato del archivo
* \return int v - la cantidad de registros - 0 si está vacío
*
***********************************************************/
int cuentaRegistros(char archivo[], int dataSize){
     FILE *pArch = fopen(archivo, "rb");
     int cantReg = 0;

     if(pArch){
        fseek(pArch, 0, SEEK_END);
        cantReg = ftell(pArch)/dataSize;
     }

    return cantReg;
}



