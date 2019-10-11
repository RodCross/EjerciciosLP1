#ifndef FUNCIONESPREG04EX01_H
#define FUNCIONESPREG04EX01_H

#include <fstream>
using namespace std;

void leeCursosV(void*&);
void imprimirCursosV(void*);
void *leeCurso(ifstream &, ifstream &);
char *leeCadLine(ifstream&);
void imprimeCur(void *, ofstream&, void*);
char *buscarReq(void*, char*);
void *leeRequisitos(char* , ifstream& );
char *leeCodigo(ifstream &);

#endif