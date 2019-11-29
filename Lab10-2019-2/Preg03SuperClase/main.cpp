#include "InstitucionEducativa.h"

int main() {
    InstitucionEducativa ie;
    
    ie.leerAlumnos("Alumnos.csv");
    ie.leerNotas("Cursos.csv");
    ie.imprimirAlumnos("Reporte.txt");
    
    return 0;
}
