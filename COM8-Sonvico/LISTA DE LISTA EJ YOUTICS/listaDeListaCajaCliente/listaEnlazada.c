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

void recorrerYmostrarClientes(nodo * lista)
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
void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre_apellido);
    printf("  Cantidad de Productos: %d \n", dato.cantProductos);
    printf("-----------------------\n");
}

persona cargarPersona()
{
    persona aux;
    fflush(stdin);
    printf("Ingrese Nro de Cliente: ");
    scanf("%d", &aux.nroCliente);
    fflush(stdin);
    printf("Ingrese nombre y apellido: ");
    gets(aux.nombre_apellido);
    fflush(stdin);
    printf("Ingrese Cantidad de productos:");
    scanf("%d", &aux.cantProductos);

    return aux;
}

void mostrarNodo(nodo * aux)
{
    mostrarPersona(aux->dato);
}

nodo * buscarNodo( nodo * lista, char nombre[20])
///busca un nodo por nombre y retorna su posici¢n de memoria
///si no lo encuentra retorna NULL.
{
    nodo * seg;
    seg = lista;
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre_apellido)!=0 ))
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodo * borrarNodo(nodo * lista, char nombre[20])
{
    nodo * seg;
    nodo * ante;	//apunta al nodo anterior que seg.

    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre_apellido)==0 ))
    {
        nodo * aux = lista;
        lista = lista->siguiente; //salteo el primer nodo.
        free(aux); //elimino el primer nodo.
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.nombre_apellido)!=0 ))
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
        if(strcmp(nuevoNodo->dato.nombre_apellido,lista->dato.nombre_apellido)<0)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {
            // busco el lugar en donde insertar el nuevo elemento.
            // necesito mantener la direccion de memoria del nodo anterior
            // al nodo que tiene un nombre mayor al del nuevo nodo.
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while( (seg != NULL)&&(strcmp(nuevoNodo->dato.nombre_apellido,seg->dato.nombre_apellido)>=0) )
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
