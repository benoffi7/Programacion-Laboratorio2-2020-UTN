#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int notaNumerica;
    char alumne[30];
    struct nodoNota * sig;
}nodoNota;

typedef struct
{
    char nombreMateria[20];
    nodoNota * listaNotas;

}celdaMateria;

int ingresoDato(celdaMateria materias[], int limite);
int alta(celdaMateria materias[],int limite, char nombreMateria[],char nombreAlumne[], int nota);
nodoNota * crearNodo(int nota,char nombreAlumne[30]);
int buscarMateria(celdaMateria materias[],int validos, char nombreMateria[]);
int agregarMateria(celdaMateria materias[],int validos, char nombreMateria[]);
nodoNota * agregarPpio(nodoNota * lista, nodoNota * nuevoNodo);
void mostrarArreglo(celdaMateria materias[30], int validos);
void mostrarLista(nodoNota * lista);

int main()
{
    celdaMateria materias[30];
    int validos = ingresoDato(materias,30);
    system("cls");
    mostrarArreglo(materias,validos);
    return 0;
}

int ingresoDato(celdaMateria materias[], int limite)
{
    int nota = 0;
    char nombreAlumne[30];
    char nombreMateria[30];
    char mander = 's';
    int validos = 0;
    while ((mander == 's') && (validos<limite))
    {
        printf("Ingrese el nombre de la materia\n");
        fflush(stdin);
        scanf("%s",&nombreMateria);

        printf("Ingrese el nombre del alumne\n");
        fflush(stdin);
        scanf("%s",&nombreAlumne);

        printf("Ingrese la nota del alumne\n");
        fflush(stdin);
        scanf("%d",&nota);

        validos = alta(materias,validos,nombreMateria,nombreAlumne,nota);

        printf("Ingrese s para seguir\n");
        fflush(stdin);
        scanf("%c",&mander);
    }
    return validos;
}

int alta(celdaMateria materias[],int validos, char nombreMateria[],char nombreAlumne[], int nota)
{
    nodoNota * nuevoNodo = crearNodo(nota,nombreAlumne);
    int pos = buscarMateria(materias,validos,nombreMateria);
    if (pos == -1)
    {
        validos = agregarMateria(materias,validos,nombreMateria);
        pos = validos - 1;
    }
    celdaMateria unaMateria = materias[pos]; //extraigo la mat
    nodoNota * unaListaDeNotas = unaMateria.listaNotas; //extraigo la lista
    unaListaDeNotas=agregarPpio(unaListaDeNotas,nuevoNodo); //agrego el nodo
    unaMateria.listaNotas = unaListaDeNotas; //asigno la lista a la mat
    materias[pos] = unaMateria; //actualizamos la materia
    return validos;
}

nodoNota * crearNodo(int nota,char nombreAlumne[30])
{
    nodoNota * nuevoNodo = (nodoNota*)malloc(sizeof(nodoNota));
    nuevoNodo->sig = NULL;
    strcpy(nuevoNodo->alumne,nombreAlumne);
    nuevoNodo->notaNumerica = nota;
    return nuevoNodo;
}

int buscarMateria(celdaMateria materias[],int validos, char nombreMateria[])
{
    int pos = -1;
    int indice = 0;
    while ((indice<validos)&&(pos==-1))
    {
        if (strcmpi(materias[indice].nombreMateria,nombreMateria)==0)
        {
            pos = indice;
        }
        indice++;
    }
    return pos;
}

int agregarMateria(celdaMateria materias[],int validos, char nombreMateria[])
{
    materias[validos].listaNotas = NULL; //inicLista;
    strcpy(materias[validos].nombreMateria,nombreMateria);
    validos++;
    return validos;
}


nodoNota * agregarPpio(nodoNota * lista, nodoNota * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void mostrarArreglo(celdaMateria materias[30], int validos)
{
    int indice = 0;
    for (indice = 0;indice<validos;indice++)
    {
        printf("materia -> %s\n",materias[indice].nombreMateria);
        printf("**** lista de notas ****\n");
        mostrarLista(materias[indice].listaNotas);
        printf("**** ******** ****\n");
    }
}

void mostrarLista(nodoNota * lista)
{
    if (lista!=NULL)
    {
        printf("alumno -> %s \n",lista->alumne);
        printf("nota -> %d \n",lista->notaNumerica);
        mostrarLista(lista->sig);
    }
}
