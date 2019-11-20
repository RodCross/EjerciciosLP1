#include <cstring>
#include "Cadena.h"

// Inicializacion

Cadena::Cadena() {
    cadena = NULL;
    longitud = 0;
    capacidad = 0;
}

Cadena::Cadena(const char *c) {
    longitud = strlen(c);
    capacidad = longitud + 1;
    cadena = new char[capacidad];
    strcpy(cadena, c);
    cadena[longitud] = 0;
}

Cadena::Cadena(int cap) {
    longitud = 0;
    capacidad = cap;
    cadena = new char[capacidad];
}

Cadena::Cadena(const Cadena &cad) {
    longitud = cad.longitud;
    capacidad = cad.capacidad;
    
    if (cad.cadena != NULL) {
        cadena = new char[capacidad];
        strcpy(cadena, cad.cadena);
        cadena[longitud] = 0;
    }
    else {
        cadena = NULL;
    }
}

// Asignacion

void Cadena::assign(const char *c) {
    int lenCad = strlen(c);
    int capCad = lenCad + 1;
    
    longitud = lenCad;
    if (capacidad < capCad) {
        if (cadena != NULL) delete [] cadena;
        
        // se separa un espacio 30% mayor
        capacidad = (int)(lenCad * 1.3);
        cadena = new char[capacidad];
    }
    
    strcpy(cadena, c);
    cadena[longitud] = 0;
}

void Cadena::assign(const Cadena &cad) {
    assign(cad.cadena);
}

void Cadena::operator =(const char *c) {
    assign(c);
}

void Cadena::operator =(const Cadena &cad) {
    assign(cad);
}

// Agregacion

void Cadena::append(const char *c) {
    int lenTemp = longitud;
    int lenCad = strlen(c);
    char buff[500];

    longitud += lenCad;
    if (longitud <= capacidad) {
        strcpy(cadena + lenTemp, c);
        cadena[longitud] = 0;
    }
    else {
        // copiando a un bufer auxiliar
        strcpy(buff, cadena);
        strcpy(buff + lenTemp, c);
        buff[longitud] = 0;
        assign(buff);
    }
}

void Cadena::operator +=(const Cadena &cad) {
    append(cad.cadena);
}

// Comparacion

int Cadena::compare(const char *c) {
    strcmp(cadena, c);
}

int Cadena::compare(const Cadena &cad) {
    compare(cad.cadena);
}

bool Cadena::operator ==(const Cadena &cad) {
    if (compare(cad.cadena) == 0) return true;
    else return false;
}

bool Cadena::operator >(const Cadena &cad) {
    if (compare(cad.cadena) > 0) return true;
    else return false;
}

bool Cadena::operator <(const Cadena &cad) {
    if (compare(cad.cadena) < 0) return true;
    else return false;
}

// Otros metodos

void Cadena::getCadena(char *c) const {
    if (longitud == 0) {
        c[0] = 0;
    }
    else {
        strcpy(c, cadena);
        c[strlen(c)] = 0;
    }
}

int Cadena::length() const {
    return longitud;
}

void Cadena::swap(Cadena &cad) {
    Cadena temp(*this);
    assign(cad);
    cad.assign(temp);
}

Cadena::~Cadena() {
    if (cadena != NULL) delete[] cadena;
}