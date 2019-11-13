#include <iostream>
#include <cstdlib>
#include "Cadena.h"
using namespace std;

Cadena::Cadena() {
    cad = NULL;
    len = cap = 0;
}

Cadena::Cadena(const char *c) {
    // calculando longitud de cadena c
    len = 0;
    for (int i = 0; c[i]; i++, len++);

    if (len != 0) {
        cap = len + 1;

        // creando y copiando de c a cad
        cad = new char[len + 1];
        for (int i = 0; c[i]; i++) cad[i] = c[i];
        cad[len] = 0;
    }
    else {
        cad = NULL;
        cap = 0;
    }
}

Cadena::Cadena(int num) {
    cad = new char[num];
    len = 0;
    cap = num;
}

Cadena::Cadena(const Cadena &org) {
    len = org.len;
    cap = org.cap;

    // creando y copiando de org.cad a cad
    cad = new char[len + 1];
    for (int i = 0; org.cad[i]; i++) cad[i] = org.cad[i];
    cad[len] = 0;
}

Cadena::~Cadena() {
    if (cad != NULL) delete[] cad;
}

void Cadena::assign(const char *c) {
    // calculando capacidad de c
    int lenC = 0, capC;
    for (int i = 0; c[i]; i++, lenC++);
    capC = lenC + 1;

    len = lenC;
    if (capC <= cap) {
        for (int i = 0; c[i]; i++) cad[i] = c[i];
        cad[lenC] = 0;
    }
    else {
        delete[] cad;

        // se separa un espacio 30% mayor
        cap = (int)(lenC * 1.3);
        cad = new char[cap];
        for (int i = 0; c[i]; i++) cad[i] = c[i];
        cad[lenC] = 0;
    }
}

void Cadena::assign(const Cadena &c) {
    this -> assign(c.cad);
}

void Cadena::operator =(const char *c) {
    this -> assign(c);
}

void Cadena::operator =(const Cadena &c) {
    this -> assign(c);
}

void Cadena::append(const char *c) {
    // calculando capacidad de c
    int lenC = 0, capC, lenTemp = len;
    char buff[500];

    for (int i = 0; c[i]; i++, lenC++);
    capC = lenC + 1;

    len += lenC;
    if (len <= cap) {
        for (int i = lenTemp, j = 0; c[j]; i++, j++) {
            cad[i] = c[j];
        }
        cad[len] = 0;
    }
    else {
        // copiando a un bufer auxiliar
        for (int i = 0; cad[i]; i++) {
            buff[i] = cad[i];
        }
        for (int i = lenTemp, j = 0; c[j]; i++, j++) {
            buff[i] = c[j];
        }
        buff[len] = 0;
        
        // se separa un espacio 30% mayor
        delete[] cad;
        cap += (int)(lenC * 1.3);
        cad = new char[cap];
        for (int i = 0; buff[i]; i++) {
            cad[i] = buff[i];
        }
        cad[len] = 0;
    }
}

void Cadena::append(const Cadena &c) {
    char *cadC = c.cad;

    this -> append(cadC);
}

void Cadena::swap(Cadena &c) {
    char *cadTemp;
    int lenTemp, capTemp;

    lenTemp = c.len;
    c.len = len;
    len = lenTemp;

    capTemp = c.cap;
    c.cap = cap;
    cap = capTemp;

    cadTemp = c.cad;
    c.cad = cad;
    cad = cadTemp;
}

Cadena Cadena::operator +(const Cadena &c) {
    Cadena temp(*this);

    temp.append(c);

    return temp;
}

int Cadena::compare(const char *c) {
    int i;

    for (i = 0; cad[i] == c[i]; i++) {
        if (cad[i] == 0) return 0;
    }

    return cad[i] - c[i];
}

int Cadena::compare(const Cadena &c) {
    this -> compare(c.cad);
}

int Cadena::operator ==(const Cadena &c) {
    int res = this -> compare(c);

    if (res == 0) return 1;
    else return 0;
}

int Cadena::operator >(const Cadena &c) {
    int res = this -> compare(c);

    if (res > 0) return 1;
    else return 0;
}

int Cadena::operator <(const Cadena &c) {
    int res = this -> compare(c);

    if (res < 0) return 1;
    else return 0;
}

int Cadena::length() {
    return len;
}

void Cadena::print() {
    cout << cad << "\n";
}

