#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ListaDoble.h"
#include "Infraccion.h"
using namespace std;

int main() {
    ifstream archIn("Infracciones.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: no se pudo abrir el archivo Infracciones.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: no se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    
    ListaDoble<Infraccion> listaInfracciones;
    int cod = 150;
    
    listaInfracciones.crear(archIn);
    listaInfracciones.imprimir(archOut, 0);
    listaInfracciones.imprimir(archOut, 1);
    archOut << endl << "MULTA " << cod << " -> " << listaInfracciones.buscar(150);
    
    
    return 0;
}
