#include "registroArchivo.h"

/*
/// El usuario ingresa la cantidad de datos que quiera
void ingresarRegistros(){
    char opcion;
    stCliente e;

    do{
        system("pause");
        e = ingresarUnRegistro();
        agregarRegistro(e);
        printf("\n\t\t ESC para salir ...  ");
        opcion = getch();
    }
    while(opcion!=27);
}



/// se guarda un dato en el archivo
void agregarRegistro(stEmpleado e){
    FILE* pArchRegistro = fopen(arRegistro,"ab");
    if(pArchRegistro){
        fwrite(&e,sizeof(stEmpleado),1,pArchRegistro);
        fclose(pArchRegistro);
    }
}

/// Se muestra un dato de tipo stRegistroMedico
void mostrarUnRegistro(stEmpleado e){
    printf("\n Legajo..........................: %d",e.legajo);
    printf("\n Nombre y Apellido...............: %s",e.nombreApellido);
    printf("\n Edad............................: %d",e.edad);
    printf("\n Departamento....................: %d\n",e.idDepartamento);

    replicante('-',60);
}

/// Se recorre el archivo y usando la funcion mostrarUnRegistro() se muestran los datos del archivo
void mostrarRegistros(char archivo[]){
    stEmpleado r;
    FILE* pArchRegistro = fopen(archivo,"rb");
    if(pArchRegistro){
        while(fread(&r,sizeof(stEmpleado),1,pArchRegistro)>0){
            mostrarUnRegistro(r);
        }
        fclose(pArchRegistro);
    }
}

/// funcion que asigna en la variable recibida un nombre al azar
int getLegajo(){
    return randomRango(1,5000);
}

/// funcion que asigna en la variable recibida un nombre al azar
void getNombreApellido(char n[]){
    char nombres[][20] = {"Amalia ","Juan ","Roberta ","Antonio ","Juana ","Fernando ","Fernanda ","Anibal ","Antonia ","Roberto ",
                           "Anastasia ","Anastasio ","Artura ","Arturo ","Maria ","Mario ","Tamara ","Adolfo ","Adolfa ","Pedro ","Alfredo ",
                           "Alfreda ","Mauro ","Maura ","Benicio ","Benicia ","Ildefonso ","Ildefonsa ","Cuchuflito ","Cuchuflita ",
                           "Remilgo "};

    strcpy(n,nombres[randomRango(0,sizeof(nombres)/(sizeof(char)*20))]);

    char apellidos[][20] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};
    strcat(n,apellidos[randomRango(0,sizeof(apellidos)/(sizeof(char)*20))]);
}

int getEdad(){
    return randomRango(18,75);
}

int getDepartamento(){
    return randomRango(1,5);
}

/// Funcion que genera un registro al azar y lo retorna
stEmpleado cargoRegistroArchivoRandom(){
    stEmpleado r;
    r.legajo=getLegajo();
    getNombreApellido(r.nombreApellido);
    r.edad=getEdad();
    r.idDepartamento=getDepartamento();

    return r;
}

/// funcion que guarda un dato de tipo stRegistroMedico en el archivo especificado
void guardaRegistroArchivo(char archivo[], stEmpleado e){
    FILE * pArch = fopen(archivo,"ab");
    if(pArch){
        fwrite(&e,sizeof(stEmpleado),1,pArch);
        fclose(pArch);
    }
}

/// Funcion que llama a las funciones anteriores y genera y guarda en el archivo la cantidad de registros deseados
void generaArchivoRandom(int cantidad){
    stEmpleado r;
    int i=0;
    printf("Generando archivo  ");
    while(i<cantidad){
        //(i % 100 == 0) ? espera():0;
        if(i%100 == 0)
            espera();
        r = cargoRegistroArchivoRandom();
        int existe = buscaLegajo(r.legajo);
        while(existe){
            r.legajo = getLegajo();
            if(!buscaLegajo(r.legajo)){
                existe = 0;
            }
        }
        guardaRegistroArchivo(arRegistro,r);
        i++;
    }
}

void espera(){
    gotoxy(whereX()-1,whereY());
    char c[]={196,47,179,92};
    static int i=0;
    i=(i > 3)?0:i;
    printf("%c",c[i]);
    i++;
}

/// Funcion que cuenta la cantidad de registros en cualquier archivo, recibe el nombre de archivo y el sizeof del tipo de dato usado
int cuentaRegistros(char nombreArchivo[], int tamStruct){
    FILE* pArchi = fopen(nombreArchivo,"rb");
    int cantReg=0;
    if(pArchi){
        fseek(pArchi,0,SEEK_END);
        cantReg = ftell(pArchi)/tamStruct;
        fclose(pArchi);
    }
    return cantReg;
}

int buscaLegajo(int l){
    int existe = 0;
    stEmpleado e;
    FILE * pArch = fopen(arRegistro,"ab");
    if(pArch){
        while(fread(&e,sizeof(stEmpleado),1,pArch)>0 && existe==0){
            if(e.legajo == l){
                existe = 1;
            }
        }
        fclose(pArch);
    }
    return existe;
}
*/
