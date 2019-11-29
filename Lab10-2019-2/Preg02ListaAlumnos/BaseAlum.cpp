/* 
 * File:   BaseAlum.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:54 AM
 */

#include "BaseAlum.h"
#include <cstring>

BaseAlum::BaseAlum() {
    nombre = NULL;
}

BaseAlum::~BaseAlum() {
    if (nombre) delete[] nombre;
}

void BaseAlum::SetNombre(const char* n) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(n) + 1];
    strcpy(nombre, n);
}

void BaseAlum::GetNombre(char* n) const {
    strcpy(n, nombre);
}

void BaseAlum::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int BaseAlum::GetCodigo() const {
    return codigo;
}
