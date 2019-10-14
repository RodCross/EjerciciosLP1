#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Func-Ex-Preg04.h"

void leerExtracciones(void *&extracciones, int &n) {
    ifstream arch("extracciones.txt", ios::in);
    if (!arch) {
        cout << "Error: no se pudo arir el archivo extracciones.txt\n";
        exit(EXIT_FAILURE);
    }

    void *buff[800], *reg, **extr;

    n = 0;
    while (1) {
        reg = leerReg(arch);
        if (reg == NULL) break;
        buff[n] = reg;
        n++;
    }
    extr = new void *[n];
    for (int i = 0; i < n; i++) {
        extr[i] = buff[i];
    }
    extracciones = extr;
}

void *leerReg(ifstream &arch) {
    int cod, *codigo, *anio;
    char buff[20], *nombre, *arbol;
    double *cantidades;
    void **registro;

    arch >> cod;
    if (arch.eof()) return NULL;
    codigo = new int;
    *codigo = cod;
    arch.get();

    arch.getline(buff, 20, ',');
    nombre = new char[strlen(buff) + 1];
    strcpy(nombre, buff);

    anio = new int;
    arch >> *anio;
    arch.get();

    arch.getline(buff, 20, ',');
    arbol = new char[strlen(buff) + 1];
    strcpy(arbol, buff);
    arch.get();
    arch.get();
    
    leerCantidades(arch, cantidades);

    registro = new void *[5];
    registro[CODIGO] = codigo;
    registro[NOMBRE] = nombre;
    registro[ANIO] = anio;
    registro[ARBOL] = arbol;
    registro[CANT] = cantidades;
    
    return registro;
}

void leerCantidades(ifstream &arch, double *&cantidades) {
    double r, c, l, p, o;

    arch >> r;
    arch.get();
    
    arch >> c;
    arch.get();
    
    arch >> l;
    arch.get();
    
    arch >> p;
    arch.get();
    
    arch >> o;

    cantidades = new double[5];
    cantidades[0] = r;
    cantidades[1] = c;
    cantidades[2] = l;
    cantidades[3] = p;
    cantidades[4] = o;
}

void imprimirExtracciones(void *extracciones, int n) {
    void **extr = (void **)extracciones, **registro;
    int *cod, codPrev, *anio, anioPrev;
    double *cant;
    char *nombre, *arbol;

    cout.precision(2);
    cout << fixed;
    codPrev = anioPrev = -1;
    cout << setw(17) << " ";
    cout <<"EXTRACCIONES FORESTALES POR ANIO Y PROVINCIA (TONELADAS)\n";
    for (int i = 0; i < n; i++) {
        registro = (void **)extr[i];
        cod = (int *)registro[CODIGO];
        nombre = (char *)registro[NOMBRE];
        anio = (int *)registro[ANIO];
        arbol = (char *)registro[ARBOL];
        cant = (double *)registro[CANT];

        if (*cod != codPrev || *cod == codPrev && *anio != anioPrev) {
            imprimirEncabezadoProv(cod, anio, nombre);
        }

        cout << left << "  " << setw(14) << arbol << right << setw(14)
            << cant[0] << setw(14) << cant[1] << setw(14) << cant[2]
            << setw(14) << cant[3] << setw(14) << cant[4] << "\n";

        codPrev = *cod;
        anioPrev = *anio;
    }
}

void imprimirEncabezadoProv(int *cod, int *anio, char *nombre) {
    imprimirLinea(MAX_CAR, '=');
    cout << "  ANIO: " << *anio << setw(56) << "PROVINCIA ";
    cout.fill('0');
    cout << setw(2) << *cod;
    cout.fill(' ');
    cout << ": " << nombre << "\n";
    imprimirLinea(MAX_CAR, '-');
    cout << left << setw(24) << "  ESPECIE" << setw(14) << "TIPO-R"
        << setw(14) << "TIPO-C" << setw(14) << "TIPO-L"
        << setw(14) << "TIPO-P" << "TIPO-O\n";
}


void imprimirLinea(int n, char c) {
    for (int i = 0; i < n; i++) {
        cout.put(c);
    }
    cout << "\n";
}