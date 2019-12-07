#include "ListaVehiculos.h"
#include "Conductor.h"
#include <iostream>
#include <iomanip>
#include <cstring>

ListaVehiculos::ListaVehiculos() {
    lista = NULL;
}

ListaVehiculos::~ListaVehiculos() {
    NodoV *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->der;
        delete sale;
    }
}

void ListaVehiculos::insertar(char *placaNueva) {
    NodoV *p = lista, *ant = NULL, *nuevo;
    char placaAnt[8];
    
    nuevo = new NodoV;
    nuevo->vehiculo.SetPlaca(placaNueva);
    
    while (p) {
        p->vehiculo.GetPlaca(placaAnt);
        if (strcmp(placaAnt, placaNueva) > 0) break;
        ant = p;
        p = p->der;
    }
    
    nuevo->der = p;
    nuevo->izq = ant;
    if (p) p->izq = nuevo;
    if (ant) ant->der = nuevo;
    else lista = nuevo;
}

void ListaVehiculos::leer(ifstream &arch) {
    char placa[8];
    
    while (1) {
        arch.get(placa, 8); // no saca la comita
        insertar(placa);
        if (arch.get() == '\n') break;
    }
}

void ListaVehiculos::imprimir(ofstream &arch) {
    NodoV *p = lista;
    char placa[8];
    
    while (p) {
        p->vehiculo.GetPlaca(placa);
        arch << setw(10) << placa;
        p = p->der;
    }
}
