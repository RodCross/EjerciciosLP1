/* 
 * File:   Nota.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:09 AM
 */

#include "Nota.h"
#include <iostream>
#include <iomanip>
#include <cstring>

Nota::Nota() {
    codCur = semestre = NULL;
}

Nota::~Nota() {
    if (codCur) delete[] codCur;
    if (semestre) delete[] semestre;
}

void Nota::SetCodCur(const char* cc) {
    if (codCur) delete[] codCur;
    codCur = new char[strlen(cc) + 1];
    strcpy(codCur, cc);
}

void Nota::GetCodCur(char* cc) const {
    strcpy(cc, codCur);
}

void Nota::SetNota(int nota) {
    this->nota = nota;
}

int Nota::GetNota() const {
    return nota;
}

void Nota::SetSemestre(const char* s) {
    if (semestre) delete[] semestre;
    semestre = new char[strlen(s) + 1];
    strcpy(semestre, s);
}

void Nota::GetSemestre(char* s) const {
    strcpy(s, semestre);
}

void Nota::leerDatos(ifstream &arch) {
    char cod[10], sem[10];
    int n;
    
    arch.getline(cod, 10, ',');
    arch >> n;
    arch.get(); // sacar la coma
    arch.getline(sem, 10);
    
    SetCodCur(cod);
    SetNota(n);
    SetSemestre(sem);
}

void Nota::imprimir(ofstream &arch) {
    char cod[10], sem[10];
    
    GetCodCur(cod);
    GetSemestre(sem);
    
    arch << left << setw(12) << cod
         << right << setw(2) << GetNota()
         << setw(10) << sem << endl;
}
