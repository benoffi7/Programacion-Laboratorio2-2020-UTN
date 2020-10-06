#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    char apellido[30];
    char nombre[30];
    char dni[10];
} stPersona;

typedef struct
{
    int id;
    stPersona persona;
    char cuil[15];
    char email[90];
    char domicilioParticular[50];
    char telefonoFijo[15];
    char telefonoCel[15];
    int idTipo;
    int sueldo;
} stEmpleado;

stEmpleado cargaUnEmpleado();
void mostrarUnEmpleado(stEmpleado e);

#endif // EMPLEADOS_H_INCLUDED
