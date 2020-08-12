#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char apellido[30];
    char nombre[30];
    char dni[10];
}stPersona;

typedef struct{
    int id;
    stPersona persona;
    char cuit[15];
    char email[90];
    char domicilioParticular[50];
    char domicilioComercial[50];
    char telefonoFijo[15];
    char telefonoCel[15];
}stCliente;

typedef struct{
    int id;
    stPersona persona;
    char cuit[15];
    char email[90];
    char domicilioComercial[50];
    char telefonoFijo[15];
    char telefonoCel[15];
}stProveedor;

typedef struct{
    int id;
    stPersona persona;
    char cuil[15];
    char email[90];
    char domicilioParticular[50];
    char telefonoFijo[15];
    char telefonoCel[15];
}stEmpleado;

int ultimoIdCliente();

int main()
{
    printf("Hello world!\n");
    return 0;
}

stCliente cargaUnCliente(){
    stCliente c;
    c.id = ultimoIdCliente()+1;


    printf("\n Nombre........: ");


    return c;
}





