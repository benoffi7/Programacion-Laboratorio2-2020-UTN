#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicLista2();
    fila->fin = inicLista2();
}

void agregar(Fila* fila, stEmpleado e){
    nodo2* nuevo = crearNodo2(e);
    fila->fin = agregarAlFinal2(fila->fin, nuevo);
    if(fila->inicio==NULL){
        fila->inicio = nuevo;
    }
    fila->fin = nuevo;
}

stEmpleado extraer(Fila* fila){

}

stEmpleado primero(Fila* fila){
    return verPrimero2(fila->inicio);
}
