#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include TAM_MAX 20

int cargarDatos(Persona[]);
Persona cargaUnaPersona();



typedef struct
{
    char nombre[30];
    int edad;
}Persona;



int cargarDatos(Persona datos[])
{
    char continuar='s';
    int i=0;
    while ( i < TAM_MAX && continuar == 's')
    {
        datos[i]=cargaUnaPersona();
        i++;
        printf("Desea seguir s/n \n");
        scanf("%c",&continuar);
    }

    return i;
}



Persona cargaUnaPersona()
{
   Persona p;
   printf("Ingrese un nombre\n");
   fflush(stdin);
   gets(p.nombre);
   printf("Ingrese una edad\n");
   scanf("%d",&p.edad));
   return p;
}

void mostrarUnaPersona(Persona p)
{
    printf("nombre: %s\n",p.nombre);
    printf("edad: %d\n",p.edad);
}


void mostrarPersonas(Persona datos[],int validos)
{
    for (int i = 0; i < validos; i++)
    {
        mostrarUnaPersona(datos[i]);
    }
}

int buscarUnaPersona(Persona datos[],int validos, char* nombre)
{
    int i=0;
    int pos=-1;
    while (i < validos && pos == -1)
    {
        if (strcmpi(datos[i].nombre,nombre) == 0)
        {
            pos=i;
        }
        i++;

    }
    return pos;
}


int main()
{
   Persona p[20];
   int validos=0;
   char nombre[30];
   int pos;
   validos =cargarDatos(p);
   mostrarPersonas(datos,validos);
   printf("Ingrese nombre de persona a buscar\n");
   fflush(stdin);
   scanf("%s",nombre);
   pos=buscarUnaPersona(datos,validos,nombre);
   printf("La edad de la persona encontrada es: %d\n", p[pos].edad);

    return 0;
}




