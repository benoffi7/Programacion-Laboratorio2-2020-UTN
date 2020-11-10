#include <stdio.h>
#include <stdlib.h>
#include "listaDeArboles.h"
#include <string.h>

nodoListaDeArbol * inicLista ()
{
    return NULL;
}

nodoListaDeArbol * crearNodoLista (int anio)
{
    nodoListaDeArbol * nuevo = (nodoListaDeArbol * )malloc(sizeof(nodoListaDeArbol));
    nuevo->anioNacimiento = anio;
    nuevo->arbolPersonas = NULL;
    nuevo->sig = NULL;

    return nuevo;
}

nodoListaDeArbol * agregarEnOrden (nodoListaDeArbol * lista, nodoListaDeArbol * nuevo)
{
    if (!lista)
    {
        lista = nuevo;
    }
    else
    {
        if (nuevo->anioNacimiento < lista->anioNacimiento)
        {
            nuevo->sig = lista;
            lista = nuevo;
        }
        else
        {
            nodoListaDeArbol * aux = lista;
            nodoListaDeArbol * anterior = lista;
            while (aux !=NULL && aux->anioNacimiento < nuevo-> anioNacimiento )
            {
                ante = aux;
                aux = aux->sig;
            }

            ante->sig = nuevo;
            nuevo ->sig = aux;
        }
    }
    return lista;
}

void mostrarLista (nodoListaDeArbol * lista)
{
    while (lista)
    {
        printf("\n\n Anio de Nacimiento: %d\n", lista->anioNacimiento);
        mostrarArbol(lista->arbolPersonas);
        lista = lista->sig;
    }
}

nodoListaDeArbol * buscarNodoAnio (nodoListaDeArbol * lista, int anio)
{
    while (lista && lista->anioNacimiento != anio)
        lista = lista->sig;

    return lista;
}

nodoListaDeArbol * cargarDatosUsuario (nodoListaDeArbol * lista)
{
    char continuar = 's';
    nodoListaDeArbol * nodoEncontrado;
    persona nueva;
    nodoArbol * nuevoNodo;
    int anio;
    do
    {
        printf("Ingrese anio de nacimiento de la persona: ");
        scanf("%d", &anio);
        nodoEncontrado = buscarNodoAnio(lista, anio);
        if (nodoEncontrado == NULL)
        {
            nodoEncontrado = crearNodoLista(anio);
            lista = agregarEnOrden(lista,nodoEncontrado);
        }
        nueva = cargarPersona();
        nuevoNodo = crearNodoArbol(nueva);
        nodoEncontrado ->arbol = insertarEnArbol (nodoEncontrado->arbol,nuevoNodo);


    }
    while (continuar == 's');

    return lista;
}

nodoListaDeArbol * leerDatosArchivoLDA (char nombreArchivo[])
{
    nodoListaDeArbol * LDA=inicLista();
    nodoListaDeArbol * anioEncontrado = inicLista();
    nodoArbol * nuevo = inicArbol();
    registroArchivo reg;
    FILE * archi = fopen(nombreArchivo,"rb");

    if (archi)
    {
        while(fread(&reg,sizeof(registroArchivo),1,archi)>0)
        {
            anioEncontrado = buscarNodoAnio(LDA,reg.anioNacimiento);

            if (anioEncontrado == NULL)
            {
                anioEncontrado = crearNodoLista(reg.anioNacimiento);
                LDA = agregarEnOrden(LDA,anioEncontrado);
            }
            persona p;
            p.dni = reg.dni;
            strcpy(p.nombre,reg.nombre);
            nuevo = crearNodoArbol(p);

            anioEncontrado->arbolPersonas = insertarEnArbol(anioEncontrado->arbolPersonas,nuevo);
        }
        fclose(archi);
    }
    return LDA;
}

void guardarDatosArchivoLDA (char nombreARchivo[], nodoListaDeArbol * LDA)
{
    FILE * archi = fopen(nombreARchivo,"wb");

    if (archi)
    {
        while (LDA != NULL)
        {
            guardarArbol(archi,LDA->arbolPersonas,LDA->anioNacimiento);

            LDA = LDA->sig;
        }
        fclose(archi);
    }
}

void guardarArbol (FILE * archivoAbierto, nodoArbol * arbol, int anio)
{
    registroArchivo reg;
    if (arbol)
    {
        reg.anioNacimiento = anio;
        reg.dni = arbol->p.dni;
        strcpy (reg.nombre, arbol->p.nombre);

        fwrite(&reg,sizeof(registroArchivo),1,archivoAbierto);

        guardarArbol(archivoAbierto,arbol->izq, anio);
        guardarArbol(archivoAbierto,arbol->der, anio);
    }
}
