#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dim 30
void inicializarArreglo (int arreglo []);
int cargarArreglo (int arreglo[]);
int sumaArreglo (int arreglo [], int validos);
int contarValores (int arreglo[]);
float promedioArreglo (int arreglo[]);
void mostrarArreglo (int arreglo[], int validos);
int cargarCadenaCaracteres (char cadena []);
int cargarPalabra (char cadena[]);
void mostrarCadena (char cadena [], int validos);
int esCapicua (char cadena [], int validos);
void funcionContenedora (int arreglo [], int validos, int * maximo, int * minimo, float * promedio);
int valorMaximo (int arreglo [], int validos);
int valorMinimo (int arreglo [], int validos);
float promedioArreglo2 (int arreglo [], int validos);
int cargarArreglosParalelos (char apellidos [][dim], int edades []);
void mostrarParalelos (char apellidos [][dim], int edades[], int validos);
int buscarMayor (int edades [], int validos);
void printMayor (char apellidos [][dim], int edades [], int validos);



int main()
{
    /**1. Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:
a. Hacer una función que inicialice las celdas del arreglo en –1.
b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
c. Hacer una función que sume el contenido del arreglo y lo retorne.
d. Hacer una función que cuente la cantidad de valores ingresados.
e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d).
f. Hacer la función main correspondiente.*/

//    int arreglo [dim], validos = 0, suma = 0, contar = 0;
//    float promedio = 0;
//    inicializarArreglo(arreglo);
//    validos = cargarArreglo(arreglo);
//    mostrarArreglo(arreglo, validos);
//    suma = sumaArreglo(arreglo, validos);
//    printf ("La Suma es %d \n", suma);
//    contar = contarValores(arreglo);
//    printf("El conteo de valores es: %d\n", contar);
//    promedio = promedioArreglo(arreglo);
//    printf("El promedio es: %.2f\n", promedio);

    /**6. Dada una cadena de caracteres, hacer una función que determine si dicha cadena es capicúa o no. La función recibe
	como parámetro la cadena y retorna 1 o 0 según sea la respuesta.*/
//	char cadena [dim];
//	int validos = 0, flag = -1;
//	//validos = cargarCadenaCaracteres(cadena);
//	validos = cargarPalabra(cadena);
//	//mostrarCadena(cadena, validos);
//	flag = esCapicua(cadena, validos);
//	if (flag == 0)
//        printf ("La palabra no es capicua \n");
//    else printf ("La palabra es capicua \n");

    /**10. Hacer una función que reciba como parámetros de entrada un arreglo de enteros y su dimensión, y tres parámetros
    de salida, tres números enteros que representen: valor máximo, valor mínimo y promedio. Se debe usar pasaje de
    parámetros por referencia.*/
//    int arreglo [dim], validos = 0, maximo=0, minimo=0;
//    float promedio = 0;
//    validos = cargarArreglo(arreglo);
//    funcionContenedora(arreglo, validos, &maximo, &minimo, &promedio);
//    printf ("El valor maximo es: %d \nEl valor minimo es: %d\n El promedio es: %.2f\n", maximo, minimo, promedio);

    /**9. Dados dos arreglos paralelos, uno con apellidos y otro con edades.
    Se debe hacer un programa para encontrar el apellido de la persona de mayor edad. Se debe modularizar. */
    char apellidos [dim][dim];
    int edades [dim], validos = 0;
    validos = cargarArreglosParalelos(apellidos, edades);
    mostrarParalelos(apellidos, edades, validos);
    printMayor(apellidos, edades, validos);
    return 0;
}
void mostrarArreglo (int arreglo[], int validos)
{
    for (int i = 0; i < validos; i++)
        printf("[%d] ", arreglo[i]);
}
void inicializarArreglo (int arreglo [])
{
    for(int i = 0; i<dim; i++)
    {
        arreglo[i] = -1;
    }
}

int cargarArreglo (int arreglo[])
{
    int i = 0;
    char control = 's';
    while (control == 's' && i < dim)
    {
        printf ("Ingrese un numero\n");
        scanf ("%d", &arreglo[i]);
        i++;

        printf ("Desea seguir cargando numeros? s/n \n");
        fflush(stdin);
        scanf ("%c", &control);
    }
    return i;
}

int sumaArreglo (int arreglo [], int validos)
{
    int suma = 0;
    for (int i = 0; i < validos; i++)
        suma += arreglo[i];
        ///suma = suma + arreglo [i]; Es lo mismo que lo de arriba
    return suma;
}

int contarValores (int arreglo[])
{
    int i = 0;
    while ((arreglo[i] != -1) && (i < dim))
        i++;
    return i;
}

float promedioArreglo (int arreglo[])
{
    int suma = 0, cantidad = 0;
    cantidad = contarValores(arreglo);
    suma = sumaArreglo(arreglo, cantidad);
    return (float)suma/cantidad;
}

int cargarCadenaCaracteres (char cadena [])
{
    int i = 0;
    char control = 's';
    while (control == 's' && i < dim)
    {
        printf ("Ingrese un caracter \n");
        fflush(stdin);
        scanf ("%c", &cadena[i]);
        i++;

        printf ("Quiere ingresar otro caracter? s/n \n");
        fflush (stdin);
        scanf ("%c", &control);
    }
    return i;
}

int cargarPalabra (char cadena[])
{
    int validos = 0;
    printf ("Ingrese una palabra \n");
    fflush(stdin);
    gets(cadena);

    validos = strlen(cadena);
    return validos;

}

void mostrarCadena (char cadena [], int validos)
{
    for (int i = 0; i < validos; i++)
        printf ("%c", cadena[i]);
}

int esCapicua (char cadena [], int validos)
{
    int flag = 0, i = 0;
    while (cadena[i] == cadena[validos-1] && i <= validos)
    {
        i++;
        validos--;
    }
    if (i >= validos)
        flag = 1;
    return flag;
}
/**10. Hacer una función que reciba como parámetros de entrada un arreglo de enteros y su dimensión, y tres parámetros
    de salida, tres números enteros que representen: valor máximo, valor mínimo y promedio. Se debe usar pasaje de
    parámetros por referencia.*/
void funcionContenedora (int arreglo [], int validos, int * maximo, int * minimo, float * promedio)
{
    (*maximo) = valorMaximo(arreglo, validos);
    (*minimo) = valorMinimo(arreglo, validos);
    (*promedio) = promedioArreglo2(arreglo, validos);
}

int valorMaximo (int arreglo [], int validos)
{
    int maximo = arreglo[0];
    for (int i = 1; i < validos; i++)
    {
        if (arreglo[i] > maximo)
            maximo = arreglo[i];
    }
    return maximo;
}

int valorMinimo (int arreglo [], int validos)
{
    int minimo = arreglo[0];
    for (int i = 1; i < validos; i++)
    {
        if (arreglo[i] < minimo)
            minimo = arreglo[i];
    }
    return minimo;
}

float promedioArreglo2 (int arreglo [], int validos)
{
    int suma = 0;
    for (int i = 0; i < validos; i ++)
    {
        suma += arreglo[i];
    }
    return (float)suma/validos;
}

int cargarArreglosParalelos (char apellidos [][dim], int edades [])
{
    int i = 0;
    char seguir = 's';

    while (seguir == 's' && i < dim)
    {
        printf("Ingrese el apellido de la persona \n");
        fflush (stdin);
        gets(apellidos [i]);
        printf ("Ingrese la edad \n");
        scanf ("%d", &edades[i]);
        i++;

        printf ("Desea seguir ingresando datos? s/n \n");
        fflush(stdin);
        scanf ("%c", &seguir);
    }
    return i;
}
void mostrarParalelos (char apellidos [][dim], int edades[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf ("Apellido: %s\n", apellidos [i]);
        printf ("Edad: %d\n", edades [i]);
        printf ("\n\n");
    }
}

int buscarMayor (int edades [], int validos)
{
    int posMayor = 0;
    for (int i = 1; i < validos; i++)
    {
        if (edades[i] > edades[posMayor])
            posMayor = i;
    }
    return posMayor;
}

void printMayor (char apellidos [][dim], int edades [], int validos)
{
    int pos = buscarMayor (edades, validos);
    printf("Apellido del mayor: %s\n ",apellidos[pos]);
    printf ("Edad del mayor: %d\n", edades[pos]);
}
