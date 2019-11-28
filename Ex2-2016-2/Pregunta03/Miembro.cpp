/* 
 * File:   Miembro.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 05:52 PM
 */

#include <cstdlib>
#include <cstring>
#include "Miembro.h"

Miembro::Miembro() {
    nombre = distrito = NULL;
}

Miembro::~Miembro() {
    if (nombre) delete[] nombre;
    if (distrito) delete[] distrito;
}

void Miembro::SetDistrito(char* d) {
    if (distrito) delete[] distrito;
    distrito = new char[strlen(d) + 1];
    strcpy(distrito, d);
}

void Miembro::GetDistrito(char* d) const {
    strcpy(d, distrito);
}

void Miembro::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Miembro::GetCodigo() const {
    return codigo;
}

void Miembro::SetNombre(char* n) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(n) + 1];
    strcpy(nombre, n);
}

void Miembro::GetNombre(char *n) const {
    strcpy(n, nombre);
}
