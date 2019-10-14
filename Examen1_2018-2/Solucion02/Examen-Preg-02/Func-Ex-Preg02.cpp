#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Func-Ex-Preg01.h"
#include "Func-Ex-Preg02.h"

void ubicarPasajeros(char ***rutas, int *asientos,
                     char ****&pasajeros, char ***&sinAsignar) {
    ifstream archTransp("Transporte.csv", ios::in);
    if (!archTransp) {
        cout << "Error: no se pudo abrir el archivo Transporte.csv\n";
        exit(EXIT_FAILURE);
    }    

    char buffCad[50], *dni, *nombre, *destino;
    char **buffPasaj[200];
    int *tempAsientos, posRuta;
    int numDat, numPasaj;
    int *numReg, *tamReg; // para incrementos

    // ir a la segunda parte del archivo
    saltarPrimeraParte(archTransp);
    
    // asignar memoria a pasajeros y arreglos para incrementos
    for (numDat = 0; rutas[numDat]; numDat++);
    pasajeros = new char ***[numDat + 1];
    numReg = new int[numDat + 1];
    tamReg = new int[numDat + 1];
    for (int i = 0; i < numDat; i++) {
        pasajeros[i] = NULL;
        numReg[i] = tamReg[i] = 0;
    }
    pasajeros[numDat] = NULL;
    numReg[numDat] = tamReg[numDat] = -1;

    // llenar arreglo temporal de asientos
    copiarAsientos(tempAsientos, asientos, numDat);

    numPasaj = 0;
    while (1) {
        archTransp.getline(buffCad, 9, ',');
        if (archTransp.eof()) break;
        dni = new char[9];
        strcpy(dni, buffCad);

        archTransp.getline(buffCad, 50, ',');
        nombre = new char[strlen(buffCad) + 1];
        strcpy(nombre, buffCad);

        archTransp.getline(buffCad, 50);
        destino = new char[strlen(buffCad) + 1];
        strcpy(destino, buffCad);

        posRuta = buscarRuta(rutas, tempAsientos, destino);
        if (posRuta != -1) {
            asignarPasajero(pasajeros[posRuta], numReg[posRuta], tamReg[posRuta], dni, nombre, destino);
            tempAsientos[posRuta]--;
        }
        else {
            buffPasaj[numPasaj] = sinAsignarPasajero(dni, nombre, destino);
            numPasaj++;
        }
    }

    // eliminar arreglo temporal de asientos
    delete[] tempAsientos;

    // asignar memoria a pasajeros sin asiento
    sinAsignar = new char **[numPasaj + 1];
    for (int i = 0; i < numPasaj; i++) {
        sinAsignar[i] = buffPasaj[i];
    }
    sinAsignar[numPasaj] = NULL;
}

void saltarPrimeraParte(ifstream &arch) {
    while (1) {
        arch.ignore(100, '\n');
        if (arch.peek() == '\n') break;
    }
    arch.get();
}

void copiarAsientos(int *&temp, int *asientos, int num) {
    temp = new int[num + 1];
    for (int i = 0; i < num; i++) {
        temp[i] = asientos[i];
    }
    temp[num] = -1;
}

int buscarRuta(char ***rutas, int *asientos, char *destino) {
    bool posible = false;

    for (int i = 0; rutas[i]; i++) {
        if (asientos[i] > 0) {
            posible = buscarCoincidencia(rutas[i], destino);
            if (posible) return i;
        }
    }
    return -1;    
}

bool buscarCoincidencia(char **ruta, char *destino) {
    for (int i = 2; ruta[i]; i++) {
        if (strcmp(ruta[i], destino) == 0) {
            return true;
        }
    }
    return false;
}

void asignarPasajero(char ***&ruta, int &num, int &tam, char *dni, char *nombre, char *destino) {
    if (num == tam) {
        incrementarEspacios2(ruta, num, tam);
    }
    ruta[num] = NULL;
    ubicarPasajero(ruta[num - 1], dni, nombre, destino);
    num++;
}

void incrementarEspacios2(char ***&arr, int &num, int &tam) {
    char ***aux;

    tam += INCREMENTO;
    if (arr == NULL) {
        arr = new char **[tam];
        num++;
    }
    else {
        aux = new char **[tam];
        for (int i = 0; i < num; i++) {
            aux[i] = arr[i];
        }
        delete[] arr;
        arr = aux;
    }
}

void ubicarPasajero(char **&pasajero, char *dni, char *nombre, char *destino) {
    pasajero = new char *[3];
    pasajero[DNI] = dni;
    pasajero[NOMBRE] = nombre;
    pasajero[DESTINO] = destino;
}

char **sinAsignarPasajero(char *dni, char *nombre, char *destino) {
    char **pasajero;

    pasajero = new char *[3];
    ubicarPasajero(pasajero, dni, nombre, destino);

    return pasajero;
}

void reporteDeViajes(char ***rutas, int *asientos,
                     char ****pasajeros, char ***sinAsignar) {
    ofstream archRep("reporteDeViajes.txt", ios::out);
    if (!archRep) {
        cout << "Error: no se pudo abrir el archivo reporteDeViajes.txt\n";
        exit(EXIT_FAILURE);
    }

    archRep << setw(47) << "Lista de pasajeros\n";
    imprimirLinea(archRep, MAX_CAR, '=');

    for (int i = 0; rutas[i]; i++) {
        if (i != 0) {
            imprimirLinea(archRep, MAX_CAR, '-');
        }

        archRep << "Vehiculo No. " << i + 1 << "\n";
        imprimirDatosVehiculo(archRep, rutas[i]);
        archRep << "Pasajeros:\n";
        imprimirPasajeros(archRep, rutas[i], pasajeros[i]);
    }

    imprimirLinea(archRep, MAX_CAR, '=');
    archRep << "PASAJEROS SIN ASIGNAR\n";
    archRep << left << setw(7) << "No." << setw(12) << "DNI"
        << setw(50) << "Nombre" << "Destino\n";
    for (int i = 0; sinAsignar[i]; i++) {
        archRep << right << setw(3) << i + 1 << setw(4) << " ";
        imprimirSinAsignar(archRep, sinAsignar[i]);
    }
}

void imprimirLinea(ofstream &arch, int n, char c) {
    for (int i = 0; i < n; i++) {
        arch.put(c);
    }
    arch << "\n";
}

void imprimirDatosVehiculo(ofstream &arch, char **ruta) {
    arch << "Placa: " << ruta[0] << "\n";
    arch << "Chofer: " << ruta[1] << "\n";
    arch << "Ruta: " << ruta[2];
    for (int i = 3; ruta[i]; i++) {
        arch << " - " << ruta[i];
    }
    arch << "\n";
}

void imprimirPasajeros(ofstream &arch, char **rutas, char ***pasajeros) {
    int numPasaj = 1;

    for (int i = 2; rutas[i]; i++) {
        arch << rutas[i] << ":\n";
        arch << left << setw(7) << "No." << setw(25) << "DNI" << "Nombre\n";
        for (int j = 0; pasajeros[j]; j++) {
            imprimirDatosPasaj(arch, rutas[i], pasajeros[j], numPasaj);
        }
    }
}

void imprimirDatosPasaj(ofstream &arch, char *destino, char **pasajero, int &num) {
    if (strcmp(pasajero[DESTINO], destino) == 0) {
        arch << right << setw(2) << num << setw(5) << " ";
        arch << left << setw(25) << pasajero[DNI]
            << pasajero[NOMBRE] << "\n";
        num++;
    }
}

void imprimirSinAsignar(ofstream &arch, char **pasajero) {
    arch << left << setw(12) << pasajero[DNI] << setw(50)
        << pasajero[NOMBRE] << pasajero[DESTINO] << "\n";
}