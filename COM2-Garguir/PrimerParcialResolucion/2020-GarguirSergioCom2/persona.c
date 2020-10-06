#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

#define AR_PERSONAS "personas.dat"

/*********************************************************//**
*
* \brief Muestra un persona por consola
* \param stPersona c - una persona
* \return void
*
***********************************************************/
void muestraUnaPersona(stPersona c)
{
    printf("\nNombre...............: %s", c.nombre);
    printf("\nApellido.............: %s", c.apellido);
    printf("\nDNI..................: %s", c.dni);
    printf("\nEdad.................: %d", c.edad);
    printf("\nGenero...............: %s", (c.genero=='m')?"Masculino":"Femenino");
    printf("\n----------------------------------------------------------");
}

