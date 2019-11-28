/* 
 * File:   ListaMiembro.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 06:54 PM
 */

#include "ListaMiembro.h"
#include "Alumno.h"
#include "Profesor.h"
#define MAX_CAR 75

ListaMiembro::ListaMiembro() {
    lista = NULL;
}

ListaMiembro::~ListaMiembro() {
    NodoMiembro *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaMiembro::leerInsertar(ifstream &archIn) {
    char tipo;
    
    while (1) {
        tipo = archIn.get();
        if(archIn.eof()) break;
        archIn.get(); // sacar la coma
        insertar(archIn, tipo);
    }
}

void ListaMiembro::insertar(ifstream &archIn, char tipo) {
    NodoMiembro *p = lista, *ant = NULL, *nuevo;
    
    nuevo = new NodoMiembro;
    
    // leer datos
    if (tipo == 'A') {
        nuevo->miembro = new Alumno;
    }
    else {
        nuevo->miembro = new Profesor;
    }
    nuevo->miembro->leer(archIn);
    
    while (p) {
        if (p->miembro->GetCodigo() > nuevo->miembro->GetCodigo()) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

void ListaMiembro::imprimir(ofstream &archOut) {
    NodoMiembro *p = lista;
    
    archOut << "MIEMBROS DE LA BIBLIOTECA" << endl;
    for (int i = 0; i < MAX_CAR; i++) archOut.put('=');
    archOut << endl;
    
    while (p) {
        p->miembro->imprimir(archOut);
        p = p->sig;
    }
}
