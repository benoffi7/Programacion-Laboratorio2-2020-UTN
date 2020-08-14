#include <stdio.h>
#include <stdlib.h>
#define nomArch "Archivo.bin"
#define TAM_MAX 20

typedef struct
{
    char nombre[30];
    int edad;
} Persona;


Persona cargaUnaPersona()
{
    Persona p;
    printf("Ingrese un nombre\n");
    fflush(stdin);
    gets(p.nombre);
    printf("Ingrese una edad\n");
    scanf("%d",&p.edad));
    return p;
}

void cargarDatos()
{
    char continuar='s';
    Persona p;
    FILE* arch= fopen(nomArch, "ab");
    if (arch != NULL)
    {
        while (continuar == 's')
        {
            p=cargaUnaPersona();
            fwrite(&p,sizeof(Persona),1,arch);
            printf("Desea seguir s/n \n");
            fflush(stdin);
            scanf("%c",&continuar);
        }

        fclose(arch);

    }
    else
    {
        printf("El archivo generó un error\n");
    }

}

int traerDatos(Persona datos[])
{
    FILE* arch = fopen(nomArch,"rb");
    int i =0;
    if (arch)
    {
        while (fread(&datos[i],sizeof(Persona),1,arch) > 0)
        {
            i++;
        }

        fclose(arch);
    }

    return i;
}

int cantidadDatosCargados()
{
    int cant=0;
    FILE* arch= fopen(nomArch,"rb");
    if (arch)
    {
        fseek(arch,0,SEEK_END);
        cant= ftell(arch)/sizeof(Persona);
        fclose(arch);
    }
    return cant;
}

///la posicion comienza desde 1
Persona buscarEnArchivo(int posicion)
{
    int cant= cantidadDatosCargados();
    Persona p;
    FILE* arch = fopen(nomArch,"rb");

    if (arch && posicion < cant)
    {
        fseek(arch,sizeof(Persona)*(posicion-1),SEEK_SET);
        fread(&p,sizeof(Persona),1,arch);
        fclose(arch);
    }
    return p;
}


void persistirArreglo(Persona datos[], int validos)
{
    FILE* arch= fopen(nomArch,"wb");
    if (arch)
    {
        fwrite(datos,sizeof(Persona)*validos,1,arch);

        fclose(arch);
    }
}

int main()
{
    Persona datos[20];
    int validos=0;
    cargarDatos();
    validos=traerDatos(datos);
    persistirArreglo(datos,validos);





    return 0;
}
