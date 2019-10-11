#ifndef FUNCIONESLABORATORIO05_H
#define FUNCIONESLABORATORIO05_H

#include <fstream>
using namespace std;

#define INCREMENTO 5
#define MAX_CAR_PROD 65
#define MAX_CAR_PAL 85

void leerPalets(char ***&);
void saltarLinea(ifstream &);
char **leerPal(ifstream &, int);
void incrementarEspacios(char **&, int &, int &);
void imprimirPalets(char ***);
void imprimirLinea(ofstream &, int, char);
void imprimirPal(ofstream &, char **);
void leerProductos(char **&, char **&);
char *leerCod(ifstream &);
char *leerNom(ifstream &);
void imprimirProductos(char **, char **);
void ordenaproductos(char **, char **);
void ordenarQS(char **, char **, int, int);
void cambiar(char **, char **, int, int);
void cuentaProductos(char ***, char **, char **);
int obtenerCantProd(char *, char **);
void reportarCantPalets(char **, char **, int *);

#endif /* FUNCIONESLABORATORIO05_H */