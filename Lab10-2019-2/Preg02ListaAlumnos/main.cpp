/* 
 * File:   main.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:53 AM
 */

#include <iostream>
#include <cstdlib>
#include "ListaAlumnos.h"
using namespace std;

int main() {
    ifstream archIn("Alumnos.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    ifstream archCur("Cursos.csv", ios::in);
    if (!archCur) {
        cout << "ERROR: no se pudo abrir el archivo Cursos.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    
    ListaAlumnos la;
    
    la.leerInsertar(archIn);
    la.leerNotas(archCur);
    la.imprimir(archOut);
    
    return 0;
}
