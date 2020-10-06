#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estudiante.h"


void replicante(char c, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%c",c);
    }
}

void muestraUnEstudiante(estudiante e)
{
    printf("\nLegajo.....................: %d", e.legajo);
    printf("\nNombre y Apellido..........: %s %s",e.nombre,e.apellido);
    printf("\nDNI........................: %s",e.dni);
    printf("\nEdad.......................: %d",e.edad);
    printf("\nGenero.....................: %s ",(e.genero=='f')?"Femenino":"Masculino");
    printf("\nMaterias aprobadas.........: %d",e.cantMateriasAprobadas);
    printf("\nPromedio sin aplazos.......: %.2f",e.promedioSinAplazos);
    printf("\nPromedio con aplazos.......: %.2f\n",e.promedioConAplazos);
    replicante('-',50);
}

void muestraArchivoEstudiante()
{
    estudiante e;
    FILE * pArchEstu = fopen(arEstudiantes,"rb");
    if(pArchEstu)
    {
        while(fread(&e,sizeof(estudiante),1,pArchEstu)>0)
        {
            muestraUnEstudiante(e);
        }
        fclose(pArchEstu);
    }
}
