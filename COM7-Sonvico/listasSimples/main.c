#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

typedef struct
{
    persona dato;
    struct nodo * siguiente;
} nodo;


nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo (persona dato)
{
///crea un puntero de tipo nodo
    nodo * aux = (nodo*) malloc(sizeof(nodo));

///asigna valores a sus campos de información
    aux->dato = dato;

///asigna valor NULL al campo que contiene la dirección de memoria del //siguiente nodo
    aux->siguiente = NULL;

///retorna la dirección de memoria del nuevo nodo, que deberá ser asignada a una variable de tipo "puntero a nodo".
    return aux;
}


nodo * agregarPpio (nodo * lista, nodo * nuevoNodo)
{
///si la lista está vacía, ahora apuntará al nuevo nodo.
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
///si la lista no está vacía, inserta el nuevo nodo al comienzo de la //misma, y el viejo primer nodo pasa a ser el segundo de la lista.
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre);
    printf("  Edad: %d \n", dato.edad);
    printf("-----------------------\n");
}

void mostrarNodo(nodo * aux)
{
    mostrarPersona(aux->dato);
}

void recorrerYmostrar(nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
                 
        }
    }
    return seg;
}

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}


nodo * buscarNodo( nodo * lista, char nombre[20])
///busca un nodo por nombre y retorna su posici¢n de memoria
///si no lo encuentra retorna NULL.
{
    nodo * seg;		///apunta al nodo de la lista que este  siendo leido.
    seg = lista;  	///con esto evito cambiar el valor de la variable
                    ///lista, que contiene un puntero al primer nodo de la
                    ///lista vinculada
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 ))
        ///busco mientras me quede lista por recorrer y no haya encontrado el nombre
    {
        seg=seg->siguiente;	//avanzo hacia el siguiente nodo.
    }
    ///en este punto puede ha fallado alguna de las dos condiciones del while
    ///si fallo la primera es debido a que no encontro lo que buscaba (seg es NULL)
    ///si fall la segunda es debido a que se encontro el nodo buscado.
    return seg;
}

nodo * borrarNodo(nodo * lista, char nombre[20])
// elimino un nodo de la lista y retorno un puntero al primer elemento de la misma.
// esto ultimo es necesario para el caso en que se elimina el primer elemento de la lista,
// se modifica el contenido de la variable lista, y eso no se puede hacer de la forma en
// que esta declarada. Para poder hacerlo deber¡a poner **lista. :)
{
    nodo * seg;
    nodo * ante;	//apunta al nodo anterior que seg.

    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 ))
    {
        nodo * aux = lista;
        lista = lista->siguiente; //salteo el primer nodo.
        free(aux); //elimino el primer nodo.
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 ))
        {
            ante = seg;	//adelanto una posicion la var ante.
            seg = seg->siguiente; //avanzo al siguiente nodo.
        }
        //en este punto tengo en la variable ante la direccion de memoria del
        //nodo anterior al buscado, y en la variable seg, la dir de memoria del
        //nodo que quiero borrar.
        if( seg!= NULL)
        {
            ante->siguiente = seg->siguiente; //salteo el nodo que quiero eliminar.
            free(seg); //elimino el nodo.
        }
    }
    return lista; //debo retornar el puntero al primer nodo, por el tipo de pasaje de parametros.
    //No puedo modificar el contenido de la var lista, que no es lo mismo
    //que modificar *lista (contenido de la direccion de memoria apuntada
    //por lista.
    //Otra forma de resolverlo es poner el par metro **lista. :)
}


int main()
{
    printf("Hello listas!\n");


    persona aux1= {"pepe grillo", 23};
    persona aux2= {"maria perez", 31};
    persona aux3= {"bart simpson", 10};

    ///  variable estática definida en el main()
    nodo * lista=inicLista();


    lista=agregarPpio(lista, crearNodo(aux1));
    lista=agregarPpio(lista, crearNodo(aux2));
    lista=agregarPpio(lista, crearNodo(aux3));




    recorrerYmostrar(lista);

    return 0;
}
