#include "Regular.h"
#include "Intercambio.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    ifstream archIn("Alumnos.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    
    Alumno *alumno;
    char tipo;
    
    while (1) {
        tipo = archIn.get();
        if(archIn.eof()) break;
        archIn.get(); // sacar la coma
        
        if (tipo == 'R') alumno = new Regular;
        else alumno = new Intercambio;
        
        alumno->leer(archIn);
        alumno->imprimir(archOut);
    }
    
    return 0;
}
