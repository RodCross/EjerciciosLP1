#include "Vehiculo.h"
#include <cstring>

Vehiculo::Vehiculo() {
    placa = NULL;
}

Vehiculo::~Vehiculo() {
    if (placa) delete[] placa;
}

void Vehiculo::SetPlaca(const char* p) {
    if (placa) delete[] placa;
    placa = new char[strlen(p) + 1];
    strcpy(placa, p);
}

void Vehiculo::GetPlaca(char* p) const {
    strcpy(p, placa);
}
