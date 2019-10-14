#ifndef FUNC_EX_PREG01_H
#define FUNC_EX_PREG01_H

#include <fstream>
using namespace std;

void leerRutas(char*** &, int *&);
char** leerRuta(ifstream &arch);
char *leerCadena(ifstream &arch, char a);

void imprimirRutas(char *** rutas, int *asientos);
void imprimirRuta(ofstream &arch, char **ruta, int asientos);
void impLinea(ofstream &arch, int num, char a);

#endif