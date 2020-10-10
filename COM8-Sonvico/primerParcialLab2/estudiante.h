#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define arEstudiantes "EstudiantesTUP.dat"

typedef struct {
    int legajo;
    char nombre[20];
    char apellido [20];
    char dni[10];
    int edad;
    char genero;
    int cantMateriasAprobadas;  /// indica el total de materias aprobadas del estudiante en la carrera (max 20)
    float promedioSinAplazos;    /// indica el promedio de estudiante, sin tener en cuenta aplazos
    float promedioConAplazos;   /// indica el promedio de estudiante, teniendo en cuenta aplazos
}estudiante;

void replicante(char c, int n);
void muestraUnEstudiante(estudiante p);
void muestraArchivoEstudiante();


#endif // PERSONA_H_INCLUDED
