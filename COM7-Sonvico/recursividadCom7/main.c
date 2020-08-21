#include <stdio.h>
#include <stdlib.h>

int factorial (int x){

    int rta;

    /// 1! = 1
    /// 0! = 1
    if(x==0)
    {
        rta=1;
    }
    else
    {
        rta=x*factorial(x-1);
    }
    return rta;

}


int main()
{
    printf("Hello world!\n");

    printf("%d", factorial(5));

    return 0;
}
