#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoArbol
{
    struct nodoArbol * izq;
    struct nodoArbol * der;
    char nombreAlumno[30];
    int nota;
} nodoArbol;

typedef struct nodoLista
{
    struct nodoLista * sig;
    int nota;

} nodoLista;

typedef struct celda
{
    struct nodoLista * notas;
    char nombreAlumno[30];
} celda;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int dato,char nombre[30]);
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
int pasarDelArbolAlArregloDeListas(celda muchosAlumnos[30], nodoArbol * nodo, int validos);
void mostrarArreglo(celda muchosAlumnos[30], int validos);
void mostrarLista(nodoLista * lista);
int posAlumnoEnArreglo(celda muchosAlumnos[30], char nombre[30], int validos);
nodoLista * crearNodoLista(int nota);
nodoLista * agregarPpio(nodoLista * l, nodoLista * nn);
nodoLista * inicLista();

int main()
{
    nodoArbol * raiz = inicArbol();
    raiz = cargarMuchos(raiz);
    //nodoArbol * NMI = nodoMasIzquierda(raiz->der);
    //nodoArbol * NMD = nodoMasDerecha(raiz->izq);
    //printf("NMI %d\n",NMI->dato);
    //printf("NMD %d\n",NMD->dato);
    //raiz = borrarNodo(raiz,4);
    mostrar(raiz);
    celda muchosAlumnos[30];
    int validos = pasarDelArbolAlArregloDeListas(muchosAlumnos,raiz,0);
    printf("validos es %d\n",validos);
    mostrarArreglo(muchosAlumnos,validos);

    return 0;
}

int pasarDelArbolAlArregloDeListas(celda muchosAlumnos[30], nodoArbol * nodo, int validos)
{
    if (nodo != NULL)
    {
        if (validos<30)
        {
            int posBuscada = posAlumnoEnArreglo(muchosAlumnos,nodo->nombreAlumno,validos);
            if (posBuscada==-1)
            {
                muchosAlumnos[validos].notas = inicLista();
                strcpy(muchosAlumnos[validos].nombreAlumno,nodo->nombreAlumno);
                validos = validos + 1;
                posBuscada = validos - 1;
            }

            nodoLista * aux = crearNodoLista(nodo->nota);
            muchosAlumnos[posBuscada].notas = agregarPpio(muchosAlumnos[posBuscada].notas,aux);

            validos = pasarDelArbolAlArregloDeListas(muchosAlumnos,nodo->izq,validos);
            validos = pasarDelArbolAlArregloDeListas(muchosAlumnos,nodo->der,validos);
        }
    }
    return validos;
}

void mostrarArreglo(celda muchosAlumnos[30], int validos)
{
    int indice = 0;
    for (indice = 0;indice<validos;indice++)
    {
        printf("nombre --> %s\n",muchosAlumnos[indice].nombreAlumno);
        printf("lista de notas\n");
        mostrarLista(muchosAlumnos[indice].notas);
        printf("****************\n");
    }
}

void mostrarLista(nodoLista * lista)
{
    if (lista)
    {
        printf("nota --> %d\n",lista->nota);
        mostrarLista(lista->sig);
    }
}

int posAlumnoEnArreglo(celda muchosAlumnos[30], char nombre[30], int validos)
{
    int pos = -1;
    int indice;
    for (indice = 0; indice<validos; indice++)
    {
        if (strcmp(muchosAlumnos[indice].nombreAlumno,nombre) == 0)
        {
            pos = indice;
        }
    }
    return pos;
}

nodoLista * crearNodoLista(int nota)
{
    nodoLista * aux = (nodoLista*)malloc(sizeof(nodoLista));
    aux->sig = NULL;
    aux->nota = nota;
    return aux;
}

nodoLista * agregarPpio(nodoLista * l, nodoLista * nn)
{
    if (l == NULL)
    {
        l = nn;
    }
    else
    {
        nn->sig = l;
        l = nn;
    }
    return l;
}

nodoArbol * inicArbol()
{
    return NULL;
}

nodoLista * inicLista()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato, char nombre[30])
{
    nodoArbol * aux = (nodoArbol*) malloc(sizeof(nodoArbol));
    aux->nota = dato;
    strcpy(aux->nombreAlumno,nombre);
    aux->der = NULL;
    aux->izq = NULL;
    return aux;
}

nodoArbol * cargarMuchos(nodoArbol * raiz)
{
    char mander = 's';
    char nombre[30];
    int dato;
    int respuesta;
    while (mander == 's')
    {
        printf("ingrese una nota\n");
        fflush(stdin);
        scanf("%d",&dato);

        printf("ingrese un nombre\n");
        fflush(stdin);
        scanf("%s",&nombre);


        nodoArbol * nuevoNodo = crearNodoArbol(dato,nombre);

        raiz = insertar(raiz,nuevoNodo);

        printf("el dato ha sido insertado de manera correcta\n");



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
        if (nuevoNodo->nota < raiz->nota)
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
    case 1 :
        preorder(raiz);
        break;
    case 2 :
        inorder(raiz);
        break;
    case 3 :
        postorder(raiz);
        break;
    default:
        printf("no existe el modo. sorry not sorry \n");
    }
}

void mostrarNodo(nodoArbol * nodo)
{
    printf("----%s----\n",nodo->nombreAlumno);
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
        if (raiz->nota == dato)
        {
            respuesta = 1;
        }
        else
        {
            if (dato > raiz->nota)
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
        if (nodo->nota == dato)
        {
            if (nodo->izq!=NULL)
            {
                nodoArbol * masDer = nodoMasDerecha(nodo->izq);//busco la MAYOR (DER) clave de los MENORES (IZQ)
                //el 2 en nuestro ejemplo
                nodo->nota = masDer->nota; //hago el reemplazo!
                nodo->izq = borrarNodo(nodo->izq,masDer->nota); //volvemos a borrar pero la hoja que es más facil
            }
            else if (nodo->der!=NULL)
            {
                nodoArbol * masIzq = nodoMasIzquierda(nodo->der); //busco la MENOR (IZQ) clave de los MAYORES (DER)
                //el 5 en nuestro ejemplo
                nodo->nota = masIzq->nota;
                nodo->der = borrarNodo(nodo->der,masIzq->nota); //volvemos a borrar pero la hoja que es más facil
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
        else if (dato > nodo->nota)
        {
            nodo->der = borrarNodo(nodo->der,dato);
        }
        else if (dato < nodo->nota)
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
