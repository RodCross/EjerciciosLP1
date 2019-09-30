/* 
 * Archivo:  Bibl-EstructuraCadena.h
 * Autor:    Rodrigo Alonso Cruz Leán
 * Código:   20170516
 *
 * Creado el 27 de septiembre de 2019, 08:06 AM
 */

#ifndef BIBL_ESTRUCTURACADENA_H
#define BIBL_ESTRUCTURACADENA_H

#include <fstream>
using namespace std;

#define MAX_CAD 100

struct Cadena {
    char cadena[MAX_CAD];
    int longitud;
    bool overF;
};

void inicializa(struct Cadena &);
void inicializa(struct Cadena &, char, int = MAX_CAD);
void leer(ifstream &, struct Cadena &, char = '\n');
void imprimir(ofstream &, struct Cadena &);
int longitud(struct Cadena &);
void recortar(struct Cadena &);
void intercambiar(struct Cadena &, struct Cadena &);

void operator &(struct Cadena &, const struct Cadena &);
void operator +=(struct Cadena &, const struct Cadena &);
struct Cadena operator +(const struct Cadena &, const struct Cadena &);
bool operator ==(const struct Cadena &, const struct Cadena &);
bool operator >(const struct Cadena &, const struct Cadena &);
bool operator <(const struct Cadena &, const struct Cadena &);
istream & operator <<(istream &, struct Cadena &);
ostream & operator >>(ostream &, struct Cadena &);

#endif /* BIBL_ESTRUCTURACADENA_H */

