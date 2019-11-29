#include <cstring>
#include <iostream>
#include "Intercambio.h"

Intercambio::Intercambio() {
    idioma = pais = NULL;
}

Intercambio::~Intercambio() {
    if (idioma) delete[] idioma;
    if (pais) delete[] pais;
}

void Intercambio::SetIdioma(const char* idi) {
    if (idioma) delete[] idioma;
    idioma = new char[strlen(idi) + 1];
    strcpy(idioma, idi);
}

void Intercambio::GetIdioma(char *idi) const {
    strcpy(idi, idioma);
}

void Intercambio::SetPais(const char* ps) {
    if (pais) delete[] pais;
    pais = new char[strlen(ps) + 1];
    strcpy(pais, ps);
}

void Intercambio::GetPais(char *ps) const {
    strcpy(ps, pais);
}

void Intercambio::SetSemestres(int semestres) {
    this->semestres = semestres;
}

int Intercambio::GetSemestres() const {
    return semestres;
}

void Intercambio::leer(ifstream &arch) {
    char nom[50], ps[50], idi[50];
    int cod, sem;
    
    arch >> cod;
    arch.get(); // sacar la coma
    arch.getline(nom, 50, ',');
    arch.getline(ps, 50, ',');
    arch.getline(idi, 50, ',');
    arch >> sem;
    arch.get(); // sacar el salto de linea
    
    SetCodigo(cod);
    SetNombre(nom);
    SetPais(ps);
    SetIdioma(idi);
    SetSemestres(sem);
}

void Intercambio::imprimir(ofstream &arch) {
    char nom[50], ps[50], idi[50];
    
    GetNombre(nom);
    GetPais(ps);
    GetIdioma(idi);
    
    arch << "Codigo alumno: " << GetCodigo() << endl
         << "Alumno de Intercambio" << endl
         << "Nombre del alumno: " << nom << endl
         << "Pais: " << ps << endl
         << "Idioma: " << idi << endl
         << "Permanecera " << GetSemestres() << " semestre";
    
    if (GetSemestres() != 1) arch << "s";
    arch << endl;
}

char Intercambio::GetTipo() {
    return 'I';
}
