#include "Alumno.h"
#include <cstring>

Alumno::Alumno() {
    nombre = NULL;
}

Alumno::~Alumno() {
    if (nombre) delete[] nombre;
}

void Alumno::SetNombre(const char *n) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(n) + 1];
    strcpy(nombre, n);
}

void Alumno::GetNombre(char *n) const {
    strcpy(n, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}
