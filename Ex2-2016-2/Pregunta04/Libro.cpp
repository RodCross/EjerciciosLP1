/* 
 * File:   Libro.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 07:53 PM
 */

#include "Libro.h"
#include <iostream>
#include <iomanip>
#include <cstring>

Libro::Libro() {
}

Libro::~Libro() {
}

void Libro::SetPais(const char* p) {
    if (pais) delete[] pais;
    pais = new char[strlen(p) + 1];
    strcpy(pais, p);
}

void Libro::GetPais(char* p) const {
    strcpy(p, pais);
}

void Libro::SetAutor(const char* a) {
    if (autor) delete[] autor;
    autor = new char[strlen(a) + 1];
    strcpy(autor, a);
}

void Libro::GetAutor(char* a) const {
    strcpy(a, autor);
}

void Libro::SetTitulo(const char* t) {
    if (titulo) delete[] titulo;
    titulo = new char[strlen(t) + 1];
    strcpy(titulo, t);
}

void Libro::GetTitulo(char* t) const {
    strcpy(t, titulo);
}

void Libro::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Libro::GetCodigo() const {
    return codigo;
}

void Libro::leerDatos(ifstream &arch) {
    int cod;
    char titu[100], aut[100], ps[50];
    
    arch >> cod;
    arch.get(); // sacar la coma
    arch.getline(titu, 100, ',');
    arch.getline(aut, 100, ',');
    arch.getline(ps, 50);
    
    SetCodigo(cod);
    SetTitulo(titu);
    SetAutor(aut);
    SetPais(ps);
}

void Libro::imprimir(ofstream &arch) {
    char titu[100], aut[100], ps[50];
    
    GetTitulo(titu);
    GetAutor(aut);
    GetPais(ps);
    
    arch << left << setw(12) << GetCodigo()
         << setw(40) << titu
         << setw(35) << aut
         << setw(20) << ps << endl;
}
