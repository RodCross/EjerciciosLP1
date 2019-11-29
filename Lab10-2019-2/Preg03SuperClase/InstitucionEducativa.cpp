#include "InstitucionEducativa.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

void InstitucionEducativa::leerAlumnos(const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    
    listaAlumnos.leerInsertar(arch);
}

void InstitucionEducativa::leerNotas(const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    
    listaAlumnos.leerNotas(arch);
}

void InstitucionEducativa::imprimirAlumnos(const char *nomArch) {
    ofstream arch(nomArch, ios::out);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    
    listaAlumnos.imprimir(arch);
}
