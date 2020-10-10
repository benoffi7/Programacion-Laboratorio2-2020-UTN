#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicLista2();
    fila->fin = inicLista2();
}

void agregar(Fila* fila, stCliente dato){
    nodo2* nuevo = crearNodo2(dato);

    fila->fin = agregarAlFinal2(fila->fin, nuevo);

    if(fila->inicio==NULL){
        fila->inicio = fila->fin;
    }

    fila->fin=nuevo;
}

stCliente primero(Fila* fila){
    stCliente c;
    if(fila->inicio){
        c=verPrimero2(fila->inicio);
    }

    return c;
}

stCliente primeroPro(Fila* fila){
    return verPrimero2(fila->inicio);
}

stCliente extraer(Fila* fila){
    stCliente c;
    if(fila->inicio){
        c = verPrimero2(fila->inicio);
        fila->inicio = borrarPrimero2(fila->inicio);
        if(!fila->inicio){
            fila->fin = inicLista2();
        }
    }
    return c;
}

int filaVacia(Fila* fila){
    int resp=0;
    if(!fila->inicio){   /// if(fila->inicio == NULL)
        resp=1;
    }
    return resp;
}

int filaVaciaPro(Fila* fila){
    return (fila->inicio)?0:1;
}

void muestraFila(Fila* fila){
    muestraLista2(fila->inicio);
}
