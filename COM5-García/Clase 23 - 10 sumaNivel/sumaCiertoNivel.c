#include <stdio.h>
#include <stdlib.h>

//sumar datos(nodos) de cierto nivel
int sumarNivel(nodoA* A, int nivel)
{
  if (A != NULL)
  {
     if (nivel == 0) //estoy parado en el nivel que buscaba
     {
        return A->dato;
     }
    else
      {
          return sumarNivel(A->izq,nivel-1) + sumarNivel(A->der,nivel-1); //avanzo sumando rama derecha y rama izquierda
      }

  }
  else
    {
        return 0; //retorna 0 si esta vacio
    }

}


int main()
{


    return 0;
}
