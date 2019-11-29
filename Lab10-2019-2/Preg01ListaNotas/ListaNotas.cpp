/* 
 * File:   ListaNotas.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:15 AM
 */

#include "ListaNotas.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

ListaNotas::ListaNotas() {
    lista = NULL;
}

ListaNotas::~ListaNotas() {
    NodoNota *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaNotas::modificar(NodoNota* nodo, int nota, char *sem) {
    nodo->nota.SetNota(nota);
    nodo->nota.SetSemestre(sem);
}

void ListaNotas::leerInsertar(ifstream &arch) {
    NodoNota *nuevo, *temp;
    char cod[10];
    
    nuevo = new NodoNota;
    nuevo->nota.leerDatos(arch);
    
    nuevo->nota.GetCodCur(cod);
    temp = buscar(cod);
    if (temp) {
        char semAnt[10], semNuevo[10];
        char anioAnt[5], periodoAnt, anioNuevo[5], periodoNuevo;
        int aAnt, aNuevo;
        
        temp->nota.GetSemestre(semAnt);
        nuevo->nota.GetSemestre(semNuevo);
        
        for (int i = 0; semAnt[i] != '-'; i++) anioAnt[i] = semAnt[i];
        for (int i = 0; semNuevo[i] != '-'; i++) anioNuevo[i] = semNuevo[i];
        anioAnt[strlen(anioAnt)] = 0;
        anioNuevo[strlen(anioNuevo)] = 0;
        aAnt = atoi(anioAnt);
        aNuevo = atoi(anioNuevo);
        periodoAnt = semAnt[strlen(semAnt) - 1];
        periodoNuevo = semNuevo[strlen(semNuevo) - 1];
        
        if (aNuevo > aAnt || aNuevo == aAnt && periodoNuevo > periodoAnt) {
            modificar(temp, nuevo->nota.GetNota(), semNuevo);
        }
    }
    else {
        insertar(nuevo);
    }
}

void ListaNotas::insertar(NodoNota *nuevo) {
    NodoNota *p = lista, *ant = NULL;
    char codP[10], codNuevo[10];
    
    while (p) {
        p->nota.GetCodCur(codP);
        nuevo->nota.GetCodCur(codNuevo);
        
        if (strcmp(codP, codNuevo) > 0) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

void ListaNotas::imprimir(ofstream &arch) {
    NodoNota *p = lista;
    
    arch << "LISTADO DE NOTAS:" << endl;
    arch << left << setw(10) << "CODIGO"
         << "NOTA" << setw(4) << " " << "Semestre" << endl;
    
    while (p) {
        p->nota.imprimir(arch);
        p = p->sig;
    }
}

NodoNota* ListaNotas::buscar(char* cod) {
    NodoNota *p = lista;
    char codP[10];
    
    while (p) {
        p->nota.GetCodCur(codP);
        if (strcmp(codP, cod) == 0) break;
        p = p->sig;
    }
    
    return p;
}
