#ifndef FUNC_EX_PREG02_H
#define FUNC_EX_PREG02_H

#define INCREMENTO 5
#define MAX_CAR 75
enum Pasajero {DNI, NOMBRE, DESTINO};

#include <fstream>
using namespace std;

void ubicarPasajeros(char ***, int *, char ****&, char ***&);
void saltarPrimeraParte(ifstream &);
void copiarAsientos(int *&, int *, int);
int buscarRuta(char ***, int *, char *);
bool buscarCoincidencia(char **, char *);
void asignarPasajero(char ***&, int &, int &, char *, char *, char *);
void incrementarEspacios2(char ***&, int &, int &);
void ubicarPasajero(char **&, char *, char *, char *);
char **sinAsignarPasajero(char *, char *, char *);
void reporteDeViajes(char ***, int *, char ****, char ***);
void imprimirLinea(ofstream &, int, char);
void imprimirDatosVehiculo(ofstream &, char **);
void imprimirPasajeros(ofstream &, char **, char ***);
void imprimirDatosPasaj(ofstream &, char *, char **, int &);
void imprimirSinAsignar(ofstream &, char **);

#endif