#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct
{
    int dato;
    struct nodo * sig;
} nodo;


nodo * inicLista();
nodo * crearNodo(int );
nodo * agregarAlPrincipio (nodo * , nodo * );
nodo * buscarUltimo (nodo * );
nodo * agregarAlFinal (nodo * , nodo * );
nodo * deArchivoALista (nodo * lista, char  []);
void mostrarLista (nodo * );

#endif // LISTA_H_INCLUDED
