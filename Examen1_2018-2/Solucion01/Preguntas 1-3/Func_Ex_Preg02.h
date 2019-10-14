#ifndef FUNC_EX_PREG02_H
#define FUNC_EX_PREG02_H

#include <fstream>
using namespace std;

void ubicarPasajeros(char ***, int *, char ****&, char ***&);
char **leerPasajero(ifstream &);
void incrementarEspacio(char ***& , int &, int &);
int buscarRutaDisp(char *, char ***, int *, int *);
bool mismoDestino(char *, char **);
void agregarPasajero(char ***&, int , char** , int *&, int *&);

void reporteDeViajes(char ***, int *, char ****, char ***);
void imprimirSA(ofstream &, char** , int );
void imprimirDatosBus(ofstream &, char **, int );
void imprimirPasajeros(ofstream &, char ***);
void imprimirPasajero(ofstream &, char**, int );


#endif