#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

void mostrarPersona(persona dato);
persona cargaUnaPersona();

void guardarPersonasEnArchivo();


#endif // PERSONA_H_INCLUDED
