#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ListaConductores.h"
using namespace std;

int main() {
    ifstream archIn("Conductores.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Conductores.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
            
    ListaConductores listaConductores;
    
    while (1) {
        listaConductores.leerInsertar(archIn);
        if (archIn.eof()) break;
    }
    listaConductores.imprimir(archOut);
    
    return 0;
}
