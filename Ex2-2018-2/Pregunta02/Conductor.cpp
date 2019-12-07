#include "Conductor.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>

Conductor::Conductor() {
    nombre = NULL;
}

Conductor::~Conductor() {
    if (nombre) delete[] nombre;
}

void Conductor::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Conductor::GetTelefono() const {
    return telefono;
}

void Conductor::SetNombre(const char* n) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(n) + 1];
    strcpy(nombre, n);
}

void Conductor::GetNombre(char* n) const {
    strcpy(n, nombre);
}

void Conductor::SetDni(int dni) {
    this->dni = dni;
}

int Conductor::GetDni() const {
    return dni;
}

void Conductor::leer(ifstream &arch) {
    int dni, tel;
    char nom[100];
    
    arch >> dni;
    if (arch.eof()) return;
    arch.get(); // sacar la comita
    arch.getline(nom, 100, ',');
    arch >> tel;
    arch.get(); // sacar la comita
    
    SetDni(dni);
    SetNombre(nom);
    SetTelefono(tel);
    
    vehiculos.leer(arch);
}

void Conductor::imprimir(ofstream &arch) {
    char nom[100];
    
    GetNombre(nom);
    
    arch << left << setw(12) << GetDni()
         << setw(50) << nom
         << setw(12) << GetTelefono();
    
    vehiculos.imprimir(arch);
    
    arch << endl;
}

void Conductor::leerInfraccion(ifstream &arch) {
    vehiculos.leerInfraccion(arch);
}
