#include "listaEnlazada.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato= dato;
    aux->siguiente = NULL;
    return aux;
}

nodo * agregarPpio(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
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

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;//tomo la dir del siguiente.
        free(seg);//borro el actual.
        seg = proximo;//actualizo el actual con la dir del siguiente, para avanzar
    }
    return seg;
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

nodo * eliminaUltimoNodo(nodo * lista)
{
    nodo * aux;
    nodo * ante;

    if(lista)
    {
        if(lista->siguiente==NULL) /// la lista tiene un solo nodo
        {
            aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        else  /// la lista tiene mas de un nodo
        {
            aux=lista;
            while(aux->siguiente!=NULL)
            {
                ante=aux;
                aux=aux->siguiente;
            }
            free(aux);
            ante->siguiente=NULL;
        }
    }
    return lista;
}

nodo * eliminaPrimerNodo(nodo * lista)
{
    nodo * aux=lista;
    if(lista)
    {
        lista=lista->siguiente;
        free(aux);
    }
    return lista;
}

/** //////////////////////////////////////////////////*/
/// funciones que usan la estructura de persona
/** //////////////////////////////////////////////////*/

void mostrarNodo(nodo * aux)
{
    mostrarPersona(aux->dato);
}

nodo * buscarNodo( nodo * lista, char nombre[20])
///busca un nodo por nombre y retorna su posici¢n de memoria
///si no lo encuentra retorna NULL.
{
    nodo * seg;		//apunta al nodo de la lista que est  siendo leido.
    seg = lista;  	//con esto evito cambiar el valor de la variable
    //lista, que contiene un puntero al primer nodo de la
    //lista vinculada
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 ))
        //busco mientras me quede lista por recorrer y no haya encontrado el nombre
    {
        seg=seg->siguiente;	//avanzo hacia el siguiente nodo.
    }
    //en este punto puede ha fallado alguna de las dos condiciones del while
    //si fallo la primera es debido a que no encontro lo que buscaba (seg es NULL)
    //si fall la segunda es debido a que se encontro el nodo buscado.
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

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
// agrega un nuevo nodo a la lista manteniendo el orden.
{
    //Si la lista esta vacia agrego el primer elemento.
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        // si el nuevo elemento es menor que el primero de la lista,
        // agrego al principio.
        if(strcmp(nuevoNodo->dato.nombre,lista->dato.nombre)<0)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {
            // busco el lugar en donde insertar el nuevo elemento.
            // necesito mantener la direccion de memoria del nodo anterior
            // al nodo que tiene un nombre mayor al del nuevo nodo.
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while( (seg != NULL)&&(strcmp(nuevoNodo->dato.nombre,seg->dato.nombre)>=0) )
            {
                ante = seg;
                seg = seg->siguiente;
            }
            // inserto el nuevo nodo en el lugar indicado.
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;


}

/// fn extra

nodo * crearLista(nodo * lista){



    lista=agregarPpio(lista, crearNodo(crearPersona(130, "pepe", 89)));
    lista=agregarPpio(lista, crearNodo(crearPersona(10, "maria", 23)));
    lista=agregarPpio(lista, crearNodo(crearPersona(34, "juan", 34)));
    lista=agregarPpio(lista, crearNodo(crearPersona(294, "laura", 24)));
    lista=agregarPpio(lista, crearNodo(crearPersona(179, "jose", 28)));
    lista=agregarPpio(lista, crearNodo(crearPersona(50, "sergio", 55)));
    lista=agregarPpio(lista, crearNodo(crearPersona(68, "gustavo", 34)));
    lista=agregarPpio(lista, crearNodo(crearPersona(163, "soledad", 21)));

    return lista;

}
