#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main()
{
Fila F;
inicFila(&F);
poneFila(&F,'c');
poneFila(&F,'h');
if (!Filavacia(F))
{
    printf("%c", sacaFila(&F));
}
    return 0;
}
