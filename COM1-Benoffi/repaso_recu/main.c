//3. Diseñar una aplicación que ofrezca, a través de un menú, la posibilidad de calcular áreas de figuras
//geométricas específicas. Se deben codificar funciones que calculen las áreas de: círculo, cuadrado, rectángulo,
// triángulo y trapecio. Las fórmulas pueden buscarse en libros de geometría de nivel secundario (polimodal).
#include<stdio.h>
#include<conio.h>
float triangulo(int base, int altura);
int cuadrado(int lado);
void menu () ;
int main ()
{
    char seguir;
    printf("desea calcular un area? (s/n)");
    fflush(stdin);
    scanf("%c", &seguir );
    while(seguir=='s')
    {
        menu();

        printf("desea calcular un area? (s/n)");
        fflush(stdin);
        scanf("%c", &seguir);
    }//fin de while
    return 0;

}
float triangulo(int base, int altura)
{
    float resultado ;
    resultado=(float)(base*altura)/(float)2 ;
    return resultado;
}//fin funcion triangulo
int cuadrado(int lado)
{
    int resultado;
    resultado=lado*lado ;

    return resultado;
}//fin funcion cuadrado

int rectangulo(int base, int altura)
{
    int resultado;
    resultado= base*altura ;
    return resultado;
} //fin funcion rectangulo
float trapecio (float base_mayor, float base_menor, float altura)
{
    float resultado;
    resultado=((base_mayor+base_menor)*altura)/2;
    return resultado;
}//fin funcion trapecio
void menu ()
{
    int opcion;
    int base_menu, altura_menu, lado_menu, base_rectangulo, altura_rectangulo, base_mayor, base_menor, altura ;
    float resultado;
    printf("ingrese 1 para calcular el area de un triangulo \n");
    printf("ingrese 2 para calcular el area de un cuadrado \n");
    printf("ingrese 3 para calcular el area de un rectangulo \n");
    printf("ingrese 4 para calcular el area de un trapecio \n");
    printf("ingrese 5 para salir del programa");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        printf("ingrese la base y altura del triangulo \n");
        scanf("%d %d", &base_menu, &altura_menu);
        resultado=triangulo(base_menu, altura_menu);
        printf("el area del triangulo es: %f \n", resultado);
        break;
    case 2:
        printf("ingrese un lado del cuadrado \n");
        scanf("%d", &lado_menu);
        resultado=cuadrado(lado_menu);
        printf("el area del cuadrado es : %f \n", resultado);
        break ;
    case 3:
        printf("ingrese base y altura del rectangulo \n");
        scanf("%d %d", &base_rectangulo, &altura_rectangulo);
        resultado= rectangulo(base_rectangulo, altura_rectangulo);
        printf("el area del rectangulo es: %d \n", resultado);
        break;
    case 4:
        printf("ingrese la base mayor , base menor y la altura \n");
        scanf("%f %f %f", base_mayor, base_menor, altura);
        resultado=trapecio(base_mayor, base_menor, altura);
        printf("el area del trapecio es: %f \n");
        break;

    case 5:
        printf("gracias por usar el programa \n");
        break;
    default:
        printf("error \n");
        break ;

    }//fin funcion menu
}
