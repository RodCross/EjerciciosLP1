#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include <cstring>
#include <cctype>

#include "Func_Ex_Preg01.h"
#include "Func_Ex_Preg02.h"
#include "Func_Ex_Preg03.h"

enum Pas {DNI, NOMBRE, DESTINO};
enum Ruta {PLACA, CHOFER, CIUDADES};

void redefinirRutas(char ***&rutas, int *&asientos, char ****pasajeros){
    // Quitar ciudades sin pasajeros
    int nC;
    char **buffCiudades, *ciudad;
    buffCiudades = new char*[10];
    
    for(int i=0; rutas[i]; i++){
        // A que ciudades van los pasajeros
        nC = 0;
        for(int j=0; pasajeros[i][j]; j++){
            buffCiudades[j] = pasajeros[i][j][DESTINO];
            nC++;
        }
        buffCiudades[nC] = NULL;
        // Compararlas con las ciudades de la ruta
        for(int j=CIUDADES; rutas[i][j]; j++){
            ciudad = rutas[i][j];
            if(!Esta(ciudad, buffCiudades)) eliminarDato(rutas[i], j);
        }
    }
}

void eliminarDato(char **&ruta, int j){
    // Eliminar el dato ruta[j]
    int nC;
    delete[] ruta[j];
    for(int i=j; ruta[i]; i++){
        ruta[i] = ruta[i+1];
        nC++;
    }
}

bool Esta(char *ciudad, char **listaCiudades){
    for(int i=0; listaCiudades[i]; i++){
        if(strcmp(ciudad,listaCiudades[i])==0) return true;
    }
    return false;
}