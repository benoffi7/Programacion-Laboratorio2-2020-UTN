#include "Pila.h"
void inicPila(Pila * p)
{
    p->datos = inicLista();
}
void mostrar(Pila p)
{
    printf("\nTope ------------------------------------------- Base\n");
    mostrarLista(p->datos);

    printf("\nTope ------------------------------------------- Base\n");
}

