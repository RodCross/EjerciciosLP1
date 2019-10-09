#include "FuncionesPreg01Ex01.h"
#include "FuncionesPreg02Ex01.h"

int main(){
    char ***cursos, ***cursosAprob;
    int *alumnos;
    leerCursos(cursos);
    imprimirCursos(cursos);
    leerNotas(alumnos, cursosAprob);
    imprimirAprobados(alumnos, cursosAprob);
    return 0;
}