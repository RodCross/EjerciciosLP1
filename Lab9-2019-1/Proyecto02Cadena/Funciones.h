#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Cadena.h"
#include <fstream>
using namespace std;

ifstream &operator >>(ifstream &, Cadena &);
ofstream &operator <<(ofstream &, const Cadena &);
void leer(Cadena *&, int &);
void ordenar(Cadena *, int, int);
void imprimir(Cadena *, int);

#endif