#include "ListaAlumno.h"
#include "Regular.h"
#include "Intercambio.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

ListaAlumno::ListaAlumno() {
    lista = NULL;
}

ListaAlumno::~ListaAlumno() {
    NodoAlumno *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaAlumno::leerInsertar(ifstream &arch) {
    char tipo;
    
    while (1) {
        tipo = arch.get();
        if (arch.eof()) break;
        arch.get();
        insertar(arch, tipo);
    }
}

void ListaAlumno::insertar(ifstream &arch, char tipo) {
    NodoAlumno *p = lista, *ant = NULL, *nuevo;
    
    nuevo = new NodoAlumno;
    
    if (tipo == 'R') nuevo->alumno = new Regular;
    else nuevo->alumno = new Intercambio;
    
    nuevo->alumno->leer(arch);
    
    while (p) {
        if (p->alumno->GetCodigo() > nuevo->alumno->GetCodigo()) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

NodoAlumno* ListaAlumno::buscar(int cod) {
    NodoAlumno *p = lista;
    
    while (p) {
        if (p->alumno->GetCodigo() == cod) break;
        p = p->sig;
    }
    
    return p;
}

void ListaAlumno::leerCursosNotas(ifstream &arch) {
    NodoAlumno *a;
    int cod;
    
    while (1) {
        arch >> cod;
        if (arch.eof()) break;
        arch.get(); // sacar la coma
        
        a = buscar(cod);
        if (a) a->listaCN.leerInsertar(arch);
        else arch.ignore(500, '\n');
    }
}

void ListaAlumno::imprimir(ofstream &arch) {
    NodoAlumno *p = lista;
    
    arch << setw(40) << "ALUMNOS DE LA INSTITUCION" << endl;
    
    while (p) {
        p->alumno->imprimir(arch);
        p->listaCN.imprimir(arch);
        p = p->sig;
    }
}
