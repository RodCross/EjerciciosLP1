/* 
 * File:   AlRegular.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:57 AM
 */

#include "AlRegular.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

AlRegular::AlRegular() {
    especialidad = facultad = NULL;
}

AlRegular::~AlRegular() {
    if (especialidad) delete[] especialidad;
    if (facultad) delete[] facultad;
}

void AlRegular::SetFacultad(const char* fac) {
    if (facultad) delete[] facultad;
    facultad = new char[strlen(fac) + 1];
    strcpy(facultad, fac);
}

void AlRegular::GetFacultad(char* fac) const {
    strcpy(fac, facultad);
}

void AlRegular::SetEspecialidad(const char* esp) {
    if (especialidad) delete[] especialidad;
    especialidad = new char[strlen(esp) + 1];
    strcpy(especialidad, esp);
}

void AlRegular::GetEspecialidad(char* esp) const {
    strcpy(esp, especialidad);
}

void AlRegular::leer(ifstream &arch) {
    int cod;
    char nom[100], esp[50], fac[50];
    
    arch >> cod;
    arch.get(); // sacar la coma
    arch.getline(nom, 100, ',');
    arch.getline(esp, 100, ',');
    arch.getline(fac, 100);
    
    SetCodigo(cod);
    SetNombre(nom);
    SetEspecialidad(esp);
    SetFacultad(fac);
}

void AlRegular::imprimir(ofstream &arch) {
    char nom[100], esp[50], fac[50];
    
    GetNombre(nom);
    GetEspecialidad(esp);
    GetFacultad(fac);
    
    arch << "Codigo alumno: " << GetCodigo() << endl
         << "Alumno Regular" << endl
         << "Nombre del alumno: " << nom << endl
         << "Especialidad: " << esp << endl
         << "Facultad: " << fac << endl;
}
