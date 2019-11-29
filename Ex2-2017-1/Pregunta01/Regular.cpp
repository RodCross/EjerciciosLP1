#include <cstring>
#include <iostream>
#include "Regular.h"

Regular::Regular() {
    especialidad = facultad = NULL;
}

Regular::~Regular() {
    if (especialidad) delete[] especialidad;
    if (facultad) delete[] facultad;
}

void Regular::SetFacultad(const char *f) {
    if (facultad) delete[] facultad;
    facultad = new char[strlen(f) + 1];
    strcpy(facultad, f);
}

void Regular::GetFacultad(char *f) const {
    strcpy(f, facultad);
}

void Regular::SetEspecialidad(const char *e) {
    if (especialidad) delete[] especialidad;
    especialidad = new char[strlen(e) + 1];
    strcpy(especialidad, e);
}

void Regular::GetEspecialidad(char *e) const {
    strcpy(e, especialidad);
}

void Regular::leer(ifstream &arch) {
    char nom[50], esp[50], fac[50];
    int cod;
    
    arch >> cod;
    arch.get(); // sacar la coma
    arch.getline(nom, 50, ',');
    arch.getline(esp, 50, ',');
    arch.getline(fac, 50);
    
    SetCodigo(cod);
    SetNombre(nom);
    SetEspecialidad(esp);
    SetFacultad(fac);
}

void Regular::imprimir(ofstream &arch) {
    char nom[50], esp[50], fac[50];
    
    GetNombre(nom);
    GetEspecialidad(esp);
    GetFacultad(fac);
    
    arch << "Codigo alumno: " << GetCodigo() << endl
         << "Alumno: Regular" << endl
         << "Nombre del alumno: " << nom << endl
         << "Especialidad: " << esp << endl
         << "Facultad: " << fac << endl << endl;
}

char Regular::GetTipo() {
    return 'R';
}
