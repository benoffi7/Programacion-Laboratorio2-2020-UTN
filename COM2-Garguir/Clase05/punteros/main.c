#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} stPersona;

int cargarArregloChar(char arr[], int maximos);
void mostrarArregloChar(char arr[], int validos);
void intercambioChar(char *a, char *b);
void invertirArregloChar (char arreglo [], int validos);
int cargarArreglo(stPersona a[], int validos);
void mostrarArreglo(stPersona a[], int validos);
void muestraUnaPersona(stPersona a);
int pasaGenero(stPersona p[], int vPersona, stPersona g[], char genero);
stPersona* pasaGeneroMalloc(stPersona p[], int vPersona, stPersona *g, int *vGenero, char genero);
int pasaGeneroMalloc2(stPersona p[], int vPersona, stPersona **g, char genero);

int main()
{
    char c[100];
    int v=0;

    stPersona a[100];
    int vPersona=0;

    stPersona genero[30];
    int vGenero=0;

    stPersona *g=NULL;
    int vG=0;



    vPersona = cargarArreglo(a, vPersona);
    mostrarArreglo(a, vPersona);

    //g = pasaGeneroMalloc(a, vPersona, g, &vG, 'h');

    vG = pasaGeneroMalloc2(a, vPersona, &g, 'h');
    mostrarArreglo(g, vG);

    //  vGenero pasaGenero(a, vPersona, genero, 'h');
//   mostrarArreglo(genero, vGenero);


    printf("Hello world!\n");
    return 0;
}

int cargarArregloChar(char arr[], int maximos)
{
    int i = 0;
    char control = 's';

    while(i < maximos && (control == 'S' || control == 's'))
    {
        printf("Ingrese una letra: \n");
        fflush(stdin);
        scanf("%c", &arr[i]);
        i++;
        printf("Desea continuar cargando datos? (s | n) \n");
        fflush(stdin);
        scanf("%c", &control);
    }

    return i;
}

//Funcion que muestra una arreglo tipo char.
void mostrarArregloChar(char arr[], int validos)
{
    int i = 0;
    printf("Contenido del arreglo. \n");

    for(i; i < validos; i++)
    {

        printf("| %c |", arr[i]);
    }
    printf("\n");
}

void intercambioChar(char *a, char *b)
{
    char aux;
    aux=*a;
    *a=*b;
    *b=aux;
}


void invertirArregloChar (char arreglo [], int validos)
{
    int i=0;
    int j=validos - 1;

    while (i<j)
    {
        intercambioChar(&arreglo[i], &arreglo[j]);
        i++;
        j--;
    }
}

int cargarArreglo(stPersona a[], int v)
{
    char op = 's';

    while(v<30 && op == 's')
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(a[v].nombre);

        printf("\nIngrese genero (H/M): ");
        fflush(stdin);
        scanf("%c", &a[v].genero);

        printf("\nIngrese edad: ");
        scanf("%d", &a[v].edad);

        v++;

        printf("\n\nDesea cargar otro? s/n: ");
        op = getch();
    }


    return v;
}

void mostrarArreglo(stPersona a[], int validos)
{

    char gene[7];
    int i = 0;

    while(i<validos)
    {
        muestraUnaPersona(a[i]);
        i++;
    }
}

void muestraUnaPersona(stPersona a)
{
    char gene[10];

    if(a.genero == 'h')
    {
        strcpy(gene, "Hombre");
    }
    else
    {
        strcpy(gene, "Mujer");
    }

    printf("\n--------------------------------");
    printf("\nNOMBRE.......: %s", a.nombre);
    printf("\nGENERO.......: %s", gene);
    printf("\nEDAD.........: %d", a.edad);
    printf("\n--------------------------------\n");
}

int pasaGenero(stPersona p[], int vPersona, stPersona g[], char genero)
{
    int vGenero = 0;
    int i=0;
    while(i < vPersona && vGenero < 30)
    {
        if(p[i].genero == genero)
        {
            g[vGenero] = p[i];
            vGenero++;
        }
        i++;
    }

    return vGenero;
}

int cuentaGenero(stPersona p[], int vP, char g)
{
    int cont=0;
    for(int i=0; i<vP; i++ )
    {
        if(p[i].genero == g)
        {
            cont++;
        }
    }
    return cont;
}

/**********************************************************//**
*
* \brief Copia personas de un genero en particular a otro arreglo.
* \param stPersona p[] - Un arreglo de personas
* \param int vPersona - los validos del arreglo anterior
* \param stPersona *g - puntero a inicializar. Recuerden que estoy recibiendo una copia de un puntero. No es una referencia
* \param int *vGenero - puntero a entero que son los validos del arreglo
* \param char genero - el filtro de datos a utilizar
* \return stPersona * - el puntero al arreglo generado
*
***************************************************************/

stPersona* pasaGeneroMalloc(stPersona p[], int vPersona, stPersona *g, int *vGenero, char genero)
{
    *vGenero = cuentaGenero(p, vPersona, genero);
    g = malloc(sizeof(stPersona)*(*vGenero));

    int i=0;
    int j=0;
    while(i < vPersona)
    {
        if(p[i].genero == genero)
        {
            g[j] = p[i];
            j++;
        }
        i++;
    }

    return g;
}


/**********************************************************//**
*
* \brief Copia personas de un genero en particular a otro arreglo
* \param stPersona p[] - Un arreglo de personas
* \param int vPersona - los validos del arreglo anterior
* \param stPersona **g - referencia al puntero a inicializar
* \param char genero - el filtro de datos a utilizar
* \return int vGenero - los validos del arreglo cargado
*
***************************************************************/
int pasaGeneroMalloc2(stPersona p[], int vPersona, stPersona **g, char genero)
{
    int vGenero = cuentaGenero(p, vPersona, genero);
    (*g) = (stPersona*) malloc(sizeof(stPersona) * vGenero);

    int i=0;
    int j=0;
    while(i < vPersona)
    {
        if(p[i].genero == genero)
        {
            (*g)[j] = p[i];
            j++;
        }
        i++;
    }

    return vGenero;
}
