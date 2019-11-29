#include "ListaCursoNota.h"
#include <iostream>
#include <iomanip>
#include <cstring>

ListaCursoNota::ListaCursoNota() {
    lista = NULL;
}

ListaCursoNota::~ListaCursoNota() {
    NodoCursoNota *p = lista, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaCursoNota::leerInsertar(ifstream &arch) {
    NodoCursoNota *nuevo;

    nuevo = new NodoCursoNota;
    nuevo->cn.leer(arch);
    insertar(nuevo);
}

void ListaCursoNota::insertar(NodoCursoNota *nuevo) {
    NodoCursoNota *p = lista, *ant = NULL;
    char buffP[10], buffN[10];
    
    while (p) {
        p->cn.GetCodigo(buffP);
        nuevo->cn.GetCodigo(buffN);
        if (strcmp(buffP, buffN) > 0) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

void ListaCursoNota::imprimir(ofstream &arch) {
    NodoCursoNota *p = lista;
    
    arch << "LISTADO DE NOTAS:" << endl;
    arch << left << setw(10) << "CODIGO" << "NOTA" << endl;
    
    while (p) {
        p->cn.imprimir(arch);
        p = p->sig;
    }
    arch << endl;
}
