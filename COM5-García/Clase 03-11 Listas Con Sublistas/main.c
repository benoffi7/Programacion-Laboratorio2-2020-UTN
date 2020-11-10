#include <stdio.h>
#include <stdlib.h>
#define nomArch "AlumnosMateria.bin"

///dada una lista de materias, generar una lista de alumnos por cada materia

typedef struct
{
    int legajo;
    char nombreApe[30];
    char materia[30];
} registroArchivo;


int buscarMateria(nodoMateria* listaMaterias, char* materia)
{
    int enc = 0;
    while (listaMaterias != NULL && strcmp(listaMaterias->materia,materia) != 0)
    {
        listaMaterias = listaMaterias->sig;
    }
    if (listaMaterias != NULL)
    {
        enc = 1;
    }

    return enc;
}

void agregarMateria(nodoMateria** listaMaterias, char* materia)
{
    nodoMateria nuevo = crearNodoMateria(materia);
    nuevo->sig = *listaMaterias;
    *listaMaterias = nuevo;

}

void agregarAlumno(nodoAlumno** alumnos, char* nomApe, int legajo)
{
    //se agrega un alumno a la lista de alumnos


}

void agregarAlumnoDeMateria(nodoMateria* listaMaterias, char* nomApe, int legajo, char* materia)
{
    while (strcmp(listaMaterias->materia,materia) != 0)
    {
        listaMaterias = listaMaterias->sig;
    }
    agregarAlumno(&(listaMaterias->listaAlumnos),nomApe,legajo);

}

void pasarArchivoALista(nodoMateria** listaMaterias)
{
    FILE* fp = fopen(nomArch,"rb");
    registroArchivo r;
    int enc;
    if (fp)
    {
        while (fread(&r,sizeof(registroArchivo),1,fp) > 0 )
        {
            enc = buscarMateria(*listamaterias,r.materia);
            if (enc)
            {
                agregarAlumnoDeMateria(*listaMaterias,r.nombreApe,r.legajo,r.materia);

            }
            else
            {
                agregarMateria(listaMaterias,r.materia);
                agregarAlumnoDeMateria(*listaMaterias,r.nombreApe,r.legajo,r.materia);

            }
        }
        fclose(fp);
    }


}





int main()
{
    nodoMateria* lista = NULL;


    return 0;
}
