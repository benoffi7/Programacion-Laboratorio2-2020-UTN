#include <stdio.h>
#include <stdlib.h>
#define archSalida "notas.bin"



void pasarAFile(celda *arreglo, int validos)
{
    FILE *fp = fopen(archSalida,"ab");
    nodo* aux;
    if (fp)
    {
        for (int i = 0; i <validos ; i++)
        {
            aux= arreglo[i].lista;
            while (aux != NULL )
            {
                if (aux->dato.nota > 6)
                {
                    fwrite(&(aux->dato), sizeof(notaAlumno),1,fp);
                }
                aux = aux->sig;
            }

        }

      fclose(fp);
    }
}

void listaAFile(nodo* lista, FILE* fp )
{
    while (lista != NULL)
    {
        if (lista->dato.nota > 6)
        {
            fwrite(&(lista->dato),sizeof(notaAlumno),1,fp);
        }
        lista=lista->sig;
    }

}


void recorrerArregloFile(celda* arreglo, int validos)
{
    FILE *fp = fopen(archSalida,"ab");

    if (fp)
    {
        for (int i = 0; i < validos; i++)
        {
            listaAFile(arreglo[i].lista,fp);
        }
        fclose(fp);
    }

}




int main()
{
    printf("Hello world!\n");
    return 0;
}
