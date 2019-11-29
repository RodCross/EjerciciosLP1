/* 
 * File:   ListaAlumnos.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 09:08 AM
 */

#include "ListaAlumnos.h"
#include "AlRegular.h"
#include "AlIntercambio.h"
#include <iostream>

ListaAlumnos::ListaAlumnos() {
    lista = NULL;
}

ListaAlumnos::~ListaAlumnos() {
    NodoAlumno *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaAlumnos::leerInsertar(ifstream& arch) {
    char tipo;
    
    while (1) {
        tipo = arch.get();
        if (arch.eof()) break;
        arch.get(); // sacar la coma
        insertar(arch, tipo);
    }
}

void ListaAlumnos::insertar(ifstream& arch, char tipo) {
    NodoAlumno *p = lista, *ant = NULL, *nuevo;
    
    nuevo = new NodoAlumno;
    
    if (tipo == 'R') nuevo->alumno.SetBaseAlum(new AlRegular);
    else nuevo->alumno.SetBaseAlum(new AlIntercambio);
    
    nuevo->alumno.leerAlumno(arch);
    
    while (p) {
        if (p->alumno.GetCodigo() > nuevo->alumno.GetCodigo()) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

NodoAlumno *ListaAlumnos::buscar(int cod) {
    NodoAlumno *p = lista;
    
    while (p) {
        if (p->alumno.GetCodigo() == cod) break;
        p = p->sig;
    }
    
    return p;
}

void ListaAlumnos::leerNotas(ifstream& arch) {
    NodoAlumno *a;
    int cod;
    
    while (1) {
        arch >> cod;
        if (arch.eof()) break;
        arch.get(); // sacar la coma
        
        a = buscar(cod);
        if (a) a->alumno.leerNotas(arch);
        else arch.ignore(500, '\n');
    }
}

void ListaAlumnos::imprimir(ofstream& arch) {
    NodoAlumno *p = lista;
    
    arch << "             ALUMNOS DE LA INSTITUCION" << endl;
    
    while (p) {
        p->alumno.imprimir(arch);
        p = p->sig;
    }
}
