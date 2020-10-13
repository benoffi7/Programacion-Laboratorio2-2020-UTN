#include "arbolBinario.h"






void main()
{
  nodoA* arbol =NULL;
  arbol = crearNodoA(4);
  arbol->izq = crearNodoA(7);
  arbol->der = crearNodoA(10);
  arbol->der->izq = crearNodoA(5);
  arbol->der->der = crearNodoA(12);
  arbol->izq->izq = crearNodoA(2);
  arbol->izq->izq->izq = crearNodoA(1);
  arbol->izq->izq->der = crearNodoA(9);
  arbol->izq->izq->der->izq = crearNodoA(6);
  printf("%d",cantGrado1(arbol));





}
