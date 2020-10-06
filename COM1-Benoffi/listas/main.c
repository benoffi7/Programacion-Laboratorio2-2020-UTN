#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    //informacion del siguiente
    struct nodo * siguiente;
    //informacion del nodo actual
    //puede ser variables u otra estructura ej persona
    int dato;
} nodo;

nodo * inicLista();
nodo * cargarMuchos(nodo * lista);
nodo * crearNodo(int dato);
nodo * agregarAlPpio(nodo * lista, nodo * nuevoNodo);
void mostrarLista(nodo * lista);
void mostrarNodo(nodo * unNodo);
void mostrarListaRec(nodo * lista);
void mostrarListaRec2(nodo * lista);
nodo * borrarNodo(nodo * lista, int aBorrar);

int main()
{
    nodo * lista = inicLista();
    mostrarLista(lista);
    lista = cargarMuchos(lista);
    system("cls");
   // printf("mostrando lista\n");
    //mostrarLista(lista);
    //lista = borrarNodo(lista,11);
    printf("mostrando lista recursiva inversa\n");
    mostrarListaRec2(lista);
    return 0;
}

void mostrarLista(nodo * lista)
{
    nodo * seguidora = lista;
    while (seguidora!=NULL)
    {
        mostrarNodo(seguidora);
        seguidora = seguidora->siguiente;
    }
}

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int dato)
{
    nodo * nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodo * agregarAlPpio(nodo * lista, nodo * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        //primero engancho el nuevo primero con el viejo primero
        nuevoNodo->siguiente = lista;
        //primero ahora es nuevo nodo why? porque la funcion es agregar al ppio
        lista = nuevoNodo;

    }
    return lista;
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else if (nuevoNodo->dato < lista->dato) //esto pasa cuando en NN tengo un 2 y el primero es un 3
    {
        //el 2 (NN) debe ir primero
        lista = agregarAlPpio(lista,nuevoNodo);
    }
    else //cuando el primero es un 2-3-4-6-NULL y quiero agregar un 5 (NN)
    {
        nodo * seguidora = lista;
        nodo * anterior = lista;
        while ((seguidora!=NULL)&&(seguidora->dato<nuevoNodo->dato))
        {
            anterior = seguidora;//hermano menor sigue
            seguidora = seguidora->siguiente; //hermano mayor
        }
        //seguidora quedo en el 6, no sabemos que hay detras
        //anterior quedo en el 4
        anterior->siguiente = nuevoNodo;
        nuevoNodo->siguiente = seguidora;
    }

    return lista;
}


nodo * ingresarEnOrdenRec(nodo * lista, nodo * nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {



        if (nuevo->dato > lista->dato)
        {
            lista->siguiente = ingresarEnOrdenRec(lista->siguiente,nuevo);
        }
        else
        {
            //nos pasamos dentro de la lista
            nuevo->siguiente = lista; //hago el enganche!!
            lista = nuevo; //cambio el enlace de lista para el llamado anterior
             if lista->sig == nn->sig{lista->sig = nn}

        }

    }

    return lista;
}

void mostrarListaRec(nodo * lista)
{
    if (lista == NULL)
    {
        //dejo la recu
        printf("fin de la lista\n");
    }
    else
    {

        mostrarListaRec(lista->siguiente);
mostrarNodo(lista);
    }
}

void mostrarListaRec2(nodo * lista)
{
    if (lista != NULL)
    {
        mostrarListaRec2(lista->siguiente);
        mostrarNodo(lista);
    }//implicita -> si es nulo no hago nada por ende no hay más recursion
}


void mostrarNodo(nodo * unNodo)
{
    printf("el nodo es %d\n",unNodo->dato);
}


nodo * cargarMuchos(nodo * lista)
{
    char mander = 's';
    int dato = 0;
    while (mander == 's')
    {

        printf("ingrese un dato\n");
        scanf("%d",&dato);

        //creo el nuevo nodo separado del resto, no sabe donde esta
        //apunta a null el siguiente y tiene su dato cargado
        nodo * nuevoNodo = crearNodo(dato);

        //le paso la lista con o sin null (depende)
        //y el nuevo nodo
        //si la lista esta vacia lista == nuevoNodo
        //sino engancho el nn con la lista y cambio la
        //referencia del (viejo)primero(lista) al nuevo nodo (nuevo primero)
        lista = agregarEnOrden(lista,nuevoNodo);
        //lo retorno para avisarle al main, hey, hay un nuevo primero

        printf("desea seguir? \n");
        fflush(stdin);
        scanf("%c",&mander);
    }
    return lista;
}


nodo * borrarNodo(nodo * lista, int aBorrar)
{
    nodo * aux;
    nodo * anterior;

    //si hay por lo menos un dato y es el que quiero borrar
    if ((lista!=NULL) && (lista->dato == aBorrar))
    {
        //primero aislamos a lista
        aux = lista;
        //segundo cambiamos la referencia del primer nodo
        lista = lista->siguiente; //el primero es igual al segundo
        //liberamos a aux, lo sacamos de memoria
        free(aux); //viejo primero porque entro en el if
    }
    else //si esta despues del primero
    {
        aux = lista; //dejamos a lista tranquila
        anterior = aux;
        while ((aux!=NULL)&&(aux->dato!=aBorrar))
        {
            anterior = aux;
            aux = aux->siguiente;
        }
        //cuando sale del while puede del while sale por dos razones
        //1ra que no hay más lista
        //2da encontro el dato
        if (aux!=NULL) //encontramos el nodo!
        {
            //bypass
            anterior->siguiente = aux->siguiente;
            //liberamos el dato
            free(aux);

        }

    }
    return lista;
}



