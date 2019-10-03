#ifndef FUNCDECADENAS_H
#define FUNCDECADENAS_H

#include <fstream>
using namespace std;

#define INCREMENTO 5

void leerDatos(char **&, char **&, char ***&);
char *leerRequisitos(ifstream &, char **&, char **&);
void ordenarDatos(char **, char **, char ***);
void imprimirDatos(char **, char **, char ***);
char *leerCodigo(ifstream &);
char *leerCurso(ifstream &);
char *leerUnicoReq(ifstream &);
char **leerReq(char **, char **, char *);
void incrementarEspacios(char **&, int &, int &);
void ordenarQS(char **, char **, char ***, int, int);
void cambiar(char **, char **, char ***, int, int);
void imprimirReq(ofstream &, char **);

#endif