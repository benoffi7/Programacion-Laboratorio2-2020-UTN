#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "utilidades.h"
#include "gotoxy.h"
#include "cliente.h"
#define arRegistro "clientes.dat"

void ingresarRegistros();
stCliente ingresarUnRegistro();
void agregarRegistro(stCliente e);

int getLegajo();
void getNombre(char n[]);
void getApellido(char n[]);
void getDni(char n[]);
int getDepartamento();
int getEdad();
stCliente cargoRegistroArchivoRandom();
void guardaRegistroArchivo(char archivo[], stCliente e);
void generaArchivoRandom(int cantidad);
void espera();
int cuentaRegistros(char nombreArchivo[], int tamStruct);

#endif // REGISTROARCHIVO_H_INCLUDED
