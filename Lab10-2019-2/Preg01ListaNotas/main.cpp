/* 
 * File:   main.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:08 AM
 */

#include <iostream>
#include <cstdlib>
#include "ListaNotas.h"
using namespace std;

int main() {
    ifstream archIn("Cursos.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Cursos.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    
    ListaNotas ln;
    char buff[10];
    
    while (1) {
        archIn.getline(buff, 10, ',');
        if (archIn.eof()) break;
        ln.leerInsertar(archIn);
    }
    
    ln.imprimir(archOut);

    return 0;
}
