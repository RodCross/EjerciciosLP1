#include <iostream>
#include "FuncAux.h"

void imprimirLinea(ofstream& archSalida, int num, char car) {
    for(int i = 0; i < num; i++) {
        archSalida.put(car);
    }
}