#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"


/*********************************************************//**
*
* \brief Carga un cliente con intervencion del usuario
* \param ninguno
* \return stCliente retorna un cliente
*
***********************************************************/
stCliente cargaUnCliente()
{
    stCliente c;
    int existe;
    c.id = ultimoIdCliente()+1;

    do
    {
        system("cls");
        printf("\n DNI.........: ");
        fflush(stdin);
        scanf("%s",c.persona.dni);

        existe=existeDNICliente(c.persona.dni);
    }
    while(existe);  /// es igual a while(existe==1)

    do
    {
        printf("\n Nombre........: ");
        fflush(stdin);
        scanf("%s", c.persona.nombre);
    }
    while(strlen(c.persona.nombre)==0);

    printf("\n Apellido......: ");
    fflush(stdin);
    scanf("%s", c.persona.apellido);

    printf("\n E-Mail........: ");
    fflush(stdin);
    scanf("%s", c.email);

    printf("\n Nombre......: ");
    fflush(stdin);
    gets(c.persona.nombre) ;

    printf("\n Apellido....:");
    fflush(stdin);
    gets(c.persona.apellido);
    printf("\n DNI....:");
    fflush(stdin);
    gets(c.persona.dni);
    printf("\n CUIT......: ");
    fflush(stdin);
    gets(c.cuit);
    printf("\n Email......: ");
    fflush(stdin);
    gets(c.email);
    printf("\n Domicilio Particular......: ");
    fflush(stdin);
    gets(c.domicilioParticular);
    printf("\n Domicilio Comercial......: ");
    fflush(stdin);
    gets(c.domicilioComercial);
    printf("\n Telefono Fijo......: ");
    fflush(stdin);
    gets(c.telefonoFijo);
    printf("\n Telefono Celular......: ");
    fflush(stdin);
    gets(c.telefonoCel);

    return c;
}

void muestraUnCliente(stCliente c)
{
    printf("\nNombre...............: %s", c.persona.nombre);
    printf("\nApellid..............: %s", c.persona.apellido);
    printf("\nDNI..................: %s", c.persona.dni);
    printf("\nCUIT.................: %s", c.cuit);
    printf("\nEmail................: %s", c.email);
    printf("\nDomicilio............: %s", c.domicilioParticular);
    printf("\nTelefono Fijo........: %s", c.telefonoFijo);
    printf("\nTelefono Celular.....: %s", c.telefonoCel);
    printf("\n----------------------------------------------------------");
}
