#ifndef FUNC_EX_PREG01_H
#define FUNC_EX_PREG01_H

#define INCREMENTO 5

#include <fstream>
using namespace std;

void leerRutas(char ***&, int *&);
char **leerRuta(ifstream &);
void incrementarEspacios(char **&, int &, int &);
int leerAsiento(ifstream &);
void imprimirRutas(char ***, int *);
void imprimirRuta(char **, int);

#endif