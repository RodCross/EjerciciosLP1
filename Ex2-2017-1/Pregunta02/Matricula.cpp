#include "Matricula.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void Matricula::leerAlumnos(const char* nomArch) {
    ifstream archIn(nomArch, ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    
    listaAlumnos.leerInsertar(archIn);
}

void Matricula::leerNotas(const char* nomArch) {
    ifstream archIn(nomArch, ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    
    listaAlumnos.leerCursosNotas(archIn);
}

void Matricula::imprimirAlumnos(const char* nomArch) {
    ofstream archOut(nomArch, ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    
    listaAlumnos.imprimir(archOut);    
}
