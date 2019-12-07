#include <iostream>
#include <fstream>
#include "ListaMiembro.h"
using namespace std;

int main() {
    ifstream archIn("Miembros.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Miembros.csv" << endl;
        exit(1);
    }
    ifstream archLib("libros.csv", ios::in);
    if (!archLib) {
        cout << "ERROR: no se pudo abrir el archivo libros.csv" << endl;
        exit(1);
    }
    ifstream archRes("HistorialReservas.csv", ios::in);
    if (!archRes) {
        cout << "ERROR: no se pudo abrir el archivo HistorialReservas.csv" << endl;
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
    c0.leerReservas(archRes);
    c0.imprimir(archOut);

    return 0;
}