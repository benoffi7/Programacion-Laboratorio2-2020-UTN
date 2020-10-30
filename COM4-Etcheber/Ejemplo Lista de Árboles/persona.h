#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


typedef struct
{
    int dni;
    char nombre[30];
}persona;

///Funciones persona
persona cargarPersona();
void mostrarPersona(persona mostrar);
#endif // PERSONA_H_INCLUDED
