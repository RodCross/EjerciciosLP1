#include "Libreria.h"
using namespace std;

int main() {
    Libreria libreria;
    
    libreria.leerLibros("Libreria-LP1.csv");
    libreria.imprimirLibros("Reporte-Inicial.txt");
    libreria.venderLibros("Ventas-Libreria-LP1.csv");
    libreria.imprimirLibros("Reporte-Final.txt");
    
    return 0;
}
