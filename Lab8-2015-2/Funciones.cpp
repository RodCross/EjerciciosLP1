#include <iostream>
#include "Funciones.h"
using namespace std;

void leer(Cadena *&nombres, int &numDat) {
    ifstream arch("personas.txt", ios::in);
    if (!arch) {
        cout << "Error: no se pudo abrir el archivo personas.txt\n";
        exit(1); 
    }

    numDat = 0;
    Cadena buff[100];
    char apPat[50], apMat[50], nomb[50];
    while (1) {
        arch >> apPat;
        if (arch.eof()) break;
        buff[numDat] = apPat;

        buff[numDat].append("/");
        arch >> apMat;
        buff[numDat].append(apMat);

        buff[numDat].append("/");
        arch >> nomb;
        buff[numDat].append(nomb);

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
    for (int i = 0; i < numDat; i++) {
        nombres[i].print();
    }
}