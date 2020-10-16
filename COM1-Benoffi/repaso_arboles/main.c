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
nodoArbol * nodoMasIzquierda(nodoArbol * nodo);
nodoArbol * nodoMasDerecha(nodoArbol * nodo);
nodoArbol * borrarNodo(nodoArbol * nodo, int dato);


int main()
{
    nodoArbol * raiz = inicArbol();
    raiz = cargarMuchos(raiz);
    //nodoArbol * NMI = nodoMasIzquierda(raiz->der);
    //nodoArbol * NMD = nodoMasDerecha(raiz->izq);
    //printf("NMI %d\n",NMI->dato);
    //printf("NMD %d\n",NMD->dato);
    raiz = borrarNodo(raiz,4);
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

nodoArbol * borrarNodo(nodoArbol * nodo, int dato)
{
    if (nodo == NULL)
    {
        //fin del arbol,rama u hoja
    }
    else // hay algo
    {
        if (nodo->dato == dato)
        {
            if (nodo->izq!=NULL)
            {
                nodoArbol * masDer = nodoMasDerecha(nodo->izq);//busco la MAYOR (DER) clave de los MENORES (IZQ)
                //el 2 en nuestro ejemplo
                nodo->dato = masDer->dato; //hago el reemplazo!
                nodo->izq = borrarNodo(nodo->izq,masDer->dato); //volvemos a borrar pero la hoja que es más facil
            }
            else if (nodo->der!=NULL)
            {
                nodoArbol * masIzq = nodoMasIzquierda(nodo->der); //busco la MENOR (IZQ) clave de los MAYORES (DER)
                //el 5 en nuestro ejemplo
                nodo->dato = masIzq->dato;
                nodo->der = borrarNodo(nodo->der,masIzq->dato); //volvemos a borrar pero la hoja que es más facil
            }
            else
            {
                if (esHoja(nodo)==1)
                {
                    free(nodo);
                    nodo = NULL;
                }
            }
        }
        else if (dato > nodo->dato)
        {
            nodo->der = borrarNodo(nodo->der,dato);
        }
        else if (dato < nodo->dato)
        {
             nodo->izq = borrarNodo(nodo->izq,dato);
        }
    }
    return nodo;
}


nodoArbol * nodoMasDerecha(nodoArbol * nodo)
{
    if (nodo!=NULL)
    {
        if (nodo->der!=NULL)
        {
            nodo = nodoMasDerecha(nodo->der);
        }
    }
    return nodo;
}

nodoArbol * nodoMasIzquierda(nodoArbol * nodo)
{
    if (nodo!=NULL)
    {
        if (nodo->izq!=NULL)
        {
            nodo = nodoMasIzquierda(nodo->izq);
        }
    }
    return nodo;
}
