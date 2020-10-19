#ifndef ARBOLABB_H_INCLUDED
#define ARBOLABB_H_INCLUDED

typedef int tipoDato;

typedef struct nodoA
{
    tipoDato dato;
    struct nodoA* izq;
    struct nodoA* der;

}nodoA;


nodoA* crearNodoArbol(tipoDato);
void insertarABB(nodoA**, tipoDato);
int minimoABB(nodoA*);
int maximoABB(nodoA*);
void eliminarGrado1uHoja(nodoA**,tipoDato dato);

#endif // ARBOLABB_H_INCLUDED
