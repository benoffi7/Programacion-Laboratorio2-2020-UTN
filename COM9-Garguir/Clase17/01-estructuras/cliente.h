#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    char apellido[30];
    char nombre[30];
    char dni[10];
} stPersona;

typedef struct{
    int id;
    stPersona persona;
    char cuit[15];
    char email[90];
    char domicilioParticular[50];
    char domicilioComercial[50];
    char telefonoFijo[15];
    char telefonoCel[15];
} stCliente;

stCliente cargaUnCliente();
void muestraUnCliente(stCliente c);

#endif // CLIENTE_H_INCLUDED
