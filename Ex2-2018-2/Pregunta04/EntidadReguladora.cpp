#include "EntidadReguladora.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#define MAX_CAR 104

void EntidadReguladora::crear(const char *nomArchCon, const char *nomArchInf) {
    ifstream archCon(nomArchCon, ios::in);
    if (!archCon) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArchCon << endl;
        exit(1);
    }
    
    ifstream archInf(nomArchInf, ios::in);
    if (!archInf) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArchInf << endl;
        exit(1);
    }
    
    crearListaConductores(archCon);
    crearListaInfracciones(archInf);
}

void EntidadReguladora::crearListaConductores(ifstream &arch) {
    while (1) {
        listaConductores.leerInsertar(arch);
        if (arch.eof()) break;
    }
}

void EntidadReguladora::crearListaInfracciones(ifstream &arch) {
    listaInfracciones.crear(arch);
}

void EntidadReguladora::leerInfracciones(const char *nomArchFalt) {
    ifstream archFalt(nomArchFalt, ios::in);
    if (!archFalt) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArchFalt << endl;
        exit(1);
    }
    
    while (1) {
        listaConductores.leerInfraccion(archFalt);
        if (archFalt.eof()) break;
    }
}

void EntidadReguladora::emitirMultasAcumuladas(const char *nomArchDatos, const char *nomArchRep) {
    ifstream archDatos(nomArchDatos, ios::in);
    if (!archDatos) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArchDatos << endl;
        exit(1);
    }
    ofstream archRep(nomArchRep, ios::out);
    if (!archRep) {
        cout << "ERROR: no se pudo abrir el archivo " << nomArchRep << endl;
        exit(1);
    }
    
    procesarConductores(archDatos, archRep);
}

void EntidadReguladora::procesarConductores(ifstream &archIn, ofstream &archOut) {
    int dni, telefono, infracciones[20];
    char nombre[100];
    double monto;
    
    // encabezado
    archOut << right << setw(67) << "ENTIDAD REGULADORA DE TRANSITO" << endl;
    for (int i = 0; i < MAX_CAR; i++) archOut.put('=');
    archOut << endl;
    archOut << left << setw(12) << "DNI"
            << setw(45) << "NOMBRE"
            << setw(25) << "TELEFONO"
            << "MONTO TOTAL POR MULTAS" << endl;
    
    archOut.precision(2);
    archOut << fixed;

    while (1) {
        archIn >> dni;
        if (archIn.eof()) break;
        listaConductores.acumularMultas(dni, nombre, telefono, infracciones);
        monto = calcularMonto(infracciones);
        imprimirConductor(archOut, dni, nombre, telefono, monto);
    }
}

double EntidadReguladora::calcularMonto(int *inf) {
    double suma = 0;
    
    for (int i = 0; inf[i] != -1; i++) {
        suma += listaInfracciones.buscar(inf[i]);
    }
    
    return suma;
}

void EntidadReguladora::imprimirConductor(ofstream &archOut, int dni, char *nom, int tel, double monto) {
    archOut << left << setw(12) << dni
            << setw(45) << nom
            << setw(25) << tel
            << right << setw(14) << monto << endl;
}
