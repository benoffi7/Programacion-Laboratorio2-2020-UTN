#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar[5] = {1,1,1,1,1};
    mostrarArreglo(ar,5,0);
    printf("\n\n");
    int rta = capicuaRecursivo(ar,4,0);

    if (rta == 1)
        printf("\nEl arreglo es capicua");
    else
        printf("\nEl arreglo no es capicua");


    abrirLecturaRecursiva();
}

void mostrarArreglo (int ar[], int validos, int cont)
{
    if (cont < validos)
    {
        mostrarArreglo(ar, validos, cont+1);
        printf("[ %d ]", ar[cont]);

    }
}

void capicuaIterativo (int ar[], int validos, int * flag)
{
    int inicio = 0, fin = validos - 1;

    while ( (inicio < fin) && (ar[inicio] == ar[fin]))
    {
        inicio++;
        fin--;
    }
    if (inicio >= fin)
        (*flag) = 1;
    else
        (*flag) = 0;
}

int capicuaRecursivo (int ar[], int fin, int inicio)
{
    int rta;
    printf("a");

    if ((inicio >= fin) || (ar[inicio] != ar [fin]))
    {
        if (ar[inicio] != ar [fin])
        {
            printf("\nEntra");
            rta = 0;
        }
        else
        {
            rta = 1;
        }
    }
    else
        rta  = capicuaRecursivo(ar, fin-1, inicio+1);
}

void leerArchivo (FILE * archi)
{
    int x;
    if (fread(&x, sizeof(int), 1, archi) > 0)
    {
        printf("\nValor : %d", x);
        leerArchivo(archi);
    }
}

void abrirLecturaRecursiva ()
{
    FILE * a = fopen ("archivoEnteros","rb");

    if (a!=NULL)
    {

        leerArchivo(a);

        fclose(a);
    }
}




