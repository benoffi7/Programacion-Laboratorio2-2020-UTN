#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[20];
    int edad;
    char genero;
} stPersona;

void muestraUnaPersona(stPersona c);

#endif // CLIENTE_H_INCLUDED
