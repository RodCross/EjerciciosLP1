#include "Vehiculo.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <iterator>

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

void Vehiculo::asignarInfraccion(ifstream &arch) {
    int cod;
    
    arch >> cod;
    arch.get();
    
    infracciones.push_back(cod);
}

void Vehiculo::imprimirInfracciones(ofstream &arch) {
    for (list<int>::iterator it = infracciones.begin(); it != infracciones.end(); it++) {
        arch << setw(5) << *it;
    }
}
