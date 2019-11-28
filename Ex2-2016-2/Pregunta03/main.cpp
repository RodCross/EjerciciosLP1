/* 
 * File:   main.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 07:50 PM
 */

#include <iostream>
#include <cstdlib>
#include "ListaMiembro.h"
using namespace std;

int main() {
    ifstream archIn("Miembros.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Miembros.csv" << endl;
        exit(1);
    }
    ifstream archLib("libros.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo libros.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    
    ListaMiembro c0;
    c0.leerInsertar(archIn);
    c0.leerLibros(archLib);
    c0.imprimir(archOut);
    
    return 0;
}

