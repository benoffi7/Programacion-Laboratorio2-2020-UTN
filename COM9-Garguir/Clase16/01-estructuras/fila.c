#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicLista2();
    fila->fin = inicLista2();
}

void agregar(Fila* fila, stCliente dato){
    nodo2* nuevo = crearNodo2(dato);
    fila->fin = agregarAlFinal(fila->fin, nuevo);
    if(fila->inicio==NULL){
        fila->inicio = fila->fin;
    }
    fila->fin=nuevo;
}
