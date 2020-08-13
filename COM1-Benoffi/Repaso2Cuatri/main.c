#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char apellido[30];
    int edad;
    char generoPreferido[30];
    int cantidadLibrosBiblioteca;
} lector;

//fn para cargar con todos los valores un lector OK
lector cargarUnLector();
//fn para mostrar un lector enviado por param OK
void mostrarUnLector(lector unLector);
//fn para cargar muchos lectores al club. recibe un pos inicial para no pisar datos OK
int cargarMuchosLectores(lector clubDeLectura[],int dim,int posInicial);
//muestra todos los lectores OK
void mostrarClub(lector clubDeLectura[],int cantidad);
//dado un club lo guarda en un archivo binario, solo los +18 años
void guardarEnArchivo(lector clubDeLectura[],int cantidad);
//lee un archivo
int leerArchivo(char nombreArchivo[30]);

int main()
{
    //lector unLector = cargarUnLector();
    //mostrarUnLector(unLector);
    //lector clubDeLectura[100];
    //int validos = cargarMuchosLectores(clubDeLectura,100,0);
    //mostrarClub(clubDeLectura,validos);
    //guardarEnArchivo(clubDeLectura,validos);
    leerArchivo("clubdelectura.gonzalo");
    return 0;
}

int leerArchivo(char nombreArchivo[30])
{
    FILE * archi = fopen(nombreArchivo,"rb");
    lector temp;
    int cantidad = 0;
    if (archi!=NULL)
    {
        while (fread(&temp,sizeof(lector),1,archi)>0)
        {
            mostrarUnLector(temp);
            cantidad++;
        }
    }
    else
    {
        printf("El archivo no existe o esta dañado o algo\n");
    }
    fclose(archi);
    return cantidad;
}

void guardarEnArchivo(lector clubDeLectura[],int cantidad)
{
    FILE * archi;
    int indice = 0;
    lector unLector;

    archi = fopen("clubdelectura.gonzalo","wb");

    if (archi!=NULL)
    {
        for (indice = 0;indice<cantidad;indice++)
        {
            unLector = clubDeLectura[indice];
            if (unLector.edad>18)
            {
                fwrite(&unLector,sizeof(lector),1,archi);
            }
        }
    }
    fclose(archi);
}

void mostrarClub(lector clubDeLectura[],int cantidad)
{
    int indice = 0;
    lector unLector;
    for (indice = 0;indice<cantidad;indice++)
    {
        unLector = clubDeLectura[indice];
        mostrarUnLector(unLector);
    }
}

int cargarMuchosLectores(lector clubDeLectura[],int dim,int posInicial)
{
    int validos = posInicial;
    char mander = 's';
    lector temp;
    while ((mander=='s')&&(validos<dim))
    {
        temp = cargarUnLector();
        //pueda o no hacer validaciones antes de guardalo
        clubDeLectura[validos] = temp ;

        validos++;
        printf("desea seguir? s para si\n");
        fflush(stdin);
        scanf("%c",&mander);
    }
    return validos;
}

lector cargarUnLector()
{
    //variable aux para cargar datos
    lector aux;
    printf("Ingrese nombre del lector\n");
    fflush(stdin);
    gets(&aux.nombre);
    printf("Ingrese apellido del lector\n");
    fflush(stdin);
    gets(&aux.apellido);
    printf("Ingrese edad del lector\n");
    fflush(stdin);
    scanf("%d",&aux.edad);
    printf("Ingrese genero preferido del lector\n");
    fflush(stdin);
    gets(&aux.generoPreferido);
    printf("Ingrese la cantidad de libros en su biblioteca\n");
    fflush(stdin);
    scanf("%d",&aux.cantidadLibrosBiblioteca);
    return aux;
}

void mostrarUnLector(lector unLector)
{
    printf("--------------------\n");

    printf("Nombre del lector -> \n");
    printf("%s\n",unLector.nombre);

    printf("Apellido del lector -> \n");
    printf("%s\n",unLector.apellido);

    printf("Genero Preferido del lector -> \n");
    printf("%s\n",unLector.generoPreferido);

    printf("Cantidad de libros del lector -> \n");
    printf("%d\n",unLector.cantidadLibrosBiblioteca);

    printf("Edad del lector -> \n");
    printf("%d\n",unLector.edad);

    printf("--------------------\n");
}
