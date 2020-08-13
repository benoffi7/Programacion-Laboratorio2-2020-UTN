#include <stdio.h>
#include <stdlib.h>

typedef struct{
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
    int idTipo;
    int sueldo;
}stEmpleado;

int ultimoIdEmpleado();
int existeDNIEmpleado();

int main()
{

    printf("Hello world!\n");
    return 0;
}

stEmpleado cargaUnEmpleado(){
    stEmpleado e;
    int existe;
    e.id = ultimoIdEmpleado()+1;

    do{
        system("cls");
        printf("\n DNI.........: ");
        fflush(stdin);
        scanf("%s",e.persona.dni);

        existe=existeDNIEmpleado(e.persona.dni);
    }while(existe); /// es igual a while(existe==1)

    do{
        printf("\n Nombre........: ");
        fflush(stdin);
        scanf("%s", e.persona.nombre);
    }while(strlen(e.persona.nombre)==0);

    printf("\n Apellido......: ");
    fflush(stdin);
    scanf("%s", e.persona.apellido);

    printf("\n E-Mail........: ");
    fflush(stdin);
    scanf("%s", e.email);


    return e;
}

void ingresaEmpleadosArchivo(){
    stEmpleado e;
    char opcion;

    do{
        e = cargaUnEmpleado();
        guardaEmpleadoArchivo(e);

        printf("\n ESC para salir..... ");
        fflush(stdin);
        opcion=getch();
    }while(opcion!=27);

}
