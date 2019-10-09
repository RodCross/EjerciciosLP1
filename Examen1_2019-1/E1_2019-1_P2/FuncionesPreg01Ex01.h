#ifndef FUNCIONESPREG01EX01_H
#define FUNCIONESPREG01EX01_H

#include <fstream>
using namespace std;

void leerCursos(char ***&);
char** leeCurso(ifstream &);
char *leeCodigo(ifstream &);
char *leeNombre(ifstream &);

void imprimirCursos(char ***);
void impLinea(ofstream &, char , int );
void imprimirCurso(ofstream &, int , char**, char***);
char* obtenerNombre(char *, char***);
bool compararCod(char **curso, char *codigo);


#endif