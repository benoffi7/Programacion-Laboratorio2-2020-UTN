#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#include "cliente.h"

int existeDNICliente(char dni[]);
int ultimoIdCliente();
void cargaClientesArchivo();
void guardaClienteArchivo(stCliente cliente);
void muestraClientesArchivo(char archCli[]);
int cargaClientesArreglo(stCliente c[], int v, int dim);
void muestraClientesArreglo(stCliente c[], int v);
int archivoClientes2Arreglo(char archivo[], stCliente c[], int v, int dim);
int archivoCompletoClientes2Arreglo(char archivo[], stCliente c[], int dim);
stCliente* archivoCompletoClientes2Arreglo1(char archivo[], stCliente *c, int *v);
int archivoCompletoClientes2Arreglo2(char archivo[], stCliente **c, int v);
int cuentaRegistros(char archivo[], int dataSize);

#endif // ARCHIVOCLIENTES_H_INCLUDED
