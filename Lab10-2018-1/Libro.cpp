#include <iostream>
#include <iomanip>
#include <cstring>
#include "Libro.h"

Libro::Libro() {
    codigo = titulo = autor = NULL;
    nVend = 0;
    monto = 0;
}

Libro::~Libro() {
    if (codigo) delete[] codigo;
    if (titulo) delete[] titulo;
    if (autor) delete[] autor;
}

void Libro::SetMonto(double m) {
    monto = m;
}

double Libro::GetMonto() const {
    return monto;
}

void Libro::SetNVend(int nv) {
    nVend = nv;
}

int Libro::GetNVend() const {
    return nVend;
}

void Libro::SetPrecio(double p) {
    precio = p;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetAutor(char *a) {
    if (autor) delete[] autor;
    autor = new char[strlen(a) + 1];
    strcpy(autor, a);
}

void Libro::GetAutor(char *a) const {
    strcpy(a, autor);
}

void Libro::SetTitulo(char *t) {
    if (titulo) delete[] titulo;
    titulo = new char[strlen(t) + 1];
    strcpy(titulo, t);
}

void Libro::GetTitulo(char *t) const {
    strcpy(t, titulo);
}

void Libro::SetCodigo(char *c) {
    if (codigo) delete[] codigo;
    codigo = new char[strlen(c) + 1];
    strcpy(codigo, c);
}

void Libro::GetCodigo(char *c) const {
    strcpy(c, codigo);
}

void Libro::operator++(int) {
    nVend++;
    monto += precio;
}

void operator >>(ifstream &archIn, Libro &lib) {
    char buff[100];
    double precio;
    
    archIn.getline(buff, 7, ',');
    lib.SetCodigo(buff);
    archIn.getline(buff, 100, ',');
    lib.SetTitulo(buff);
    archIn.getline(buff, 50, ',');
    lib.SetAutor(buff);
    archIn >> precio;
    archIn.get(); // sacar el salto de linea
    lib.SetPrecio(precio);
}

ofstream &operator <<(ofstream &archOut, const Libro &lib) {
    char buff[100];
    
    archOut.precision(2);
    archOut << fixed;
    
    lib.GetCodigo(buff);
    archOut << left << setw(10) <<  buff;
    lib.GetTitulo(buff);
    archOut << setw(60) << buff;
    lib.GetAutor(buff);
    archOut << setw(25) << buff
            << right << setw(10) << lib.GetPrecio()
            << setw(6) << lib.GetNVend()
            << setw(10) << lib.GetMonto() << "\n";
    
    return archOut;
}