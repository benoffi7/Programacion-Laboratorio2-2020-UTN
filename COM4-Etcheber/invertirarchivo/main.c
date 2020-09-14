#include <stdio.h>
#include <stdlib.h>
#define DIM 10
#include <time.h>
#define arEnteros "enteros2.dat"

int main()
{
    int arreglo[DIM];
    int validos = 0;
    srand(time(NULL));

//   for(int i = 0; i < DIM; i++){
//       arreglo[i] = rand()%300;
//       validos++;
//   }
//
//     for(int i = 0; i < DIM; i++){
//     printf("Arreglo[%d] = %d\n",i, arreglo[i]);
//    }
//    FILE* pEnteros = fopen(arEnteros, "wb");
//    if(pEnteros){
//
//
//         for(int i = 0; i < DIM; i++){
//            fwrite(&arreglo[i],sizeof(int),1,pEnteros);
//        }
//        fseek(pEnteros, 0, 0);
//
//
//        fclose(pEnteros);
//    }



   FILE* pEnteros = fopen(arEnteros, "r+b");
    if(pEnteros){

        fseek(pEnteros, 0, 0);

         for(int i = 0; i < DIM; i++){
            fread(&arreglo[i], sizeof(int), 1, pEnteros);
            validos++;
        }

         for(int i = 0; i < DIM; i++){
            printf("Arreglo[%d] = %d\n",i, arreglo[i]);
        }

        system("pause");
        fseek(pEnteros, 0 , 2);
        int cantidad = ftell(pEnteros) / sizeof(int);
        intercambiarPosiciones(0, cantidad, pEnteros);


        fclose(pEnteros);
    }



    return 0;
}

int  buscaMenorRecursivo(int arreglo[], int validos, int i){

    int menor = arreglo[i];

    if( i < validos - 1){

     menor = buscaMenorRecursivo(arreglo, validos, i+1);


     if(menor > arreglo[i]){
            menor = arreglo[i];
        }

    }
    return menor;
}



void intercambiarPosiciones(int pos,int cant ,FILE *archiEntero){



    if(pos < cant /2){

        int num1, num2;


        /// guardarmos los numeros a intercambiar
        fseek(archiEntero, sizeof(int) * pos , SEEK_SET);
        fread(&num1, sizeof(int), 1, archiEntero);

        fseek(archiEntero, sizeof(int) * (cant - pos - 1), 0);
        fread(&num2, sizeof(int), 1, archiEntero);

        /// usamos los numeros guardados y los intercambiamos
        fseek(archiEntero, sizeof(int) * pos , SEEK_SET);
        fwrite(&num2, sizeof(int), 1, archiEntero);

        fseek(archiEntero, sizeof(int) * (cant - pos - 1), 0);
        fwrite(&num1, sizeof(int), 1, archiEntero);

        ///hacemos la llamada recursiva
        intercambiarPosiciones(pos+1, cant, archiEntero);


    }



}
