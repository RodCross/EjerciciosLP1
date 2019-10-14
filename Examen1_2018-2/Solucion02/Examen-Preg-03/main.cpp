#include "Func-Ex-Preg01.h"
#include "Func-Ex-Preg02.h"
#include "Func-Ex-Preg03.h"

int main() {
    int *asientos;
    char ***rutas, ****pasajeros, ***sinAsignar;

    leerRutas(rutas, asientos);
    imprimirRutas(rutas, asientos);
    ubicarPasajeros(rutas, asientos, pasajeros, sinAsignar);
    reporteDeViajes(rutas, asientos, pasajeros, sinAsignar);
    redefinirRutas(rutas, asientos, pasajeros);
    imprimirRutas(rutas, asientos);

    return 0;
}