#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

typedef int tipoDato;

typedef struct nodoA
{
   tipoDato dato;
   struct nodoA* izq;
   struct nodoA* der;
}nodoA;


nodoA* crearNodoA(tipoDato dato);




#endif // ARBOLBINARIO_H_INCLUDED
