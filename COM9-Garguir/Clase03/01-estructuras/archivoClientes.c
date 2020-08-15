#include <stdio.h>
#include <stdlib.h>
#include "archivoClientes.h"
#include "cliente.h"

#define AR_CLIENTES "clientes.dat"


int existeDNICliente(char dni[])
{
    stCliente aux;
    int flag=0;

    FILE * archi = fopen(AR_CLIENTES,"rb");

    if(archi)  /// if(archi != NULL)
    {
        while(flag==0 && fread(&aux,sizeof(stCliente),1,archi) >0)
        {
            if(strcmp(aux.persona.dni == dni)==0)
            {
                flag=1;
            }
        }

        fclose(archi);
    }
    return flag;
}

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

void guardaClienteArchivo(stCliente cliente){
    FILE * pArch = fopen("cliente.dat", "ab");
    if(pArch){
        fwrite(&cliente, sizeof(stCliente), 1, pArch);
        fclose(pArch);
    }
}

void muestraClientesArchivo(char archCli[]){
    stCliente c;
    FILE *pArch = fopen(archCli, "rb");
    if(pArch){
        while(fread(&c, sizeof(stCliente), 1, pArch) > 0){
            muestraUnCliente(c);
        }
        fclose(pArch);
    }
}

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

void muestraClientesArreglo(stCliente c[], int v){
    for(int i=0; i<v; i++){
        muestraUnCliente(c[i]);
    }
}

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
