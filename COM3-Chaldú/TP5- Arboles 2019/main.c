#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"
#include "arbolPersona.h"
#include "listaEnlazada.h"

/// 3. Hacer una función que copie el contenido del árbol en una lista vinculada.

/// la idea es recorrer el arbol en modo inorder.. e ir agregando al final de la lista
/// el nodo que se crea...

nodo * pasarArbolLista (nodoArbolPersona * arbol, nodo * lista)
{
    nodo * aux=NULL;
    if(arbol!=NULL)
    {

        lista=pasarArbolLista(arbol->izq, lista);

        aux=crearNodo(arbol->dato);
        lista=agregarFinal(lista, aux);

        lista=pasarArbolLista(arbol->der, lista);
    }
    return lista;
}

int main()
{
    printf(" Hello world of arboles de ints !\n");

    nodoArbol * arbolito = inicArbol();

    int A[]= {40,20,60,10,30,70,50,80,79};

    int i;

    for(i=0; i<9; i++)
    {
        arbolito=insertar(arbolito, A[i]);
    }

    printf("\n Mostrando en modo preorder...\n");
    preorder(arbolito);

    printf("\n Mostrando en modo inorder...\n");
    inorder(arbolito);

    printf("\n Mostrando en modo postorder...\n");
    postorder(arbolito);

    printf("\nLa suma es %d\n\n", sumarValoresArbol(arbolito));

    printf("\nDibujo del arbol\n\n");
    dibujarArbol(arbolito);

    nodoArbol * aux = buscar(arbolito, 22);
    if(aux!=NULL)
    {
        printf("\nEl dato esta!");
    }
    else
    {
        printf("\nEl dato NO esta!");
    }

    nodo * listaPersonas = inicLista();

    nodoArbolPersona * arbolitoPersona = inicArbol();

    arbolitoPersona =crearArbol(arbolitoPersona);

    puts("\nArbol de personas!\n");
    preorderPersona(arbolitoPersona);


    listaPersonas= pasarArbolLista(arbolitoPersona, listaPersonas);

    puts("\n\nLista de personas\n");

    recorrerYmostrar(listaPersonas);

    printf("\n\nLa altura del arbol de personas es %d", alturaDelArbol(arbolitoPersona));

    printf("\n\nLa cantidad de hojas del arbol de personas es %d", cuentaHojas(arbolitoPersona));

    printf("\n\nLa cantidad de nodos del arbol de personas es %d", contarNodosArbol(arbolitoPersona));

    nodoArbolPersona * buscado = NULL;

    buscado=buscarPersona(arbolitoPersona, 50);

    if(buscado)
    {
        printf("\nEl legajo  esta!\n");
        mostrarNodo(buscado);
    }
    else
    {
        printf("\nEl legajo NO esta!\n");
    }

     buscado = buscarEnpreorder(arbolitoPersona, "juan");

    if(buscado)
    {
        printf("\nEl nombre  esta!\n");
        mostrarNodo(buscado);
    }
    else
    {
        printf("\nEl nombre NO esta!\n");
    }

    return 0;
}
