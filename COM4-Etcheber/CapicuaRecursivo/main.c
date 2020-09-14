#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[5] = {10,31,5,8,16};

//    if (averiguarCapicua(arreglo,4,0)==1)
//        printf("Es capicua");
//    else
//        printf("No es capicua");

int posMenor = encontrarMenorRecursivo(arreglo,5,0);

FILE * archivito = fopen ("nombre.bin", "rb");

rta = capicuaArchivos(archivito);

fclose(archivito);

printf("La posicion menor es: %d", posMenor);
}

int averiguarCapicua (int ar[],int fin, int inicio)
{
    int flag;
    if ((inicio >= fin) || (ar[inicio]!=ar[fin]))
    {
        if (inicio < fin)
            flag = 0;
        else
            flag = 1;
    }
    else
        flag = averiguarCapicua(ar,fin-1, inicio+1);

    return flag;
}

int encontrarMenorIterativo (int ar[], int validos, int inicio)
{
    int posMenor = inicio;

    for (int i=inicio; i<validos; i++)
    {
        if (ar[i] < ar[posMenor])
            posMenor = i;
    }
    return posMenor;
}

int encontrarMenorRecursivo(int ar[], int validos, int inicio)
{
    int posMenor;
    if (inicio==validos-1)
    {
        posMenor = inicio;
    }

    else
    {
        posMenor = encontrarMenorRecursivo(ar, validos, inicio+1);
        if (ar[inicio]< ar[posMenor])
            posMenor = inicio;

    }
    return posMenor;
}

int capicuaArchivos (FILE * archi)
{
    fread (variable, sizeof(int),1,archi)
}
