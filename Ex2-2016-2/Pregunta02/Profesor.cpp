/* 
 * File:   Profesor.cpp
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 06:01 PM
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Profesor.h"

Profesor::Profesor() {
    categoria = dedicacion = grado = seccion = NULL;
}

Profesor::~Profesor() {
    if (categoria) delete[] categoria;
    if (dedicacion) delete[] dedicacion;
    if (grado) delete[] grado;
    if (seccion) delete[] seccion;
}

void Profesor::SetGrado(char* g) {
    if (grado) delete[] grado;
    grado = new char[strlen(g) + 1];
    strcpy(grado, g);
}

void Profesor::GetGrado(char* g) const {
    strcpy(g, grado);
}

void Profesor::SetSeccion(char* sec) {
    if (seccion) delete[] seccion;
    seccion = new char[strlen(sec) + 1];
    strcpy(seccion, sec);
}

void Profesor::GetSeccion(char* sec) const {
    strcpy(sec, seccion);
}

void Profesor::SetDedicacion(char* ded) {
    if (dedicacion) delete[] dedicacion;
    dedicacion = new char[strlen(ded) + 1];
    strcpy(dedicacion, ded);
}

void Profesor::GetDedicacion(char* ded) const {
    strcpy(ded, dedicacion);
}

void Profesor::SetCategoria(char* cat) {
    if (categoria) delete[] categoria;
    categoria = new char[strlen(cat) + 1];
    strcpy(categoria, cat);
}

void Profesor::GetCategoria(char* cat) const {
    strcpy(cat, categoria);
}

void Profesor::leer(ifstream &arch) {
    char nom[100], dist[50], cat[50], ded[50], sec[50], gr[50];
    int cod;
    
    arch.getline(nom, 100, ',');
    arch >> cod;
    arch.get();
    arch.getline(dist, 50, ',');
    arch.getline(cat, 50, ',');
    arch.getline(ded, 50, ',');
    arch.getline(sec, 50, ',');
    arch.getline(gr, 50);
    
    SetNombre(nom);
    SetCodigo(cod);
    SetDistrito(dist);
    SetCategoria(cat);
    SetDedicacion(ded);
    SetSeccion(sec);
    SetGrado(gr);
}

void Profesor::imprimir(ofstream &arch) {
    char nom[100], dist[50], cat[50], ded[50], sec[50], gr[50];
    
    GetNombre(nom);
    GetDistrito(dist);
    GetCategoria(cat);
    GetDedicacion(ded);
    GetSeccion(sec);
    GetGrado(gr);
    
    arch << "Codigo profesor: " << GetCodigo() << endl
         << "Nombre del profesor: " << nom << endl
         << "Distrito: " << dist << endl
         << "Categoria: " << cat << endl
         << "Dedicacion: " << ded << endl
         << "Seccion: " << sec << endl
         << "Grado academico: " << gr << endl << endl;
}
