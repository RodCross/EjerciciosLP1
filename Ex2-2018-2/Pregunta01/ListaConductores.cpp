#include "ListaConductores.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

ListaConductores::ListaConductores() {
    lista = NULL;
}

ListaConductores::~ListaConductores() {
    NodoC *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->der;
        delete sale;
    }
}

void ListaConductores::leerInsertar(ifstream &arch) {
    NodoC *p = lista, *ant = NULL, *nuevo;
    
    nuevo = new NodoC;
    nuevo->conductor.leer(arch);
    if (arch.eof()) {
        delete nuevo;
        return;
    }
    while (p) {
        if (p->conductor.GetDni() > nuevo->conductor.GetDni()) break;
        ant = p;
        p = p->der;
    }
    
    nuevo->der = p;
    nuevo->izq = ant;
    if (p) p->izq = nuevo;
    if (ant) ant->der = nuevo;
    else lista = nuevo;
}

void ListaConductores::imprimir(ofstream &arch) {
    NodoC *p = lista;
    
    while (p) {
        p->conductor.imprimir(arch);
        p = p->der;
    }
}
