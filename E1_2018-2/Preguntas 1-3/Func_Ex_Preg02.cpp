#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include <cstring>
#include <cctype>

#include "Func_Ex_Preg01.h"
#include "Func_Ex_Preg02.h"

#define INCREMENTO 5
#define MAX_LINEA 100

enum Pas {DNI, NOMBRE, DESTINO};
enum Ruta {PLACA, CHOFER, CIUDADES};

void ubicarPasajeros(char ***rutas, int *asientos, char ****&pasajeros, char ***&sinAsignar){
    ifstream arch("Transporte_P2.csv",ios::in);
    if(!arch){
        cout<<"Error al abrir Transporte_P2.csv"<<endl;
        exit(1);
    }

    char c, *nombre, *destino, ****buses, ***sinAsig=NULL;
    char **nuevoPas;
    int *dni, numRutas=0, numRuta, numSA=0, tamSA=0;
    int *asientosOcupados, *tamBus;

    for(int i=0; rutas[i]; i++) numRutas++;

    buses = new char***[numRutas+1];
    for(int i=0; i<=numRutas; i++) buses[i] = NULL;

    tamBus = new int[numRutas];
    asientosOcupados = new int [numRutas];
    for(int i=0; i<numRutas; i++) {
        asientosOcupados[i] = 0;
        tamBus[i] = 0;
    }

    while(1){
        c = arch.peek();
        if(arch.eof()) break;
        
        // Lee datos de un pasajero
        nuevoPas = leerPasajero(arch);

        // Ubicar pasajero en un bus
        numRuta = buscarRutaDisp(nuevoPas[DESTINO], rutas, asientos, asientosOcupados);
        if(numRuta == -1){
            // No se pudo asignar
            if(numSA == tamSA) incrementarEspacio(sinAsig, numSA, tamSA);
            sinAsig[numSA] = NULL;
            sinAsig[numSA-1] = nuevoPas;
            numSA++;
        }
        else{
            // Se pudo encontrar bus disponible
            agregarPasajero(buses[numRuta], numRuta, nuevoPas, asientosOcupados, tamBus);
        }
    }
    delete [] asientosOcupados;
    delete [] tamBus;
    pasajeros = buses;
    sinAsignar = sinAsig;
}

char **leerPasajero(ifstream &arch){
    char* nom, **pasajero;
    pasajero = new char*[3];
    pasajero[DNI] = leerCadena(arch, ',');
    pasajero[NOMBRE] = leerCadena(arch, ',');
    pasajero[DESTINO] = leerCadena(arch, '\n');
    return pasajero; 
}

void incrementarEspacio(char ***& arreglo, int &num, int &tam){
    char ***aux;
    tam += INCREMENTO;
    if(arreglo == NULL){
        arreglo = new char**[tam];
        arreglo[0] = NULL;
        num = 1;
    }
    else{
        aux = new char** [tam];
        for(int i=0; i<num; i++)
            aux[i]  = arreglo[i];
        delete [] arreglo;
        arreglo = aux;
    }
}

int buscarRutaDisp(char *destino, char ***rutas, int *asientos, int *asientosOcupados){
    for(int i=0; rutas[i]; i++){
        if(mismoDestino(destino, rutas[i])){
            if(asientos[i]>=asientosOcupados[i]) return i;
        }
    }
    return -1;
}

bool mismoDestino(char *destino, char **ruta){
    for(int i=CIUDADES; ruta[i]; i++){
        if(strcmp(ruta[i], destino)==0) return true;
    }
    return false;
}

void agregarPasajero(char ***&bus, int numRuta, char** nuevoPas, int *&asientosOcupados, int *&tamBus){
    if(asientosOcupados[numRuta] == tamBus[numRuta]){
        incrementarEspacio(bus, asientosOcupados[numRuta], tamBus[numRuta]);
    }
    bus[asientosOcupados[numRuta]] = NULL;
    bus[asientosOcupados[numRuta]-1] = nuevoPas;
    asientosOcupados[numRuta]++;
}

void reporteDeViajes(char ***rutas, int *asientos, char ****pasajeros, char ***sinAsignar){
    ofstream arch("ReporteDeViajes.txt", ios::out);
    if(!arch){
        cout<<"Error al abrir ReporteDeViajes.txt"<<endl;
        exit(1);
    }

    arch<<setw(60)<<"Lista de pasajeros"<<endl;
    impLinea(arch, MAX_LINEA, '=');

    for(int i=0; rutas[i]; i++){
        imprimirDatosBus(arch, rutas[i], i+1);
        imprimirPasajeros(arch, pasajeros[i]);
        impLinea(arch, MAX_LINEA, '-');
    }
    if(sinAsignar[0]==NULL) return;

    impLinea(arch, MAX_LINEA, '=');
    arch<<"PASAJEROS SIN ASIGNAR:"<<endl;
    arch<<"No.     DNI         Nombre                                          Destino"<<endl;
    for(int i=0; sinAsignar[i]; i++){
        imprimirSA(arch, sinAsignar[i], i+1);
    }
}

void imprimirSA(ofstream &arch, char** pasajero, int num){
    char *dni = pasajero[DNI];
    char *nombre = pasajero[NOMBRE];
    char *destino = pasajero[DESTINO];

    arch<<right<<setw(2)<<num<<"   "
        <<left<<setw(13)<<dni<<"  "
        <<setw(40)<<nombre
        <<setw(20)<<destino<<endl;
}

void imprimirDatosBus(ofstream &arch, char **ruta, int num){
    arch<<"Vehiculo No. "<<num<<endl
        <<"Placa:  "<<ruta[PLACA]<<endl
        <<"Chofer: "<<ruta[CHOFER]<<endl
        <<"Ruta: ";
    for(int i=CIUDADES; ruta[i]; i++){
        arch<<ruta[i];
        if(ruta[i+1]) arch<<" - ";
    }
    arch<<endl;
}

void imprimirPasajeros(ofstream &arch, char ***pasajeros){
    
    arch<<"Pasajeros:"<<endl;
    arch<<"No.      DNI              Nombre"<<endl;

    for(int i=0; pasajeros[i]; i++){
        imprimirPasajero(arch, pasajeros[i], i+1);
    }
}

void imprimirPasajero(ofstream &arch, char**pasajero, int num){
    char *dni = pasajero[DNI];
    char *nombre = pasajero[NOMBRE];
    char *destino = pasajero[DESTINO];

    arch<<right<<setw(2)<<num<<"    "
        <<left<<setw(20)<<dni
        <<setw(40)<<nombre
        <<setw(20)<<destino<<endl;
}