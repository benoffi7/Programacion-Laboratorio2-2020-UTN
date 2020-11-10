#include "nodoCaja.h"

nodoCaja * inicListaCaja()
{
    return NULL;
}

nodoCaja * crearNodoCaja(caja c)
{
    nodoCaja * aux = (nodoCaja*)malloc(sizeof(nodo));
    aux->c = c;
    aux->listaClientes = inicLista();
    aux->siguiente = NULL;
    return aux;
}

nodoCaja * agregarPpioCaja(nodoCaja * lista, nodoCaja * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodoCaja * alta (nodoCaja *listaCajas, nodo * nuevoCliente, int nroCaja)
{
    nodoCaja *cajaEncontrada = buscarCaja(listaCajas,nroCaja);
    if(cajaEncontrada==NULL)
    {
        caja c = ingresarCaja(nroCaja);
        nodoCaja *nuevaCaja = crearNodoCaja(c);
        listaCajas = agregarPpioCaja(listaCajas, nuevaCaja);
        listaCajas->listaClientes = agregarFinal(listaCajas->listaClientes, nuevoCliente);
    }else{
        cajaEncontrada->listaClientes = agregarFinal(cajaEncontrada->listaClientes, nuevoCliente);
    }
return listaCajas;
}

nodoCaja * buscarCaja(nodoCaja * lista, int nroCaja)
{
    nodoCaja * seg = lista;
    nodoCaja *cajaEncontrada = NULL;
    int flag = 0;
        while(seg!= NULL && flag == 0)
        {
            if(seg->c.nroCaja == nroCaja)
            {
                cajaEncontrada = seg;
                flag=1;
            }
            seg = seg->siguiente;
        }
    return cajaEncontrada;
}

caja ingresarCaja(int nroCaja)
{
    caja c;
    c.nroCaja = nroCaja;
    printf("Ingresar Medio de Pago: \n");
    fflush(stdin);
    scanf("%s", &c.medio_Pago);
return c;
}

void recorrerYmostrarCajasClientes(nodoCaja * lista)
{
    nodoCaja * seg = lista;
    while (seg != NULL)
    {
        mostrarNodoCaja(seg);
        recorrerYmostrarClientes(seg->listaClientes);
        seg= seg->siguiente;
    }
}

void mostrarNodoCaja(nodoCaja * c)
{
    printf("Nro de Caja: %d\n", c->c.nroCaja);
    printf("Medio de Pago: %s", c->c.medio_Pago);
}

























