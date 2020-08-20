#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[30];
    int legajo;
    int edad;
}Persona;

int main()
{
    Persona clase [30];
    int validos=0;
    cargarArregloPersonas(clase,30,&validos);
    mostrarArreglo(clase, validos);
}

Persona cargarIndividual ()
{
    Persona temp;
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s",&temp.nombre);
    printf("Ingrese legajo: ");
    scanf("%d",&temp.legajo);
    printf("Ingrese edad: ");
    scanf("%d",&temp.edad);


    return temp;
}

void cargarArregloPersonas (Persona ar[], int dim, int * validos)
{
    //int i =0;
    char control = 's';
    while ( (*validos) <dim && control=='s')
    {
        ar[*validos]=cargarIndividual();
        (*validos)++;

        printf("Desea continuar? S/ N");
        fflush(stdin);
        scanf("%c",&control);
    }



    //*validos = i;
}

void mostrarPersona (Persona mostrar)
{
    printf("\nNombre: %s",mostrar.nombre);
    printf("\nNombre: %d",mostrar.legajo);
    printf("\nNombre: %d",mostrar.edad);
}

void mostrarArreglo (Persona arreglo[], int dim)
{
    for (int i=0; i<dim; i++)
    {
        mostrarPersona(arreglo[i]);
    }
}

