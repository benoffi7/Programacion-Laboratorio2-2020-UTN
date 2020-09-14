#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct nodo2 * sig;
    struct nodo2 * ante;
} nodo2;

nodo2 * inicLista ();
nodo2 * crearNodo (int numero);
void mostrarNodo (nodo2 * nodo);
nodo2 * agregarPrincipio (nodo2 * lista, nodo2 * nn);
void mostrarLista (nodo2 * lista);
nodo2 * cargarLista (nodo2 * lista);
nodo2 * agregarOrdenado (nodo2 * lista, nodo2 * nn);






int main()
{
    nodo2 * lista = inicLista();
//    nodo2 * miNodo = inicLista();
//    nodo2 * nodoAux = inicLista();
//
//    nodoAux = crearNodo(17);
//    miNodo = crearNodo(23);
//
//    lista = agregarPrincipio(lista, miNodo);
//    lista = agregarPrincipio(lista, nodoAux);

    lista = cargarLista(lista);
    mostrarLista(lista);

    return 0;
}

nodo2 * inicLista ()
{
    return NULL;
}

nodo2 * crearNodo (int numero)
{
    nodo2 * aux = (nodo2*) malloc (sizeof(nodo2));
    aux->dato = numero;
    aux->ante= NULL;
    aux ->sig = NULL;
    return aux;
}

void mostrarNodo (nodo2 * nodo)
{
    printf ("DATO: %d\n", nodo->dato);
}

nodo2 * agregarPrincipio (nodo2 * lista, nodo2 * nn)
{
    if (lista == NULL)
    {
        lista = nn;
    }
    else
    {
        lista->ante = nn;
        nn -> sig = lista;
        lista = nn;
    }

    /**
        if (lista != NULL)
        {
            lista -> ante = nn;
            nn -> sig = lista;
        }
        lista = nn;

    */
    return lista;
}

void mostrarLista (nodo2 * lista)
{
    nodo2 * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg = seg->sig;
    }
}

nodo2 * cargarLista (nodo2 * lista)
{
    char seguir = 's';
    int dato = 0;

    while (seguir == 's')
    {
        printf ("Ingrese un numero: ");
        scanf ("%d", &dato);

        nodo2 * aux = crearNodo(dato);
        lista = agregarOrdenado(lista, aux);

        printf ("Quiere cargar otro numero? \n");
        fflush(stdin);
        scanf ("%c", &seguir);
    }

    return lista;
}

nodo2 * agregarOrdenado (nodo2 * lista, nodo2 * nn)
{
    if (lista == NULL)
        lista = nn;
    else if (lista->dato > nn->dato)
        lista = agregarPrincipio(lista, nn);
    else
    {
        nodo2 * ante = lista;
        nodo2 * seg = lista->sig;

        while (seg != NULL && seg->dato < nn->dato)
        {
            ante = seg;
            seg = seg->sig;
        }

        if (seg != NULL)
            seg->ante = nn;

        nn->ante = ante;
        nn->sig = seg;
        ante->sig = nn;
    }
    return lista;
}
