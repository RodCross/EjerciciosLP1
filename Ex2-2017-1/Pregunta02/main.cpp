#include <iostream>
#include <cstdlib>
#include "ListaAlumno.h"
#include "Matricula.h"
using namespace std;

int main() {
    Matricula matricula;
    
    matricula.leerAlumnos("Alumnos.csv");
    matricula.leerNotas("Notas.csv");
    matricula.imprimirAlumnos("Reporte.txt");
    
    return 0;
}
