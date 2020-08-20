#include <stdio.h>
#include <stdlib.h>

const char nombreArchi[30] = "archivoEnteros.bin";

typedef struct
{
    char nombre[30];
    int edad;
}estudiante;

typedef struct
{
    int valor;
    struct nodoLista * sig;
}nodoLista;

int main()
{
    int * ar;

    int dimension;

    printf("Ingrese cantidad de elementos de su arreglo: ");
    scanf("%d", &dimension);

    ar = crearArregloDinamico(10);

    estudiante e;


    modificarVariable(&e, 23);




}

int * crearArregloDinamico (int dimension)
{
    int * aux = malloc(sizeof(int) * dimension);

    return aux;
}


void guardarArchivo (int ar[], int val)
{
    FILE * archi = fopen(nombreArchi,"ab");

    if (archi!=NULL)
    {
        fwrite(&ar, sizeof(int),val, archi);

        fclose(archi);
    }
}

void leerArchivo (int ar[], int dim)
{
    FILE * archi = fopen(nombreArchi,"rb");
    int i = 0;

    if (archi!=NULL)
    {
        while (fread(&ar[i], sizeof(int),1, archi))
        {
            i++;
        }

        fclose(archi);
    }
}

void modificarVariable (estudiante * a, int nuevaEdad)
{
      /// (*a) .edad = nuevaEdad;
    a->edad = nuevaEdad;

}
