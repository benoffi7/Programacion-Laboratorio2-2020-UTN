#include "utilidades.h"

int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

void replicante(char c, int n){
    for(int i=0;i<n;i++){
        printf("%c",c);
    }
}
