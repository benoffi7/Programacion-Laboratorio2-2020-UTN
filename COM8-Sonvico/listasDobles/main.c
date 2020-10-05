#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;
} nodoDoble;

nodoDoble * inicListaDoble()
{
    return NULL;
}

void recorrerYmostrar(nodoDoble * lista)
{
    if(lista)
    {
        printf("%d ", lista->dato);
        recorrerYmostrar(lista->siguiente);
    }
}

nodoDoble * crearNodoDoble(int dato)
{
    nodoDoble * aux= (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato=dato;

    aux->siguiente=NULL;

    aux->anterior=NULL;

    return aux;
}

nodoDoble * agregarPpioDoble(nodoDoble * lista, nodoDoble * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;

        lista->anterior=nuevo;

        lista=nuevo;
    }

    return lista;
}

nodoDoble * agregaFinalDoble(nodoDoble * lista, nodoDoble * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodoDoble * ultimo=lista;

        while(ultimo->siguiente!=NULL)
        {
            ultimo=ultimo->siguiente;
        }

        ultimo->siguiente=nuevo;

        nuevo->anterior=ultimo;
    }

    return lista;
}

nodoDoble * agregarEnOrdenDoble(nodoDoble * lista, nodoDoble * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato<lista->dato)
        {
            lista=agregarPpioDoble(lista, nuevo);
        }
        else
        {
            nodoDoble * seg=lista->siguiente;

            while(seg!=NULL && seg->dato<nuevo->dato)
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL) /// estoy agregando al medio de dos nodos
            {
                nodoDoble * ante=seg->anterior;

                /// esto es igual a lista simple
                ante->siguiente=nuevo;
                nuevo->siguiente=seg;

                /// nuevos enlaces de la lista doble
                nuevo->anterior=ante;
                seg->anterior=nuevo;
            }
            else /// tengo que agregar al final
            {
                lista=agregaFinalDoble(lista, nuevo);
            }
        }
    }
    return lista;
}

nodoDoble * borrarNodoDoble(nodoDoble * lista, int dato)
{
    nodoDoble * aux;

    if(lista)
    {
        if(lista->dato==dato)
        {
            aux = lista;
            lista = lista->siguiente;
            if(lista)
            {
                lista->anterior=NULL;
            }
            free(aux);
        }
        else
        {
            nodoDoble *seg=lista->siguiente;

            while(seg != NULL && seg->dato!=dato)
            {
                seg = seg->siguiente; //avanzo al siguiente nodo.
            }
            if( seg!= NULL)
        {
            nodoDoble * ante=seg->anterior;
            nodoDoble * proximo=seg->siguiente;

            ante->siguiente = seg->siguiente;
            if(proximo)
                {
                    proximo->anterior=ante;
                }
                free(seg);
            }
        }

    }
    return lista;
}

///esta fn debe utilizarse si tenemos mas de un nodo
/// codear la fn buscarUltimo :D
nodoDoble * buscarUltimo(nodoDoble * lista)
{
    nodoDoble * ultimo=lista;
    if(lista)
    {
        if(lista->siguiente!=NULL)
        {
            ultimo=buscarUltimo(lista->siguiente);
        }
    }
    return ultimo;
}

nodoDoble * eliminarPuntoMedio(nodoDoble * lista)
{
    /// validar que la lista tenga un solo nodo

    nodoDoble * inicio;
    nodoDoble * fin;

    if(lista)
    {
        if(lista->siguiente==NULL) // si la lista tiene un solo nodo
        {
            free(lista);
            lista=inicListaDoble();
        }
        else
        {
            inicio=lista;
            fin=buscarUltimo(lista);

            /// buscamos el punto medio
            while(inicio!=fin && fin->siguiente!=inicio)
            {
                inicio=inicio->siguiente;
                fin=fin->anterior;
            }
            /// al salir de este ciclo, la variable inicio queda apuntando al nodo medio o
            /// al inmediato superior de la lista (el que hay que borrar)

            /// borrado del nodo inicio
            /// salvando los enlaces de anterior y siguiente

            nodoDoble * ante=inicio->anterior; /// bajo a una variable el anterior

            ante->siguiente=inicio->siguiente; ///salteo el nodo que quiero eliminar

            if(inicio->siguiente!=NULL) /// si existe el nodo siguiente
            {
                nodoDoble * sig = inicio->siguiente;
                sig->anterior=ante;
            }
            free(inicio); ///elimino el nodo.
        }
    }
    return lista;
}

/// este codigo esta comentado porque corresponde a otro nombre de nodo doble
/// cambienlo, no sean pedorros!
/// Gus.

/*
int capicuaRecursivo(nodo2 * cabeza, nodo2 * cola)
{
    int capicua =1;

    if(cabeza!=NULL && cola!=NULL)
    {
        if (cabeza==cola||cabeza->ante==cola) /// si llegue al centro de la fila.. par o impar
        {
            capicua=1;
        }
        else
        {
            if(cabeza->dato==cola->dato)
            {
                capicua=capicuaRecursivo(cabeza->ste, cola->ante);
            }
            else
            {
                capicua=0;
            }
        }
    }
    return capicua;

}


int otroCapicuaRecursivo(nodo2 * cabeza, nodo2 * cola)
{
    int capicua=0;

    if(cabeza!=NULL && cola!=NULL)
    {
        if(cabeza->dato!=cola->dato) /// si no son iguales los datos... ya sabemos que no es capicua
        {
            capicua=0;
        }
        else /// si entra al else... es porque.... los datos ... son.... IGUALES!! :p
        {
            if(cabeza!=cola&&cabeza->ste!=cola) /// si no llegue al centro de la lista, sigo recorriendo
            {
                capicua=otroCapicuaRecursivo(cabeza->ste, cola->ante);
            }
            else  /// si llegue al centro... es CAPICUA!!
            {
                capicua=1;
            }
        }
    }
    return capicua;
}


int esCapicuaListasDobles(nodo2 * inicio, nodo2 * fin)
{

    int capicua;

    if(inicio&&fin)
    {
        if(inicio->dato!=fin->dato)
        {
            capicua=0;  /// no es capicua
        }
        else
        {
            if(inicio==fin || fin->ste==inicio)
            {
                capicua=1;
            }
            else
            {
                capicua=esCapicuaListasDobles(inicio->ste, fin->ante);
            }
        }
    }

    return capicua;
}

/// codigo de maxi

void capicuaNodoD(nodoD * lista)
{
    if(!lista)
    {
        printf("La lista esta vacia\n");
    }
    else
    {
        nodoD* primeroD = lista;
        nodoD* ultimoD = EncontrarUltimoD(lista);

        int i = realCapicua(primeroD, ultimoD);
        if(i == 1)
        {
            printf("la lista es capicua\n");
        }
        else
        {
            printf("la lista no es capicua\n");
        }
    }

}

int realCapicua(nodoD * primero, nodoD * ultimo)
{
    int i = 1;
    if(primero->dato != ultimo->dato)
    {
        i = 0;
    }
    else if(primero->siguiente != NULL && ultimo->ante != NULL)
    {
        i = realCapicua(primero->siguiente, ultimo->ante);
    }
    return i;
}
*/

int main()
{
    printf("Hello world!\n");

    nodoDoble * listaDoble=inicListaDoble();

    listaDoble=agregaFinalDoble(listaDoble, crearNodoDoble(1));
    listaDoble=agregaFinalDoble(listaDoble, crearNodoDoble(2));
    listaDoble=agregaFinalDoble(listaDoble, crearNodoDoble(3));
    listaDoble=agregaFinalDoble(listaDoble, crearNodoDoble(4));
    listaDoble=agregaFinalDoble(listaDoble, crearNodoDoble(5));

    printf("\nAntes de eliminar: \n");
    recorrerYmostrar(listaDoble);

    listaDoble=eliminarPuntoMedio(listaDoble);

    printf("\nDespues de eliminar: \n");
    recorrerYmostrar(listaDoble);

    return 0;
}
