#ifndef FUNC_EX_PREG04_H
#define FUNC_EX_PREG04_H

#define MAX_CAR 86
enum Reg {CODIGO, NOMBRE, ANIO, ARBOL, CANT};

#include <fstream>
using namespace std;

void leerExtracciones(void *&, int &);
void *leerReg(ifstream &);
void leerCantidades(ifstream &, double *&);
void imprimirExtracciones(void *, int);
void imprimirEncabezadoProv(int *, int *, char *);
void imprimirLinea(int, char);

#endif