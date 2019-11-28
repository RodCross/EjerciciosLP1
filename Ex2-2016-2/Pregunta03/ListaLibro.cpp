/* 
 * File:   ListaLibro.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 07:58 PM
 */

#include <iostream>
#include <iomanip>
#include "ListaLibro.h"

ListaLibro::ListaLibro() {
    lista = NULL;
}

ListaLibro::~ListaLibro() {
    NodoLibro *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaLibro::leerInsertar(ifstream &arch) {
    NodoLibro *nuevo;
    
    nuevo = new NodoLibro;
    nuevo->libro.leerDatos(arch);
    insertar(nuevo);
}

void ListaLibro::insertar(NodoLibro *nuevo) {
    NodoLibro *p = lista, *ant = NULL;
    
    while (p) {
        if (p->libro.GetCodigo() > nuevo->libro.GetCodigo()) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

void ListaLibro::imprimir(ofstream &arch) {
    NodoLibro *p = lista;
    
    arch << "Libros solicitados:" << endl;
    arch << left << setw(12) << "Codigo"
         << setw(40) << "Titulo"
         << setw(35) << "Autor"
         << setw(20) << "Pais de origen" << endl;
    
    while (p) {
        p->libro.imprimir(arch);
        p = p->sig;
    }
    arch << endl;
}
