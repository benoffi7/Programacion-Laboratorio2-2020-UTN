#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "archivoEmpleados.h"
#include "empleados.h"

#define AR_EMPLEADOS "empleados.dat"

/*********************************************************//**
*
* \brief Carga un empleado con intervencion del usuario
* \param ninguno
* \return stEmpleado retorn a un empleado
*
***********************************************************/

stEmpleado cargaUnEmpleado()
{
    stEmpleado e;
    int existe;
    e.id = ultimoIdEmpleado(AR_EMPLEADOS)+1;

    do
    {
        system("cls");
        printf("\n DNI.........: ");
        fflush(stdin);
        scanf("%s",e.persona.dni);

        existe=existeDNIEmpleado(e.persona.dni);
    }
    while(existe);  /// es igual a while(existe==1)

    do
    {
        printf("\n Nombre........: ");
        fflush(stdin);
        scanf("%s", e.persona.nombre);
    }
    while(strlen(e.persona.nombre)==0);

    printf("\n Apellido......: ");
    fflush(stdin);
    scanf("%s", e.persona.apellido);

    printf("\n E-Mail........: ");
    fflush(stdin);
    scanf("%s", e.email);


    return e;
}

/*********************************************************//**
*
* \brief Muestra un empleado
* \param stEmpleado e - un empleado cargado
* \return void
*
***********************************************************/
void mostrarUnEmpleado(stEmpleado e)
{
    printf("\n-------------------------------\n");
    printf("\nNombre:%s",e.persona.nombre);
    printf("\nApellido:%s",e.persona.apellido);
    printf("\nDni:%s",e.persona.dni);
    printf("\nCuil:%s",e.cuil);
    printf("\nE-mail:%s",e.email);
    printf("\nDomicilio Particular:%s",e.domicilioParticular);
    printf("\nTelefono Fijo:%s",e.telefonoFijo);
    printf("\nTelefono Celular:%s",e.telefonoCel);
    printf("\nId Tipo:%d",e.idTipo);
    printf("\nSueldo:%d\n",e.sueldo);
    printf("\n-------------------------------\n");
}
