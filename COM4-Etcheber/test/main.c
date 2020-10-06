#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[5]= {5,8,13,7,2};
    float promedio;
    int minimo, maximo;
    modificar(arreglo, 5, &promedio,&minimo,&maximo);

    printf("El promedio es: %f", promedio);
}

void modificar (int ar[], int validos, float * promedio, int * maximo, int * minimo)
{
    int suma = 0;
    for (int i=0; i<validos; i++)
    {
        suma += ar[i];
    }

    *promedio = (float)suma/validos;

}
