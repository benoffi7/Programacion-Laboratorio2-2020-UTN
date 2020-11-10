#include <stdio.h>
#include <stdlib.h>
#include "listaCliente.h"
#include "nodoCaja.h"

nodoCaja * ingresarCajas(nodoCaja *lista);
int main()
{
    nodoCaja * listaCajaClientes = inicListaCaja();
    listaCajaClientes = ingresarCajas(listaCajaClientes);
    recorrerYmostrarCajasClientes(listaCajaClientes);
}

nodoCaja * ingresarCajas(nodoCaja *lista)
{
char continuar='s';
persona p;
int nroDeCaja;

    while(continuar=='s')
    {
        printf("\nIngresar Nro de Cliente:  ");
        fflush(stdin);
        scanf("%d", &p.nroCliente);

        printf("\nIngresar NOMBRE Y APELLIDO del Cliente:  ");
        fflush(stdin);
        gets(p.nombre_apellido);

        printf("\nIngresar CANTIDAD DE Producto:  ");
        fflush(stdin);
        scanf("%d", &p.cantProductos);

        printf("\n¿A QUE NUMERO DE CAJA DESEA INGRESAR EL CLIENTE?  \n");
        fflush(stdin);
        scanf("%d", &nroDeCaja);

        nodo * cliente = crearNodo(p);
        lista = alta(lista,cliente,nroDeCaja);

        printf("\n\nDesea continuar presione s:  ");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n\n");
    }
return lista;
}

