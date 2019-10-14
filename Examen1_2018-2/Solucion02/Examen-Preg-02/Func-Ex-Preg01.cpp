#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Func-Ex-Preg01.h"

void leerRutas(char ***&rutas, int *&asientos) {
    ifstream archTransp("Transporte.csv", ios::in);
    if (!archTransp) {
        cout << "Error: no se pudo abrir el archivo Transporte.csv\n";
        exit(EXIT_FAILURE);
    }

    char **buffRutas[50];
    int buffAsientos[50];
    int numDat = 0;

    while (1) {
        buffRutas[numDat] = leerRuta(archTransp);
        if (buffRutas[numDat] == NULL) break;
        buffAsientos[numDat] = leerAsiento(archTransp);
        numDat++;
    }

    rutas = new char **[numDat + 1];
    asientos = new int[numDat + 1];
    for (int i = 0; i < numDat; i++) {
        rutas[i] = buffRutas[i];
        asientos[i] = buffAsientos[i];
    }
    rutas[numDat] = NULL;
    asientos[numDat] = -1;

    archTransp.close();
}

char **leerRuta(ifstream &arch) {
    char **ruta = NULL;
    char buff[50], *cadena;
    int tam = 0, num = 0;

    while (1) {
        if (isdigit(arch.peek())) break;
        if (arch.eof()) return NULL;
        arch.getline(buff, 50, ',');
        cadena = new char[strlen(buff) + 1];
        strcpy(cadena, buff);
        if (num == tam) {
            incrementarEspacios(ruta, num, tam);
        }
        ruta[num] = NULL;
        ruta[num - 1] = cadena;
        num++;
    }
    return ruta;
}

void incrementarEspacios(char **&arr, int &num, int &tam) {
    char **aux;

    tam += INCREMENTO;
    if (arr == NULL) {
        arr = new char *[tam];
        num++;
    }
    else {
        aux = new char *[tam];
        for (int i = 0; i < num; i++) {
            aux[i] = arr[i];
        }
        delete[] arr;
        arr = aux;
    }
}

int leerAsiento(ifstream &arch) {
    int asiento;

    arch >> asiento;
    arch.get();

    return asiento;
}

void imprimirRutas(char ***rutas, int *asientos) {
    for (int i = 0; rutas[i]; i++) {
        imprimirRuta(rutas[i], asientos[i]);
    }
}

void imprimirRuta(char **ruta, int asiento) {
    cout << left << setw(10) << ruta[0] << setw(45) << ruta[1]
         << right << setw(4) << asiento << setw(4) << " ";
    for (int i = 2; ruta[i]; i++) {
        cout << left << setw(18) << ruta[i];
    }
    cout << "\n";
}