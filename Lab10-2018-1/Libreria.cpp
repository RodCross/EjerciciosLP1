#include <iostream>
#include <cstdlib>
#include "Libreria.h"

void Libreria::leerLibros(const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << "\n";
        exit(1);
    }
    
    arbolLibros.crearArbol(arch);
}

void Libreria::venderLibros(const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << "\n";
        exit(1);
    }
    
    arbolLibros.venderLibro(arch);
}


void Libreria::imprimirLibros(const char *nomArch) {
    ofstream arch(nomArch, ios::out);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArch << "\n";
        exit(1);
    }
    
    arbolLibros.imprimirLibros(arch);
}
