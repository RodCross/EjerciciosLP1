#include <cstring>
#include "Func-Ex-Preg01.h"
#include "Func-Ex-Preg02.h"
#include "Func-Ex-Preg03.h"

void redefinirRutas(char ***rutas, int *asientos, char ****pasajeros) {
    for (int i = 0; rutas[i]; i++) {
        revisarCiudades(rutas[i], pasajeros[i]);
    }
}

void revisarCiudades(char **ruta, char ***pasajero) {
    bool sinPasajeros, eliminar = false;
    char *buff[6];
    int numCiud = 0, i, j;

    for (int i = 2; ruta[i]; i++) {
        sinPasajeros = eliminarCiudad(ruta[i], pasajero);
        if (sinPasajeros) {
            delete[] ruta[i];
            eliminar = true;
        }
        else {
            buff[numCiud] = ruta[i];
            numCiud++;
        }
    }

    if (eliminar) {
        for (i = 2, j = 0; j < numCiud; i++, j++) {
            ruta[i] = buff[j];
        }
        ruta[i] = NULL;
    }
}

bool eliminarCiudad(char *destino, char ***pasajero) {
    for (int i = 0; pasajero[i]; i++) {
        if (strcmp(pasajero[i][DESTINO], destino) == 0) {
            return false;
        }
    }
    return true;
}