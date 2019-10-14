#ifndef FUNC_EX_PREG04_H
#define FUNC_EX_PREG04_H

#include <fstream>
using namespace std;

void leerExtracciones(void*&extracciones, int &N);
void** leerExtraccion(ifstream &arch);
int *leerNumero(ifstream &arch);

void imprimirExtracciones(void *extracciones, int N);
void imprimirExtraccion(ofstream &arch, void *ext);
int obtenerProv(void *ext);
void imprimirEncabezado(ofstream &arch, void *ext);

#endif