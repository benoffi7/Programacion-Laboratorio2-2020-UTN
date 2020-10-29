#include <stdio.h>
#include <stdlib.h>
#define DIM 30

///arreglo de listas, el arreglo es de materias que tienen nombre y campo que representa la lista de alumnos con sus
///respectivas notas, no hay orden considerado

int buscaPosMateria(Celda Materias[], char* materia,int validos)
{
    int i=0;
    int pos=-1;
    while (i < validos &&  pos == -1)
    {
        if (strcmp(materia,Materias[i].materia) == 0)
            pos= i;

      i++;
    }

    return pos;

}


int cargarMateria(Materias,materia,validos){

       strcpy(Materias[validos].materia,materia);
       Materias[validos].listaNotas = NULL.
       validos++;

 return validos;
}

void mostrarNombreAlumno(Alumno a)
{
    printf("%s", a.nomAlumno);
}

void mostrarNombresLista(nodo* lista)
{
    while (lista != NULL){

        //printf("%s", lista->a.nomAlumno);
        mostrarNombreAlumno(lista->a);
        lista=lista->sig;
    }

}

//mostrar el nombre de los alumnos de una determinada materia

void BuscarYmostrar(Celda Materias[],char* materia,int validos)
{
    int i=0;
    while (i < validos && strcmp(Materias[i].materia,materia) != 0)
    {
        i++;
    }
    if (i < validos)
    {
        mostrarNombresLista(Materias[i].listaNotas);
    }

}


int cargarDatos(Celda Materias[], char *materia, Alumno a, float nota, int validos)
{
   int pos;

   pos=buscaPosMateria(Materias,validos);
   if (pos == -1)
   {
       if (validos < DIM)
       {
           validos=cargarMateria(Materias,materia,validos); // ingresar la nueva materia
           pos=validos-1;                                   //e inicializar la lista correspondiente a esa celda
           insertarAlprincipio(&(Materias[pos].listaNotas),a,nota);
       }
       else
          printf("No hay mas espacio disponible para la nueva materia");
   }
   else
   {
       insertarAlprincipio(&(Materias[pos].listaNotas),a,nota);
   }

   return validos;

}




int main()
{
  int validos=0;
  Celda Materias[30];


    return 0;
}
