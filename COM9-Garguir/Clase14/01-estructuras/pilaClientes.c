#include "pilaClientes.h"


void inicPila(PilaCli* p){
    (*p)=inicLista();
}

int pilaVacia(PilaCli* p){
    int rta = 0;

    if((*p)==NULL){
        rta = 1;
    }else{
        rta = 0;
    }

    return rta;
}

int pilaVaciaPro(PilaCli* p){
    return ((*p)==NULL)?1:0;
}

void apilarCliente(PilaCli* p, stCliente c){
    (*p)=agregarAlPrincipio((*p),crearNodo(c));
}

void apilarClientePD(PilaCli* p, stCliente c){
    agregarAlPrincipioPD(p,crearNodo(c));
}

stCliente desapilarCliente(PilaCli* p){
    stCliente c = (*p)->dato;
    (*p) = eliminarPrimerNodo(*p);
    return c;
}

stCliente topeCliente(PilaCli* p){
    return (*p)->dato;
}
