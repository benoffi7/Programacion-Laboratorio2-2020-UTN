#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

#define AR_PERSONAS "personas.dat"

nodo* archivo2lista(nodo* lista);

int main()
{
    /// Punto 1.
    nodo* listaPersonas = inicLista();
    listaPersonas = archivo2lista(listaPersonas);
    muestraLista(listaPersonas);

    /// Punto 2.



    return 0;
}

/**
Copiar los datos de las personas del archivo en una lista simplemente enlazada,
insertando sus datos en orden por apellido.
*/

nodo* archivo2lista(nodo* lista){
    FILE* archi = fopen(AR_PERSONAS, "rb");
    stPersona p;
    if(archi){
        while(fread(&p, sizeof(stPersona), 1, archi)>0){
            lista=agregarEnOrdenApellido(lista, crearNodo(p));
        }

        fclose(archi);
    }
    return lista;
}

/**
Hacer una función recursiva que sume las edades de las personas de la lista que tengan
DNI par y sean mayores de edad. (Recuerde que el dato DNI es de tipo char[]).
*/
int sumaEdadesRecursiva(nodo* lista){
    int suma=0;
    if(lista){
        if(atoi(lista->dato.dni)%2 ==0 && lista->dato.edad > 17){
            suma = lista->dato.edad + sumaEdadesRecursiva(lista->siguiente);
        }else{
            suma = sumaEdadesRecursiva(lista->siguiente);
        }
    }

    return suma;
}

/**
Hacer una función recursiva que busque la persona de menor edad en la lista y la
retorne.
*/
stPersona buscaMenorRecursivo(nodo* lista){
    stPersona menor;
    if(!lista->siguiente){
        menor = lista->dato;
    }else{
        menor = buscaMenorRecursivo(lista->siguiente);
        if(lista->dato.edad < menor.edad){
            menor = lista->dato;
        }
    }

    return menor;
}

/**
Hacer una función que recorra la lista y copie las personas cuyo apellido comience con
una letra recibida por parámetro a una fila. (Recuerde que un string es un arreglo de
caracteres).
*/

void lista2fila(nodo* lista, Fila* fila, char letra){
    nodo* seg = lista;
    while(seg){
        if(seg->dato.apellido[0] == letra){
            agregar(fila, seg->dato);
        }
        seg = seg->siguiente;
    }
}

/**
Hacer una función recursiva que cuente las personas de la lista, mayores a una edad
recibida por parámetro.
*/
int cuentaPersonas(nodo* lista, int edad){
    int cont=0;
    if(lista){
        if(lista->dato.edad > edad){
            cont = 1 + sumaEdadesRecursiva(lista->siguiente);
        }else{
            cont = sumaEdadesRecursiva(lista->siguiente);
        }
    }

    return cont;
}

/**
Hacer una función que calcule el porcentaje de personas mayores a cierta edad con
respecto al total de personas de la lista (Para este cálculo deberá utilizar la función
anterior, piense!!!).
*/
float promedioPersonas(nodo* lista, int edad){
    int totalMayores = cuentaPersonas(lista, edad);
    int totalPersonas = cuentaPersonas(lista, 0);
    float por = (float) totalMayores / totalPersonas * 100;
    return por;
}
/// esta funcion requiere una lista con datos
float promedioPersonasPro(nodo* lista, int edad){
    return (float) cuentaPersonas(lista, edad) / cuentaPersonas(lista, 0) * 100;
}


