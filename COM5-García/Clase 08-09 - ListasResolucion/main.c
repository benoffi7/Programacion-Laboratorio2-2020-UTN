#include <stdio.h>
#include <stdlib.h>
#define nomArch "archivo.bin"


//1Hacer un programa que lea de un archivo datos y los inserte en una lista.
void insertaDatos(nodo** lista)
{
    int dato,
        FILE* fp= fopen(nomArch,"rb");
    if (fp)
    {
        while (fread(&dato,sizeof(int),1,arch)>0)
        {
            insertaAlPrincipio(lista,dato); //visto en teoria
        }
        fclose(arch);
    }

}
//2Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.
void insertaDatos(nodo** lista)
{
    int dato,
        FILE* fp= fopen(nomArch,"rb");
    if (fp)
    {
        while (fread(&dato,sizeof(int),1,arch)>0)
        {
            insertaEnOrden(lista,dato); //visto en teoria
        }
        fclose(arch);
    }

}


//3 en teoria



//Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva //lista. Se deben redireccionar los punteros.

//variación de la teoría, en este caso inserta un nodo

void intercalar(nodo* lista1, nodo* lista2,nodo** lista3)
{
    nodo* aux;
    while (lista1!= NULL && lista2 != NULL)
    {
        if ((lista1)->dato < (lista2)->dato)
        {
	    aux=lista1;
	    lista1=lista1->sig;
	    aux->sig=NULL;
            insertarNodoAlFinal(lista3,aux);

        }
        else if (lista1->dato >lista2->dato)
        {
	    aux=lista2;
 	    lista2=lista2->sig;
 	    aux->sig=NULL;
            insertarNodoAlFinal(lista3,aux);

        }
        else
        {
            aux=lista1;
            lista2=lista2->sig;
            lista1=lista1->sig;
            aux->sig=NULL;
            insertaNodoAlFinal(lista3,aux);
        }
    }
    while (lista1 != NULL)
    {
	aux=lista1;
 	lista1=lista1->sig;
 	aux->sig=NULL;
    insertarNodoAlFinal(lista3,aux);

    }
    while (lista2 != NULL)
    {
	aux=lista2;
	lista2=lista2->sig;
	aux->sig=NULL;
    insertarNodoAlFinal(lista3,aux);
    }
}

//6 Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)

}
//1 2 3 4 5
aux//1->NULL
//2 3 4 5 1
aux 2
// 3 4 5 1 2
...
//1 2 3 4 5
..
//1 2 3 4 5
lista=lista->sig;
aux = 1 ->NULL
aux->sig=NULL
lista // 2 3 4 5
listaInvertida //1

lista=lista->sig;
aux = 2
aux->sig=NULL
lista // 3 4 5
listaInvertida //2 1

aux= 3
lista=lista->sig;
aux->sig=NULL
lista // 4 5
listaInvertida // 3 2 1

aux = 4
lista= lista->sig;
aux->sig=NULL;
lista // 5
listaInvertida // 4 3 2 1

aux = 5
lista=lista->sig;
aux->sig=NULL;
lista //NULL
listaInvertida // 5 4 3 2 1

*lista = listainvertida;

//listaInvertida 5->4->3->2->1->NULL

void invertir(nodo* lista)
{
    nodo* seg=*lista; //seguidora que avanza sobre la lista
    nodo* aux; //aux redirecciona el puntero actual
    nodo* listaInvertida=NULL; //donde se almacenarán las redirecciones
    while (seg != NULL)
    {
        aux=seg;
        seg=seg->sig;
        //insertar al principio
        aux->sig=listaInvertida;
        listaInvertida=aux;
    }
    (*lista)=listaInvertida; //asignamos la cabecera a la que contiene listaInvertida

}


//Utilizando el TDA Pila creado en el punto 5, cargar la pila con números enteros.
//Luego, recorrer dicha pila e insertar por orden de llegada (al final) en una lista simplemente //enlazada aquellos números que sean pares. Cuidado, la función no debe perder la pila original, //trabaje de forma tal que se conserven sus datos.




/**La referencia de P está ya que el valor de P (direccion de memoria), al ser una lista, para avanzar debemos eliminar el nodo (desapilar), entonces hacemos free de la direccion de memoria almacenada en la cabecera de la lista. Cuando volvemos a apilar ese dato, debemos volver a hacer una reserva de memoria, que devolverá otro valor de dirección. Por lo tanto, todos los usos de Pilas implementadas con listas, deben ser por referencia en los recorridos (cuando ocurre apilar y desapilar), ya que la cabecera SIEMPRE se encontrará afectada**/

//se recorre y se inserta al final de la lista
void recorrerPila(Pila *P, nodo** lista)
{
    Pila aux;
    inicPila(&aux);
    while (!pilavacia(*P))
    {
        apilar(&aux,desapilar(P));
        if (tope(aux) % 2 == 0)
            insertarAlFinal(lista,tope(aux)); //visto en teoria
    }
    while (!pilavacia(aux))
    {
        apilar(P,desapilar(&aux));
    }
}


//version con retorno de lista.
//se recorre y se inserta al final de la lista
nodo* recorrerPila(Pila *P, nodo* lista)
{
    Pila aux;
    inicPila(&aux);
    while (!pilavacia(*P))
    {
        apilar(&aux,desapilar(P));
        if (tope(aux) % 2 == 0)
            lista=insertarAlFinal(lista,tope(aux)); //visto en teoria
    }
    while (!pilavacia(aux))
    {
        apilar(P,desapilar(&aux));
    }
   return lista;
}



//Eliminar de la lista cargada en el ejercicio anterior, aquellos nodos que contengan valores menores a 10.
//algoritmo de eliminacion presentado en teoria


int main()
{

    return 0;
}
