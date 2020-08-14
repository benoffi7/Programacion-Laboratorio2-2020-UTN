#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED
#include "empleados.h"


int ultimoIdEmpleado(char archivoEmplados[]);
int existeDNIEmpleado(char dni[]);
void ingresaEmpleadosArchivo();
void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado e);
void muestraArchivoDeEmpleados(char archivoEmpleados[]);
int ingresaEmpleadosArray(stEmpleado e[], int v, int dim);
void muestraArregloEmpleados(stEmpleado e[], int v);
int cuentaRegistros(char file[], int dataSize);

#endif // ARCHIVOEMPLEADOS_H_INCLUDED
