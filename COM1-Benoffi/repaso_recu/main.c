#include <stdio.h>
#include <stdlib.h>

int main()
{
    cantarCancion(2,0);
    return 0;
}

void cantarNaNaNa(int limite, int vuelta)
{
    if (vuelta<limite)
    {
        printf("-Nah-");
        cantarNaNaNa(limite,vuelta+1);
    }
}

void cantarEstribillo()
{
    cantarNaNaNa(9,0);
    printf("-Hey Jude!-");

}

void cantarCancion(int limite, int vuelta)
{
    if (vuelta < limite)
    {
        cantarEstribillo();
        printf("\n");
        cantarCancion(limite,vuelta+1);
    }
}
