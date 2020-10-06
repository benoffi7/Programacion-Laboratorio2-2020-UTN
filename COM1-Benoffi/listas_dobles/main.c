#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define alPpio 1
#define alFinal 2
#define alMedio 3

typedef struct
{
    int dato;
    struct nodo2 * sig;
    struct nodo2 * ante;
}nodo2;

nodo2 * inicLista();
nodo2 * crearNodo(int dato);
nodo2 * agregarAlPpio(nodo2 * lista, nodo2 * nuevoNodo);
nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo);
nodo2 * buscarUltimo(nodo2 * lista);
nodo2 * cargarMuchos(nodo2 * lista, int modo);
void mostrarDeAtrasParaAdelante(nodo2 * lista);
nodo2 * agregarEnOrden(nodo2 * lista, nodo2 * nuevoNodo);
nodo2 * borrarNodo(nodo2 * lista, int aBorrar);
nodo2 * borrarElDelMedio(nodo2 * lista);
void mostrar(nodo2 * lista);

int main()
{
    nodo2 * listaDoble = inicLista();
    int modo = alMedio;
    listaDoble = cargarMuchos(listaDoble,modo);
    system("cls");
    mostrar(listaDoble);
    system("pause");
    listaDoble = borrarElDelMedio(listaDoble);
    mostrar(listaDoble);
    nodo ** listaDoble

    (*listaDoble)->
    /*
    mostrarDeAtrasParaAdelante(listaDoble);
    system("pause");
    system("cls");
    int datoABorrar = 0;
    scanf("%d",&datoABorrar);
    system("pause");
    system("cls");
    listaDoble = borrarNodo(listaDoble,datoABorrar);
    mostrarDeAtrasParaAdelante(listaDoble);
    */

    return 0;
}

nodo2 * borrarElDelMedio(nodo2 * lista)
{
    nodo2 * primero = lista;
    nodo2 * ultimo = buscarUltimo(lista);
    nodo2 * segundo = lista->sig;

    while ((primero!=NULL)&&(ultimo!=NULL)&&(primero->dato!=ultimo->dato)
           &&(segundo!=NULL)&&(segundo->dato!=ultimo->dato))
    {
        primero = primero->sig;
        segundo = primero->sig;
        ultimo = ultimo->ante;
    }

    if (primero!=NULL)
    {
        if (primero->dato == ultimo->dato)
        {
            nodo2 * ante = primero->ante; //el 2
            nodo2 * sig = primero->sig; // el 4
            if (ante!=NULL)
                ante->sig = sig;
            sig->ante = ante;
            free(ultimo);
        }
        else
        {
            nodo2 * sig = ultimo->sig;
            primero->sig = sig;
            if (sig!=NULL)
                sig->ante = primero;
            free(ultimo);
        }
    }

    return lista;
}

nodo2 * inicLista()
{
    return NULL;
}

nodo2 * crearNodo(int dato)
{
    nodo2 * aux = (nodo2*)malloc(sizeof(nodo2));
    aux->dato = dato;
    //aux->dato.edad = edad;
    //aux->estructura = estructura
    aux->sig = NULL;
    aux->ante = NULL;
    return aux;
}

nodo2 * agregarAlPpio(nodo2 * lista, nodo2 * nuevoNodo)
{
    //lista ahora sera el segundo haya o no "lista"
    nuevoNodo->sig = lista;
    if (lista!=NULL)
    {
        //ahora si pregunto porque accedo a "ante" y null no tiene "ante"
        //listas dobles
        lista->ante = nuevoNodo;
    }
    //el nuevo nodo es el nuevo primero
    return nuevoNodo;
}

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo)
{
    nodo2 * ultimo;
    if (lista == NULL)
    {
        //este caso unico justifica el retorno
        lista = nuevoNodo;
    }
    else
        {
        //el enlace al primero no se modifica
        //tengo que buscar el ultimo
        ultimo = buscarUltimo(lista);
        ultimo->sig = nuevoNodo;
        //como es doble
        nuevoNodo->ante = ultimo;//el viejo ultimo
    }
    return lista;
}

nodo2 * agregarEnOrden(nodo2 * lista, nodo2 * nuevoNodo)
{
    //que 3 casos tengo que analizar?
    if (lista == NULL) { lista = nuevoNodo; } //lista vacia se vuelve el nuevonodo
    else if (nuevoNodo->dato < lista->dato) { lista = agregarAlPpio(lista,nuevoNodo); } //hay un elemento menor, iria al principio de la lista
    else
    {
        nodo2 * seguidora = lista->sig;
        nodo2 * anterior = lista;
        while ((seguidora!=NULL)&&(nuevoNodo->dato > seguidora->dato))
        {
            anterior = seguidora;
            seguidora = seguidora->sig;
        }
        anterior->sig = nuevoNodo;
        nuevoNodo->ante = anterior;
        nuevoNodo->sig = seguidora;
        if (seguidora!=NULL)
            seguidora->ante = nuevoNodo;
    }

    return lista;
}

nodo2 * buscarUltimo(nodo2 * lista)
{
    nodo2 * seguidora = lista;
    if (seguidora!=NULL)
    {
        while(seguidora->sig!=NULL)
        {
            seguidora = seguidora->sig;
        }
    }
    return seguidora;
}

//modo-> 1 para ppio y 2 para final y 3 al medio
nodo2 * cargarMuchos(nodo2 * lista, int modo)
{
    time_t t;
    srand((unsigned) time(&t));
    char mander = 's';
    while (mander == 's')
    {
        nodo2 * nuevoNodo = crearNodo(rand()%100);
        printf("nodo agregado es %d\n",nuevoNodo->dato);

        switch (modo)
        {
            //ppio
            case 1: lista = agregarAlPpio(lista,nuevoNodo);
                    break;
                    //final
            case 2: lista = agregarAlFinal(lista,nuevoNodo);
                    break;
            case 3: lista = agregarEnOrden(lista,nuevoNodo);
                    break;
        }


        printf("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c",&mander);
    }

    return lista;
}

void mostrarDeAtrasParaAdelante(nodo2 * lista)
{
    nodo2 * aux = lista;
    nodo2 * ultimo = buscarUltimo(aux);

    while(ultimo!=NULL)
    {
        printf("Dato: %i\n",ultimo->dato);
        ultimo=ultimo->ante;
    }
}

void mostrar(nodo2 * lista)
{
    nodo2 * aux = lista;

    while(aux!=NULL)
    {
        printf("Dato: %i\n",aux->dato);
        aux=aux->sig;
    }
}

nodo2 * borrarNodo(nodo2 * lista, int aBorrar)
{
    nodo2 * aux;
    nodo2 * seguidora;
    if ((lista!=NULL)&&(lista->dato == aBorrar))
    {
        aux = lista; //protocolo covid-19, aislamiento
        lista = lista->sig; //el nuevo primero es el segundo
        lista->ante = NULL; //el nuevo primero tiene que antes, NADA! (null)
        free(aux); //liberamos a willy, digo a aux

    }
    else
    {
        seguidora = lista->sig;
        aux = lista; //ante
        while ((seguidora!=NULL)&&(seguidora->dato!=aBorrar))
        {
            aux = seguidora;
            seguidora = seguidora->sig;
        }

        if (seguidora!=NULL)
        {
            nodo2 * siguiente = seguidora->sig;
            aux->sig = siguiente; //si apunta a null no pasa nada
            if (siguiente!=NULL)
            {
                siguiente->ante =aux;
            }
            free(seguidora);
        }
    }
    return lista;
}
