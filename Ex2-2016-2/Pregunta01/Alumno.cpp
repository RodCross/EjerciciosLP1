/* 
 * File:   Alumno.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 05:56 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Alumno.h"

Alumno::Alumno() {
    especialidad = facultad = NULL;
}

Alumno::~Alumno() {
    if (especialidad) delete[] especialidad;
    if (facultad) delete[] facultad;
}

void Alumno::SetFacultad(char* fac) {
    if (facultad) delete[] facultad;
    facultad = new char[strlen(fac) + 1];
    strcpy(facultad, fac);
}

void Alumno::GetFacultad(char* fac) const {
    strcpy(fac, facultad);
}

void Alumno::SetEspecialidad(char* esp) {
    if (especialidad) delete[] especialidad;
    especialidad = new char[strlen(esp) + 1];
    strcpy(especialidad, esp);
}

void Alumno::GetEspecialidad(char* esp) const {
    strcpy(esp, especialidad);
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::leer(ifstream &arch) {
    char nom[100], dist[50], esp[50], fac[50];
    int cod, escala;
    
    arch.getline(nom, 100, ',');
    arch >> cod;
    arch.get();
    arch.getline(dist, 50, ',');
    arch >> escala;
    arch.get();
    arch.getline(esp, 50, ',');
    arch.getline(fac, 50);
    
    SetNombre(nom);
    SetCodigo(cod);
    SetDistrito(dist);
    SetEscala(escala);
    SetEspecialidad(esp);
    SetFacultad(fac);
}

void Alumno::imprimir(ofstream &arch) {
    char nom[100], dist[50], esp[50], fac[50];
    
    GetNombre(nom);
    GetDistrito(dist);
    GetEspecialidad(esp);
    GetFacultad(fac);
    
    arch << "Codigo alumno: " << GetCodigo() << endl
         << "Nombre del alumno: " << nom << endl
         << "Distrito: " << dist << endl
         << "Escala de pago: " << GetEscala() << endl
         << "Especialidad: " << esp<< endl
         << "Facultad: " << fac << endl << endl;
}
