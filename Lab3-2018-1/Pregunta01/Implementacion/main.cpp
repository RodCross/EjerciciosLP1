#include <iostream>
#include <iomanip>
#include "FuncEstadistica.h"
using namespace std;

int main() {
    int n = 42, nl = 6, nf;

    int datos[42] = {1, 6, 2, 3, 5, 4, 2, 5, 8, 2,
                     6, 0, 2, 5, 7, 4, 4, 2, 5, 4,
                     6, 2, 5, 4, 5, 6, 1, 2, 0, 2,
                     5, 4, 12, 5, 1, 2, 1, 2, 4, 5,
                     3, 5};

    int pesos[42] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
                     2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
                     3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
                     1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
                     2, 3};

    int limites[6] = {1, 2, 3, 4, 5, 6};

    int frecuencias[10];

    cout.precision(2);
    cout << fixed;

    cout << "Media: " << mediaAritmetica(datos, n) << endl;
    cout << "Media ponderada: " << mediaAritmeticaPonderada(datos, pesos, n) << endl;
    cout << "Mediana: " << mediana(datos, n) << endl;
    cout << "Desviacion estandar: " << desviacionEstandar(datos, n) << endl;

    distribucionDeFrecuencias(datos, n, limites, nl, frecuencias, nf);
    cout << "Distribucion de frecuencias:" << endl;
    for (int f = 0; f < nf - 1; f++) {
        if (f == 0) {
            cout << "<=";
        }
        else {
            cout << "  ";
        }
        cout << setw(2) << limites[f] << ": " << setw(4) << frecuencias[f] << endl;
    }
    cout << "> " << setw(2) << limites[nl - 1] << ": " <<
    setw(4) << frecuencias[nf - 1] << endl;

    return 0;
}