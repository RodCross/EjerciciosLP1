#ifndef FUNCIONESPREG02EX01_H
#define FUNCIONESPREG02EX01_H

#include <fstream>
using namespace std;

void leerNotas(int *& , char ***&);
bool nuevoAlumno(int *, int , int);
void buscarCurAprob(ifstream &, int , char**&);
void incrementarEsp(int *&, int &, int &);
void incrementarEspChar(char **&, int &, int &);

void imprimirAprobados(int *, char ***);
void imprimirCurAprob(ofstream& , char**);

#endif