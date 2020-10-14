#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct nodoArbol{
    stPersona dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;




#endif // ARBOL_H_INCLUDED
