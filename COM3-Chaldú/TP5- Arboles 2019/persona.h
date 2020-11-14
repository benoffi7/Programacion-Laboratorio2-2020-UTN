#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;

void mostrarPersona(persona dato);
persona cargarPersona();
persona crearPersona(int legajo, char nombre [], int edad);

#endif // PERSONA_H_INCLUDED
