#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Funciones.h"
#include "Cadena.h"
using namespace std;

int main() {
    ifstream archIn("datos.txt", ios::in);
    if (!archIn) { 
        cout << "Error: no se pudo abrir el archivo datos.txt\n";
        exit(1);
    }
    ofstream archOut("reporte.txt", ios::out);
    if (!archOut) { 
        cout << "Error: no se pudo abrir el archivo reporte.txt\n";
        exit(1);
    }
    
    Cadena cad01;
    Cadena cad02("Ana Roncal");
    Cadena cad03(10);
    Cadena cad04 = cad01;
    
    archIn >> cad01 >> cad02 >> cad03 >> cad04;
    archOut << cad01 << cad02 << cad03 << cad04;
    
    return 0;
}