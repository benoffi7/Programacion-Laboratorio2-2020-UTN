#include <stdio.h>
#include <stdlib.h>

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
    char cuit[15];
    char email[90];
    char domicilioParticular[50];
    char domicilioComercial[50];
    char telefonoFijo[15];
    char telefonoCel[15];
} stCliente;

typedef struct
{
    int id;
    stPersona persona;
    char cuit[15];
    char email[90];
    char domicilioComercial[50];
    char telefonoFijo[15];
    char telefonoCel[15];
} stProveedor;

typedef struct
{
    int id;
    stPersona persona;
    char cuil[15];
    char email[90];
    char domicilioParticular[50];
    char telefonoFijo[15];
    char telefonoCel[15];
} stEmpleado;

#define AR_CLIENTES "clientes.dat"

int ultimoIdCliente();

int main()
{
    printf("Hello world!\n");
    return 0;
}

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

    return c;
}

int existeDNICliente(char dni[])
{
    stCliente aux;
    int flag=0;

    FILE * archi = fopen(AR_CLIENTES,"rb");

    if(archi)  /// if(archi != NULL)
    {
        while(flag==0 && fread(&aux,sizeof(stCliente),1,archi) >0)
        {
            if(strcmp(aux.persona.dni == dni)==0)
            {
                flag=1;
            }
        }

        fclose(archi);
    }
    return flag;
}

int ultimoIdCliente()
{
    stCliente c;
    int ultimoId =0;

    FILE* bufferCliente = fopen(AR_CLIENTES,"rb");

    if (bufferCliente)
    {
        fseek(bufferCliente, (-1)* sizeof(stCliente),SEEK_END);
        if (fread(&c, sizeof (stCliente),1, bufferCliente))
        {
            ultimoId=c.id;
        }
    }
    return ultimoId;
}

void cargaClientesArchivo(){
    stCliente c;
    char opcion;

    do{
        c = cargaUnCliente();
        guardaClienteArchivo(c);

        printf("\n ESC para salir....");
        opcion=getch();
    }while(opcion!=27);
}

void guardaClienteArchivo(stCliente cliente){
    FILE * pArch = fopen("cliente.dat", "ab");
    if(pArch){
        fwrite(&cliente, sizeof(stCliente), 1, pArch);
        fclose(pArch);
    }
}

void muestraUnCliente(stCliente c){
    printf("\n Nombre................: %s", c.persona.nombre);
    printf("\n Nombre................: %s", c.persona.nombre);
    printf("\n Nombre................: %s", c.persona.nombre);
    printf("\n Nombre................: %s", c.persona.nombre);
    printf("\n --------------------------------------------------");
}

void muestraClientesArchivo(char archCli[]){
    stCliente c;
    FILE *pArch = fopen(archCli, "rb");
    if(pArch){
        while(fread(&c, sizeof(stCliente), 1, pArch) > 0){
            muestraUnCliente(c);
        }
        fclose(pArch);
    }
}
