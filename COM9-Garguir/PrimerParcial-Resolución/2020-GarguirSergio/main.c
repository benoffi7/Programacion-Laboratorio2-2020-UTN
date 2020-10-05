#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

nodo* archivo2lista(char arPersonas[], nodo* lista);

int main()
{
    nodo* listaPersonas;
    listaPersonas=inicLista();

    listaPersonas = archivo2lista("personas.dat", listaPersonas);
    muestaListaRecursiva(listaPersonas);

    return 0;
}

/**
1.	Copiar los datos de las personas del archivo en una lista simplemente enlazada,
    insertando sus datos en orden por apellido.
*/

nodo* archivo2lista(char arPersonas[], nodo* lista){
    FILE *pArchi = fopen(arPersonas, "rb");
    stPersona p;
    if(pArchi){
        while(fread(&p, sizeof(stPersona), 1, pArchi)>0){
            lista=agregarEnOrdenApellido(lista, crearNodo(p));
        }
        fclose(pArchi);
    }
    return lista;
}
/**
2.	Hacer una función recursiva que sume las edades de las personas de la lista que tengan DNI par y sean mayores de edad.
    (Recuerde que el dato DNI es de tipo char[]).
*/
int sumaEdadesRecu(nodo* lista){
    int suma=0;
    if(lista){
        if(atoi(lista->dato.dni)%2==0 && lista->dato.edad > 17){
            suma = lista->dato.edad + sumaEdadesRecu(lista->siguiente);
        }else{
            suma = sumaEdadesRecu(lista->siguiente);
        }
    }
    return suma;
}

/**
3.	Hacer una función recursiva que busque la persona de menor edad en la lista y la retorne.
*/
stPersona buscaMenorRecu(nodo* lista){
    stPersona personaMenor;
    if(!lista->siguiente){
        personaMenor = lista->dato;
    }else{
        personaMenor = buscaMenorRecu(lista->siguiente);
        if(lista->dato.edad < personaMenor.edad){
            personaMenor = lista->dato;
        }
    }
    return personaMenor;
}
/**
4.	Hacer una función que recorra la lista y copie las personas cuyo apellido comience con una letra recibida
    por parámetro a una fila. (Recuerde que un string es un arreglo de caracteres).
*/

void lista2fila(nodo* lista, Fila* fila, char letra){
    nodo* aux = lista;
    while(aux){
        if(letra == lista->dato.apellido[0]){
            agregar(fila,aux->dato);
        }
        aux = aux->siguiente;
    }
}
/**
5.	Hacer una función recursiva que cuente las personas de la lista, mayores a una edad recibida por parámetro.
*/
int cuentaPersonas(nodo* lista, int edad){
    int cont=0;
    if(lista){
        if(lista->dato.edad > edad){
            cont = 1 + cuentaPersonas(lista->siguiente, edad);
        }else{
            cont = cuentaPersonas(lista->siguiente, edad);
        }
    }
    return cont;
}

/**
6.	Hacer una función que calcule el porcentaje de personas mayores a cierta edad con respecto al
    total de personas de la lista. (Para éste cálculo deberá utilizar la función anterior, piense!!!).
*/

float promedioPersonas(nodo* lista, int edad){
    int totalMayores = cuentaPersonas(lista, edad);
    int totalPersonas = cuantaPersonas(lista, 0);
    return (float) totalMayores / totalPersonas * 100;
}

float promedioPersonas(nodo* lista, int edad){
    return (float) cuentaPersonas(lista, edad) / cuantaPersonas(lista, 0) * 100;
}
