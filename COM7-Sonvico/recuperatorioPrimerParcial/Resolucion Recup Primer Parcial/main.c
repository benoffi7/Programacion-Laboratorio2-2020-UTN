#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int NroCliente;
    char NyA[30];
} Cliente;

typedef struct _NodoPedido
{
    int NroPedido;
    Cliente cliente;
    float MontoCompra;
    struct _NodoPedido * siguiente;
} NodoPedido;

typedef struct
{
    int NroCliente;
    char NyA[30];
    int NroPedido;
    float MontoCompra;
} RegistroCompraCliente;

typedef struct
{
    struct NodoPedido * inicio;
    struct NodoPedido * fin;
} Pedidos;

/// inciso 1

/// fns de lista

NodoPedido * inicLista()
{
    return NULL;
}

NodoPedido * crearNodoPedido(RegistroCompraCliente reg)
{
    NodoPedido* nuevo = (NodoPedido*)malloc(sizeof(NodoPedido));

    nuevo->NroPedido = reg.NroPedido;
    nuevo->cliente.NroCliente = reg.NroCliente;
    nuevo->MontoCompra = reg.MontoCompra;
    strcpy(nuevo->cliente.NyA, reg.NyA);

    nuevo->siguiente=NULL;

    return nuevo;
}

NodoPedido * buscaUltimo(NodoPedido * lista)
{
    NodoPedido * seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente != NULL)
            seg=seg->siguiente;
    }
    return seg;
}

NodoPedido * agregarAlFinal(NodoPedido * lista, NodoPedido * nuevoN)
{
    if(lista==NULL)
    {
        lista=nuevoN;
    }
    else
    {
        NodoPedido * ultimo=buscaUltimo(lista);
        ultimo->siguiente=nuevoN;
    }
    return lista;
}

/// fns de TDA Fila

void inicFila(Pedidos * fila)
{
    fila->inicio=inicLista();
    fila->fin=inicLista();
}

void agregarAfila(Pedidos * fila, RegistroCompraCliente reg)
{
    NodoPedido * nuevo = crearNodoPedido(reg);

    fila->fin=agregarAlFinal(fila->fin, nuevo);

    if(fila->inicio == NULL)
        fila->inicio = fila->fin;

    fila->fin=nuevo;
}

void archivoToFila(char archivo[], Pedidos *fila)
{
    FILE * archi;
    RegistroCompraCliente reg;
    archi=fopen(archivo,"rb");

    if(archi!=NULL)
    {
        while(fread(&reg,sizeof(RegistroCompraCliente),1,archi) > 0)
        {
            agregarAfila(fila, reg);
        }
        fclose(archi);
    }
}

/// inciso 2
void cargaPedidosFila (Pedidos * fila)
{
    char cont='s';
    RegistroCompraCliente reg;

    do
    {
        printf("Ingrese numero de pedido:");
        scanf("%d", &reg.NroPedido);

        printf("Numero de cliente: ");
        scanf("%d", &reg.NroCliente);

        printf("Nombre y apellido del cliente:");
        fflush(stdin);
        gets(&reg.NyA);

        printf("Monto de compra:");
        scanf("%f", &reg.MontoCompra);

        printf("Continuar... s/n\n");
        fflush(stdin);
        scanf("%c", &cont);

        agregarAfila(fila, reg);
    }
    while(cont=='s');
}

/// inciso 3

float sumaMontoCompra(NodoPedido * lista)
{
    float suma;
    if(lista==NULL)
        suma=0;
    else
        suma=lista->MontoCompra + sumaMontoCompra(lista->siguiente);
    return suma;
}

/// inciso 4

/// fns lista
NodoPedido * borrarPrimero (NodoPedido * lista)
{
    NodoPedido * aBorrar = lista;
    if (lista!=NULL)
    {
        lista=lista->siguiente;
        free(aBorrar);
    }
    return lista;
}

/// que devolvemos como dato?
/// puede ser el nro de pedido o
/// un registroCompraCliente

int verPrimero (NodoPedido * lista)
{
    int nroPedido=0;

    if(lista)
        nroPedido=lista->NroPedido;

    return nroPedido;
}

/// fn del TDA Fila

int extraer(Pedidos* fila)
{
    int resp;

    if(fila->inicio!=NULL)
    {
        resp=verPrimero(fila->inicio);

        fila->inicio=borrarPrimero(fila->inicio);

        if(fila->inicio==NULL)
            fila->fin=inicLista();
    }
    return resp;
}

/// inciso 5

void listaToArchivo (NodoPedido * lista, char archivo[])
{
    FILE * archi=fopen(archivo,"wb");
    NodoPedido * seg;
    RegistroCompraCliente reg;

    if(lista!=NULL)
    {
        seg=lista;
        while(seg!=NULL)
        {
            if(seg->MontoCompra>5000)
            {
                reg.MontoCompra = seg->MontoCompra;
                reg.NroCliente = seg->cliente.NroCliente;
                reg.NroPedido = seg->NroPedido;
                strcpy(reg.NyA, seg->cliente.NyA);
                fwrite(&reg, sizeof(RegistroCompraCliente),1, archi);
            }
            seg=seg->siguiente;
        }
        fclose(archi);
    }
}

/// inciso 6

/// fns lista
void mostrarNodoPedido (NodoPedido * lista)
{
    printf("Numero de pedido: %d\n", lista->NroPedido);
    printf("Monto de compra: %f\n", lista->MontoCompra);
    printf("Numero de cliente: %d\n", lista->cliente.NroCliente);
    printf("Nombre y apellido del cliente: %s\n", lista->cliente.NyA);
}

void recorrerYmostrar(NodoPedido * lista)
{
    NodoPedido * seg=lista;
    while(seg!=NULL)
    {
        printf("\n");
        mostrarNodoPedido(seg);
        printf("\n");
        seg=seg->siguiente;
    }
}

/// fn del TDA Fila

void muestraFila(Pedidos * fila)
{
    recorrerYmostrar(fila->inicio);
}

/// inciso 7

int main()
{
    char archivo[]= {"registroCompraCliente.dat"};
    char archivoMayores[]= {"registroCompraClienteMayores.dat"};

    Pedidos filita;
    inicFila(&filita);

    printf("\nPasamos del archivo a la Fila\n\n");
    archivoToFila(archivo, &filita);
    muestraFila(&filita);

    printf("\n\n");
    system("pause");

    printf("\nCargamos nuevos datos a la Fila\n\n");
    cargaPedidosFila(&filita);
    muestraFila(&filita);

    printf("\n\n");
    system("pause");

    /// podrimamos hacer una fn intermediaria para consultar sobre la lista.

    printf("\nLa suma total de pedidos de la fila es $ %.2f", sumaMontoCompra(filita.inicio));

    printf("\n\n");
    system("pause");

    printf("\nSacamos un elemento de la Fila\n\n");

    int cli=extraer(&filita);

    printf("El nro de cliente extraido es %d \n", cli);


    system("pause");

    printf("\n\nLa fila ahora: \n");
    muestraFila(&filita);

    printf("\n\n");
    system("pause");

    printf("\Pasamos los datos a un nuevo archivo\n\n");
    listaToArchivo(filita.inicio, archivoMayores);


    printf("\n\n");
    system("pause");

    printf("\Pasamos los datos del nuevo archivo a otra fila\n\n");
    Pedidos mayores;

    inicFila(&mayores);

    archivoToFila(archivoMayores, &mayores);

    muestraFila(&mayores);

    return 0;
}


