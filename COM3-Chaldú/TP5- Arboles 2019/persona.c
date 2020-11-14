#include "persona.h"

void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Legajo: %d \n", dato.legajo);
    printf("Nombre: %s \n", dato.nombre);
    printf("  Edad: %d \n", dato.edad);
    printf("-----------------------\n");
}

persona cargarPersona()
{
    persona aux;

    printf("Ingrese legajo:");
    scanf("%d", &aux.legajo);
    fflush(stdin);
    printf("Ingrese nombre: ");
    gets(aux.nombre);
    fflush(stdin);
    printf("Ingrese edad:");
    scanf("%d", &aux.edad);

    return aux;
}

persona crearPersona(int legajo, char nombre [], int edad)
{
    persona aux;
    aux.legajo=legajo;
    aux.edad=edad;
    strcpy(aux.nombre, nombre);
    return aux;
}
