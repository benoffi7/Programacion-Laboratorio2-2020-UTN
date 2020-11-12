#include <stdio.h>
#include <stdlib.h>
#define nomArch "archivo.bin"

typedef struct
{
    char animal[30];
    int cant;
    int habitat;
    int idEspecie;
    char especie[20];
} registroArchivo;


typedef struct
{
    char nombreAnimal[30];
    int cantidad;
    int habitat; // 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;
typedef struct nodito
{
    animal dato;
    struct nodito* sig;
} nodito;
typedef struct nodo
{
    int idEspecie;
    char especie [20]; //"Mamiferos","Aves","Reptiles","Peces"
    nodito* animales;
} nodo;



/**
La insercion en la lista se hace en orden creciente por idEspecie.
La inserción en la sublista se hace en orden creciente por nombreAnimal.
Utilizando la información en el archivo, realice las siguientes funciones:
…fileALista(…) →  esta función recorrerá el archivo y pasará la información a la lista (utilizando las funciones necesarias)
**/


void borrarTodosAnimales(nodito** listaAnimales)
{
    nodito* aux;
    while (*listaAnimales)
    {
        aux = *listaAnimales;
        (*listaAnimales) = (*listaAnimales)->sig;
        free(aux);
    }

}


void borrarEspecie(nodo** listaEspecies, int idEspecie)
{
    nodo* aux;
    nodo* seg,*ante;
    if (*listaEspecies && *listaEspecies->idEspecie == idEspecie)
    {
        borrarTodosAnimales(&(*listaEspecies->animales));
        aux = *listaEspecies;
        *listaEspecies = (*listaEspecies)->sig;
        free(aux);

    }
    else
    {
        ante = *listaEspecies;
        seg = (*listaEspecies)->sig;
        while(seg != NULL && seg->idEspecie < idEspecie)
        {
            ante = seg;
            seg = seg->sig;
        }
        if (seg)
        {
            borrarTodosAnimales(&(seg->animales));
            ante->seg = seg->sig;
            free(seg);
        }

    }


}





///si esta retorna 1 si no 0
int existeID(nodo* listaEspecies, int idEspecie)
{
    ...

}


void insercion(nodito ** animales, char* nombreAnimal, int cant, int habitat)
{
    animal a;
    strcpy(a.nombreAnimal,nombreAnimal);
    a.cantidad=cant;
    a.habitat=habitat;
    //insertarOrdenado(animales,a);
    nodito * nuevo = crearNodito(a);
    ....


}

void busquedaEInsercion(nodo* listaEspecies, registroArchivo reg)
{
    while (listaEspecies != NULL && listaEspecies->idEspecie < reg.idEspecie)
    {
      listaEspecies= listaEspecies->sig;

    }

    insercion(&(listaEspecies->animales),reg.animal,reg.cant,reg.habitat);

}

///modularizado en el .c de mis especies
void insertarOrdenadoEspecie(nodo** listaEspecies, int idEspecie, char *nomEspecie)
{
    nodo* nuevo = crearNodo(idEspecie,nomEspecie);
    ///insertarSublista(&(nuevo->animales),reg.nombreAnimal...); no va por que no cumple con la funcion
    if (*listaEspecies && ...)
    {
        ..
    }
    else
    {

        .....
    }


}

nodo* crearNodo(int idEspecie, char* nomEspecie)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    strcpy(nuevo->especie,nomEspecie);
    nuevo->idEspecie = idEspecie;
    nuevo->animales = NULL ///inicializo el campo de la lista de animales (ACA NO INGRESO DATOS)
    nuevo->sig=NULL;

    return nuevo;

}




void FileALista(nodo** listaEspecies)
{
    FILE* fp = fopen(nomArch,"rb");
    registroArchivo reg;
    if (fp)
    {
        while(fread(&reg,sizeof(registroArchivo),1,fp)>0)
        {
           if (existeID(*listaEspecies,reg.idEspecie))
           {
               busquedaEInsercion(*listaEspecies,reg);
           }
           else
           {
               insertarOrdenadoEspecie(listaEspecies,reg.idEspecie,reg.especie);
               busquedaEInsercion(*listaEspecies,reg.idEspecie,reg.animal,reg.cant,reg.habitat);
           }


        }

        fclose(fp);
    }


}






int main()
{
 nodo* listaEspecies = NULL;


    return 0;
}
