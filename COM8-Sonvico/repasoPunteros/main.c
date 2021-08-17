#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world repaso punteros!\n");
//    /// contenido       ///  dir de memoria
//    int a=10;               ///   10            ///  0060FEFC
//
//    int b=30;               /// 30              /// F3456789
//
//    int * puntero = &a;     /// 0060FEFC       ///
//
//    *puntero=20;
//
//    printf("       a:%d   donde vive a  %p\n\n", a, &a);
//    printf("*puntero:%d   donde vive a  %p donde vive puntero  %p\n\n", *puntero, puntero, &puntero);
//
//    int *  * punteroDoble = &puntero;
//
//    *punteroDoble=&b;
//
//    printf("*puntero:%d   donde vive b  %p donde vive puntero  %p\n\n", *puntero, puntero, &puntero);


    int * miPrimerVariableAnonima = (int*) malloc(sizeof(int)*1);
    int * miSegundaVariableAnonima = (int*) malloc(sizeof(int)*1);

    scanf("%d", miPrimerVariableAnonima);
    scanf("%d", miSegundaVariableAnonima);


    printf("%d %d   %p\n\n", __LINE__, *miPrimerVariableAnonima, miPrimerVariableAnonima);
    printf("%d   %p\n\n", *miSegundaVariableAnonima, miSegundaVariableAnonima);


    return 0;
}


