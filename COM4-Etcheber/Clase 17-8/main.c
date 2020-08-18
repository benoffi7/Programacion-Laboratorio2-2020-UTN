#include <stdio.h>
#include <stdlib.h>



int main()
{
    srand(time(NULL));



    int x= rand()%100;

    printf("%d\n",x);

    int * px = &x;

    modificarParametro(&px);

    printf("%d\n",x);

    int *ar = malloc(sizeof(int)*10);  /// int ar[10];

    ar[0]= 9;
    ar[2]= 27;

}


void modificarParametro (int ** a)
{
    *a = 8;
}
