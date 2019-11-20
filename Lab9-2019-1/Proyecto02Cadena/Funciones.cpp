#include <iostream>
#include "Funciones.h"

ifstream &operator >>(ifstream &in, Cadena &cad) {
    char buff[500];
    
    in >> buff;
    cad = buff;
    
    return in;
}

ofstream &operator <<(ofstream &out, const Cadena &cad) {
    char buff[500];
    
    cad.getCadena(buff);
    out << buff << "\n";
    
    return out;
}

void leer(Cadena *&nombres, int &numDat) {
    ifstream arch("personas.txt", ios::in);
    if (!arch) {
        cout << "Error: no se pudo abrir el archivo personas.txt\n";
        exit(1); 
    }

    numDat = 0;
    Cadena buff[100];
    char nomb[50];
    while (1) {
        arch >> buff[numDat]; // apellido paterno
        if (arch.eof()) break;

        // apellido materno y nombres
        for (int i = 0; i < 2; i++) {
            buff[numDat].append("/");
            arch >> nomb;
            buff[numDat].append(nomb);
        }
        
        numDat++;
    }

    nombres = new Cadena[numDat];
    for (int i = 0; i < numDat; i++) {
        nombres[i] = buff[i];
    }
}

void ordenar(Cadena *nombres, int izq, int der) {
    int limite;

    if (izq >= der) return;
    nombres[izq].swap(nombres[(izq + der) / 2]);

    limite = izq;
    for (int i = izq + 1; i <= der; i++) {
        if (nombres[i] < nombres[izq]) {
            nombres[++limite].swap(nombres[i]);
        }
    }

    nombres[izq].swap(nombres[limite]);
    ordenar(nombres, izq, limite - 1);
    ordenar(nombres, limite + 1, der);
}

void imprimir(Cadena *nombres, int numDat) {
    ofstream arch("reporte.txt", ios::out);
    if (!arch) {
        cout << "Error: no se pudo abrir el archivo reporte.txt\n";
        exit(1); 
    }
    
    for (int i = 0; i < numDat; i++) {
        arch << nombres[i];
    }
}