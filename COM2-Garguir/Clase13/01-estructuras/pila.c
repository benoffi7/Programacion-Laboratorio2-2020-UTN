#include "pila.h"

void inicPila(Pila* p){
    (*p) = inicLista();
}

int pilaVacia(Pila* p){
    int rta=0;
    if ((*p)==NULL){
        rta = 1;
    }else{
        rta = 0;
    }
    return rta;
}

int pilaVaciaPro(Pila* p){
    return ((*p)==NULL)?1:0;
}

void apilar(Pila* p, stEmpleado e){
    (*p)=agregarAlPrincipio((*p), crearNodo(e));
}

void apilarPD(Pila* p, stEmpleado e){
    agregarAlPrincipioPD(p, crearNodo(e));
}

stEmpleado desapilar(Pila* p){
    stEmpleado e = (*p)->dato;
    (*p)=eliminaPrimerNodo(*p);
    return e;
}

stEmpleado tope(Pila* p){
    return (*p)->dato;
}



