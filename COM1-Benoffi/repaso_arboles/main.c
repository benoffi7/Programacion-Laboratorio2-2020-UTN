#include <stdio.h>
#include <stdlib.h>

typedef struct nodoArbol
{
    struct nodoArbol * izq;
    struct nodoArbol * der;
    int dato;
}nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * insertar(nodoArbol * raiz, nodoArbol * nuevoNodo);
nodoArbol * cargarMuchos(nodoArbol * raiz);
void mostrar(nodoArbol * raiz);
void mostrarNodo(nodoArbol * nodo);
void preorder(nodoArbol * nodo);
void inorder(nodoArbol * nodo);
void postorder(nodoArbol * nodo);
int existeNodo (nodoArbol * raiz, int dato);


int main()
{
    nodoArbol * raiz = inicArbol();
    raiz = cargarMuchos(raiz);
    mostrar(raiz);
    return 0;
}

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol * aux = (nodoArbol*) malloc(sizeof(nodoArbol));
    aux->dato = dato;
    aux->der = NULL;
    aux->izq = NULL;
    return aux;
}

nodoArbol * cargarMuchos(nodoArbol * raiz)
{
    char mander = 's';
    int dato;
    int respuesta;
    while (mander == 's')
    {
        printf("ingrese un dato\n");
        fflush(stdin);
        scanf("%d",&dato);

        respuesta = existeNodo(raiz,dato);

        if (respuesta == 0)
        {
            nodoArbol * nuevoNodo = crearNodoArbol(dato);

            raiz = insertar(raiz,nuevoNodo);

            printf("el dato ha sido insertado de manera correcta\n");
        }
        else
        {
            printf("ingrese un numero que no este repetido, gracias!\n");
        }

        printf("desea seguir? s/n \n");
        fflush(stdin);
        scanf("%c",&mander);
    }
    return raiz;
}

nodoArbol * insertar(nodoArbol * raiz, nodoArbol * nuevoNodo)
{
    if (raiz == NULL)
    {
        raiz = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->dato < raiz->dato)
        {
            raiz->izq = insertar(raiz->izq,nuevoNodo);
        }
        else
        {
            raiz->der = insertar(raiz->der,nuevoNodo);
        }
    }

    return raiz;
}

void mostrar(nodoArbol * raiz)
{
    int opcion = 0;
    printf("ingrese un modo de ver el arbol\n");
    fflush(stdin);
    scanf("%d",&opcion);
    switch (opcion)
    {
        case 1 : preorder(raiz);
                 break;
        case 2 : inorder(raiz);
                 break;
        case 3 : postorder(raiz);
                 break;
        default: printf("no existe el modo. sorry not sorry \n");
    }
}

void mostrarNodo(nodoArbol * nodo)
{
    printf("----%d----\n",nodo->dato);
}

void preorder(nodoArbol * nodo)
{
    if (nodo != NULL)
    {
        mostrarNodo(nodo);
        preorder(nodo->izq);
        preorder(nodo->der);
    }
}

void inorder(nodoArbol * nodo)
{
    if (nodo != NULL)
    {
        inorder(nodo->izq);
        mostrarNodo(nodo);
        inorder(nodo->der);
    }
}

void postorder(nodoArbol * nodo)
{
    if (nodo != NULL)
    {
        postorder(nodo->izq);
        postorder(nodo->der);
        mostrarNodo(nodo);
    }
}

int existeNodo (nodoArbol * raiz, int dato)
{
    int respuesta = 0;

    if (raiz!=NULL)
    {
        if (raiz->dato == dato)
        {
            respuesta = 1;
        }
        else
        {
            if (dato > raiz->dato)
            {
                respuesta = existeNodo(raiz->der,dato);
            }
            else
            {
                respuesta = existeNodo(raiz->izq,dato);
            }
        }
    }

    return respuesta;
}

int esHoja(nodoArbol * arbol)
{
    if ((arbol->izq == NULL) && (arbol->der == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//contar la cantidad de hojas HACER
//con la base de mostrar, sumar todos los valores HACER
