/* 
 * File:   AlIntercambio.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 09:04 AM
 */

#include "AlIntercambio.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

AlIntercambio::AlIntercambio() {
    idiomas = NULL;
    pais = NULL;
}

AlIntercambio::~AlIntercambio() {
    if (pais) delete[] pais;
    if (idiomas) delete[] idiomas;
}

void AlIntercambio::SetSemestres(int semestres) {
    this->semestres = semestres;
}

int AlIntercambio::GetSemestres() const {
    return semestres;
}

void AlIntercambio::SetPais(const char* ps) {
    if (pais) delete[] pais;
    pais = new char[strlen(ps) + 1];
    strcpy(pais, ps);
}

void AlIntercambio::GetPais(char* ps) const {
    strcpy(ps, pais);
}

void AlIntercambio::SetIdiomas(char** conjIdi) {
    if (idiomas) delete[] idiomas;
    idiomas = conjIdi;
}

void AlIntercambio::GetIdiomas(char* conjIdi) const {
    strcpy(conjIdi, idiomas[0]);
    for (int i = 1; idiomas[i]; i++) {
        strcat(conjIdi, " - ");
        strcat(conjIdi, idiomas[i]);
    }
    conjIdi[strlen(conjIdi) + 1] = 0;
}

void AlIntercambio::leer(ifstream& arch) {
    int cod, sem, numDat = 0;
    char nom[100], ps[50], idi[50];
    char **conjIdi, *buffIdi[10];
    
    arch >> cod;
    arch.get(); // sacar la coma
    arch.getline(nom, 100, ',');
    arch.getline(ps, 50, ',');
    while (1) {
        if(isdigit(arch.peek())) break;
        arch.getline(idi, 50, ',');
        buffIdi[numDat] = new char[strlen(idi) + 1];
        strcpy(buffIdi[numDat], idi);
        numDat++;
    }
    conjIdi = new char *[numDat + 1];
    for (int i = 0; i < numDat; i++) {
        conjIdi[i] = buffIdi[i];
    }
    conjIdi[numDat] = NULL;
    
    arch >> sem;
    arch.get(); // sacar la coma
    
    SetCodigo(cod);
    SetNombre(nom);
    SetPais(ps);
    SetIdiomas(conjIdi);
    SetSemestres(sem);
}

void AlIntercambio::imprimir(ofstream& arch) {
    char nom[100], ps[50], conjIdi[200];
    
    GetNombre(nom);
    GetPais(ps);
    GetIdiomas(conjIdi);
    
    arch << "Codigo alumno: " << GetCodigo() << endl
         << "Alumno de Intercambio" << endl
         << "Nombre del alumno: " << nom << endl
         << "Pais: " << ps << endl
         << "Idiomas: " << conjIdi << endl
         << "Permanecera " << GetSemestres() << " semestre";
    
    if (GetSemestres() != 1) arch << "s";
    arch << endl;
}
