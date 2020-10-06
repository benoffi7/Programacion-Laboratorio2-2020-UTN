#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


int main()
{
    char nombreAR[]="numerosLista";
    crearArchivo(nombreAR);
    mostrarArchivo(nombreAR);

    nodo * lis = inicLista();

    lis = deArchivoALista(lis,nombreAR);

    mostrarLista(lis);
}

void crearArchivo (char nombreArchivo[])
{
    FILE * archi = fopen(nombreArchivo,"wb");
    if (archi)
    {
        for (int i=0; i<10; i++)
        {
            fwrite(&i, sizeof(int),1,archi);
        }
        fclose(archi);
    }
}
void mostrarArchivo (char nombreArchivo[])
{
    FILE * archi = fopen(nombreArchivo,"rb");
    int i;
    if (archi)
    {
        printf("\n");
        while (fread(&i, sizeof(int),1,archi)>0)
        {
            printf("[ %i ]",i);
        }
        printf("\n");
        fclose(archi);
    }
}


//intercalarElementos ()




