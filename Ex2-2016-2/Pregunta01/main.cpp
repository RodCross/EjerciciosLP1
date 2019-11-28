/* 
 * File:   main.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 05:46 PM
 */

#include "Alumno.h"
#include "Profesor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    ifstream archIn("Miembros.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Miembros.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    
    Alumno alumno;
    Profesor profesor;
    char tipo;
    while (1) {
        tipo = archIn.get();
        if(archIn.eof()) break;
        archIn.get(); // sacar la coma
        if (tipo == 'A') {
            alumno.leer(archIn);
            alumno.imprimir(archOut);
        }
        else {
            profesor.leer(archIn);
            profesor.imprimir(archOut);
        }
    }
    
    return 0;
}
