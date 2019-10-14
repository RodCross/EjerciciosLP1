#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include <cstring>
#include <cctype>

#include "Func_Ex_Preg01.h"
#define MAX_LINEA 87

enum Ruta {PLACA, CHOFER, CIUDADES};

void leerRutas(char*** &rutas, int *&asientos){
    ifstream arch("Transporte.csv", ios::in);
    if(!arch){
        cout<<"Error al abrir Transporte.csv"<<endl;
        exit(1);
    }

    char **buffRutas[50];
    int buffAsientos[50], numR = 0;

    while(1){
        buffRutas[numR] = leerRuta(arch);
        if(buffRutas[numR] == NULL) break;
        arch>>buffAsientos[numR];
        arch.get();
        numR++;
    }
    
    rutas = new char**[numR+1];
    asientos = new int[numR+1];
    for(int i=0; i<numR; i++){
        rutas[i] = buffRutas[i];
        asientos[i] = buffAsientos[i];
    }
    rutas[numR] = NULL;
    asientos[numR] = -1;
}

char** leerRuta(ifstream &arch){
    char *buffRuta[50], c, **ruta;
    int numDat=0;
    
    while(1){
        c = arch.peek();
        if(isdigit(c)) break;
        if(c == '\n') return NULL;
        buffRuta[numDat] = leerCadena(arch, ',');
        numDat++;
    }
    
    ruta = new char*[numDat+1];
    for(int i=0; i<numDat; i++)
        ruta[i] = buffRuta[i];
    ruta[numDat] = NULL;
    return ruta;
}

char *leerCadena(ifstream &arch, char a){
    char aux[100], *cadena;
    arch.getline(aux,100,a);
    cadena = new char[strlen(aux)+1];
    strcpy(cadena, aux);
    return cadena;
}

void imprimirRutas(char *** rutas, int *asientos){
    ofstream arch("ReporteRutas.txt", ios::out);
    if(!arch){
        cout<<"Error al abrir ReporteRutas.txt"<<endl;
        exit(1);
    }
    // Encabezado
    arch<<right<<setw(50)<<"REPORTE DE RUTAS"<<endl;
    impLinea(arch, MAX_LINEA, '-');
    arch<<left<<setw(10)<<"PLACA"
        <<setw(40)<<"NOMBRE CHOFER"
        <<setw(21)<<"NUM ASIENTOS"
        <<setw(24)<<"CIUDADES DESTINO"<<endl;
    impLinea(arch, MAX_LINEA, '=');
    for(int i=0; rutas[i]; i++){
        imprimirRuta(arch, rutas[i], asientos[i]);
        impLinea(arch, MAX_LINEA, '-');
    }
}

void imprimirRuta(ofstream &arch, char **ruta, int asientos){
    char* placa = ruta[PLACA];
    char* chofer = ruta[CHOFER];
    
    arch<<left<<setw(10)<<placa
        <<setw(45)<<chofer
        <<right<<setw(4)<<asientos;
    
    if(ruta[CIUDADES]==NULL){
        arch<<endl;
        return;
    }

    for(int i=CIUDADES; ruta[i]; i++){
        if(i!=CIUDADES) arch<<setw(59)<<"";
        arch<<setw(28)<<right<<ruta[i]<<endl;
    }
}

void impLinea(ofstream &arch, int num, char a){
    for(int i=0; i<num; i++){
        arch.put(a);
    }
    arch<<endl;
}