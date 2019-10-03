#ifndef BIBLIOTECA_LAB05_H
#define BIBLIOTECA_LAB05_H

#include <fstream>
using namespace std;

void leerCursos(char ***&);
char **leerCur(ifstream &);
void imprimirCursos(char ***);
void imprimirCur(char **);
void leerMatricula(int *&, char ***&);
void imprimirMatricula(int *, char ***);
void armarListasDeClases(char ***&, char ***&, char ***&);
void imprimirListasDeClases(char ***, char ***);

#endif