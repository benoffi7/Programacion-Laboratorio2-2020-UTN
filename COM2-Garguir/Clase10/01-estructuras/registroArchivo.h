#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "empleados.h"
#include "utilidades.h"
#include "gotoxy.h"
#define AR_EMPLEADOS "empleados.dat"

void ingresarRegistros();
stEmpleado ingresarUnRegistro();
void agregarRegistro(stEmpleado e);

void getNombre(char n[]);
void getApellido(char a[]);
void getDNI(char dni[]);
void getCUIL(char cuil[], char dni[]);
void getEmail(char email[], char nombre[], char apellido[]);
void getDomicilio(char c[]);
void getTelefono(char tel[]);
int getTipo();
int getSueldo();

stEmpleado cargoRegistroArchivoRandom();
void guardaRegistroArchivo(char archivo[], stEmpleado e);
void generaArchivoRandom(int cantidad);
void espera();
int buscaDNI(char dni[]);

#endif // REGISTROARCHIVO_H_INCLUDED
