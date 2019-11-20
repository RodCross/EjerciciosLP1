#include "Cadena.h"
#include "Funciones.h"

int main() {
    Cadena *nombres;
    int numDat;

    leer(nombres, numDat);
    ordenar(nombres, 0, numDat - 1);
    imprimir(nombres, numDat);

    return 0;
}
