#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre [20];
    char posicion [20]; //buscador, cazador, golpeador, guardian
    int curso;
    int puntosGanados;
    char equipo [20]; //Ravenclaw, Hufflepuff, Gryffindor, Slytherin;
} stJugador;

typedef struct nodo
{
    stJugador dato;
    struct nodo * anterior;
    struct nodo * siguiente;
} nodo;

typedef struct nodoSimple
{
    char nombreCasa[20];
    int puntos;
    struct nodoSimple * sig;
} nodoSimple;

nodo * inicLista();
nodo * crearJugador (int id, char nombre [], char posicion [], int curso, int puntosGanados, char equipo[]);
nodo * agregarPpio (nodo * lista, nodo * nn);
nodo * agregarOrdenado (nodo * lista, nodo * nn);
nodo * cargarLista(nodo * lista);
void mostrarJugador (stJugador a);
void mostrarLista(nodo * lista);
nodo * aislarNodo (nodo ** lista);
nodo * ordenarListaPorPosicion (nodo * lista);
int sumaPuntosEquipo (nodo * lista, char equipo []);
void mostrarJugadorPosicion(nodo * lista, char nombre [], int curso);
nodo * borrarTodoUnCurso (nodo * lista, int curso);
nodoSimple * cargarListaEquipos (nodoSimple * lista, nodo * listaMaster);
nodoSimple * agregarPrincipioSimple (nodoSimple * lista, nodoSimple * nn);
nodoSimple * crearNodoSimple (int puntos, char nombreCasa[]);
void mostrarListaSimple (nodoSimple * lista);
nodoSimple * inicListaSimple ();




int main()
{
    int puntos = 0;
    nodo * lista = inicLista();
    nodoSimple * listaSimple = inicListaSimple();
    /// PUNTO 1
    lista = cargarLista(lista);
    mostrarLista(lista);
    system("pause");
    system ("cls");
    /// PUNTO 2
    printf ("ORDENANDO LA LISTA POR POSICION\n");
    lista = ordenarListaPorPosicion(lista);
    mostrarLista(lista);
    system("pause");
    system ("cls");
    /// PUNTO 3
    puntos = sumaPuntosEquipo(lista, "Slytherin");
    printf ("PUNTOS DE SLYTHERIN: %d \n", puntos);
    system("pause");
    system ("cls");
    /// PUNTO 4
    printf ("BUSCAMOS A SIRIUS BLACK, QUE ESTA EN QUINTO \n");
    mostrarJugadorPosicion(lista, "Sirius Black", 5);
    system("pause");
    system ("cls");
    /// PUNTO 5
    printf ("BORRO TODO EL CUARTO ANIO \n");
    lista = borrarTodoUnCurso(lista, 4);
    mostrarLista(lista);
    system("pause");
    system ("cls");
    /// PUNTO 6
    printf ("PUNTUACIONES POR CASA \n");
    printf ("-----------------------------\n");
    listaSimple = cargarListaEquipos(listaSimple, lista);
    mostrarListaSimple(listaSimple);
    return 0;
}
nodo * inicLista()
{
    return NULL;
}

nodo * crearJugador (int id, char nombre [], char posicion [], int curso, int puntosGanados, char equipo[])
{
    nodo * a = (nodo*) malloc (sizeof(nodo));

    a->dato.id=id;
    strcpy(a->dato.nombre,nombre);
    strcpy(a->dato.posicion, posicion);
    a->dato.curso=curso;
    a->dato.puntosGanados=puntosGanados;
    strcpy(a->dato.equipo,equipo);
    a->anterior=NULL;
    a->siguiente=NULL;

    return a;
}

nodo * agregarPpio (nodo * lista, nodo * nn)
{
    if (lista == NULL)
        lista = nn;
    else
    {
        nn->siguiente=lista;
        lista->anterior=nn;
        lista=nn;
    }
    return lista;
}

nodo * agregarOrdenado (nodo * lista, nodo * nn)
{
    if (lista == NULL)
        lista = nn;
    else if (strcmp(lista->dato.posicion,nn->dato.posicion)<0)
    {
        lista = agregarPpio(lista, nn);
    }
    else
    {
        nodo * ant = lista;
        nodo * seg = lista->siguiente;
        while (seg != NULL && strcmp(nn->dato.posicion,seg->dato.posicion)<0)
        {
            ant = seg;
            seg = seg->siguiente;
        }

        ant->siguiente=nn;
        nn->anterior=ant;
        nn->siguiente=seg;
        if (seg != NULL)
            seg->anterior=nn;
    }
    return lista;
}

nodo * cargarLista(nodo * lista)
{
    nodo * j1 = crearJugador(1,"Ron Weasley", "Guardian", 4, 100, "Gryffindor");
    nodo * j2 = crearJugador(2,"George Weasley", "Golpeador", 6, 80, "Gryffindor");
    nodo * j3 = crearJugador(3,"Fred Weasley", "Golpeador", 6, 150, "Hufflepuff");
    nodo * j4 = crearJugador(4,"Harry Potter", "Buscador", 4, 1000, "Gryffindor");
    nodo * j5 = crearJugador(5,"Draco Malfoy", "Buscador", 4, 10, "Slytherin");
    nodo * j6 = crearJugador(6,"Severus Snape", "Guardian", 2, 80, "slytherin");
    nodo * j7 = crearJugador(7,"Cedric Digory", "Cazador", 3, 150, "Hufflepuff");
    nodo * j8 = crearJugador(8,"Sirius Black", "Guardian", 5, 200, "Ravenclaw");
    nodo * j9 = crearJugador(9,"Minerva McGonagall", "Cazador", 2, 40, "Ravenclaw");
    nodo * j10 = crearJugador(10,"Oliver Wood", "Golpeador", 1, 400, "Hufflepuff");

    lista = agregarPpio(lista,j1);
    lista = agregarPpio(lista,j2);
    lista = agregarPpio(lista,j3);
    lista = agregarPpio(lista,j4);
    lista = agregarPpio(lista,j5);
    lista = agregarPpio(lista,j6);
    lista = agregarPpio(lista,j7);
    lista = agregarPpio(lista,j8);
    lista = agregarPpio(lista,j9);
    lista = agregarPpio(lista,j10);

    return lista;

}
void mostrarJugador (stJugador a)
{
    printf ("ID JUGADOR: %d\n", a.id);
    printf ("NOMBRE:");
    puts (a.nombre);
    printf ("POSICION:");
    puts (a.posicion);
    printf ("CURSO: %d\n", a.curso);
    printf ("PUNTOS GANADOS: %d\n", a.puntosGanados);
    printf ("EQUIPO:");
    puts (a.equipo);
    printf ("---------------------\n");
}

void mostrarLista(nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        mostrarJugador(seg->dato);
        seg=seg->siguiente;
    }
}
nodo * aislarNodo (nodo ** lista)
{
    nodo * aux = inicLista();
    if (*lista != NULL)
    {
        aux = (*lista);
        (*lista) = (*lista)->siguiente;
        aux->siguiente = NULL;
        aux->anterior = NULL;
    }
    return aux;
}

nodo * ordenarListaPorPosicion (nodo * lista)
{
    nodo * listaOrdenada = inicLista();
    nodo * aux;
    if (lista != NULL)
    {
        while (lista != NULL)
        {
            aux = aislarNodo(&lista);
            if (aux)
                listaOrdenada = agregarOrdenado(listaOrdenada, aux);
        }
    }
    return listaOrdenada;
}

int sumaPuntosEquipo (nodo * lista, char equipo [])
{
    int suma=0;
    if (lista == NULL)
        suma = 0;
    else
    {
        if (strcmpi(lista->dato.equipo, equipo) == 0)
            suma += lista->dato.puntosGanados + sumaPuntosEquipo(lista->siguiente, equipo);
        else
            suma += sumaPuntosEquipo(lista->siguiente,equipo);
    }
    return suma;
}

void mostrarJugadorPosicion(nodo * lista, char nombre [], int curso)
{
    nodo * seg = lista;
    if (seg != NULL)
    {
        if (strcmp (seg->dato.nombre,nombre)==0 && seg->dato.curso == curso)
        {
            mostrarJugador(seg->dato);
        }
        else
            mostrarJugadorPosicion(seg->siguiente,nombre, curso);
    }
}

nodo * borrarTodoUnCurso (nodo * lista, int grado)
{
    if (lista != NULL)
    {
        while (lista->dato.curso == grado) ///borramos todos los nodos que esten al principio que correspondan al curso buscado
        {
            nodo * aborrar = lista;
            lista = lista->siguiente;
            lista->anterior=NULL;
            free (aborrar);
        }
        nodo * ant = lista; /// Guardo el primer nodo de la lista.
        nodo * seg = lista;
        while (seg != NULL) ///Buscamos el resto de los nodos del curso y los borramos
        {
            if (seg->dato.curso == grado)
            {
                nodo * aborrar = seg;
                seg = seg->siguiente;
                if (seg)
                    seg->anterior=ant;
                ant->siguiente=seg;
                free (aborrar);
            }
            else
            {
                ant = seg;
                seg = seg->siguiente;
            }
        }
    }
    return lista;
}

nodoSimple * crearNodoSimple (int puntos, char nombreCasa[])
{
    nodoSimple * aux = (nodoSimple*) malloc(sizeof(nodoSimple));
    aux->puntos = puntos;
    strcpy (aux->nombreCasa,nombreCasa);
    aux->sig = NULL;
    return aux;
}
nodoSimple * agregarPrincipioSimple (nodoSimple * lista, nodoSimple * nn)
{
    if (lista == NULL)
        lista = nn;
    else
    {
        nn->sig=lista;
        lista=nn;
    }
    return lista;
}

nodoSimple * cargarListaEquipos (nodoSimple * lista, nodo * listaMaster)
{
    int puntosG = sumaPuntosEquipo(listaMaster, "Gryffindor");
    int puntosR = sumaPuntosEquipo(listaMaster, "Ravenclaw");
    int puntosH = sumaPuntosEquipo(listaMaster, "Hufflepuff");
    int puntosS = sumaPuntosEquipo(listaMaster, "Slytherin");

    lista = agregarPrincipioSimple(lista, crearNodoSimple(puntosG, "Gryffindor"));
    lista = agregarPrincipioSimple(lista, crearNodoSimple(puntosR, "Ravenclaw"));
    lista = agregarPrincipioSimple(lista, crearNodoSimple(puntosH, "Hufflepuff"));
    lista = agregarPrincipioSimple(lista, crearNodoSimple(puntosS, "Slytherin"));

    return lista;
}

void mostrarListaSimple (nodoSimple * lista)
{
    while (lista != NULL)
    {
        printf("CASA: ");
        puts(lista->nombreCasa);
        printf ("PUNTOS: %d\n", lista->puntos);
        printf ("-----------------------------\n");
        lista = lista->sig;
    }
}

nodoSimple * inicListaSimple ()
{
    return NULL;
}
