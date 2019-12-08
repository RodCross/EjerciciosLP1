#ifndef ENTIDADREGULADORA_H
#define ENTIDADREGULADORA_H

#include "ListaConductores.h"
#include "ListaDoble.h"
#include "Infraccion.h"

class EntidadReguladora {
private:
    ListaConductores listaConductores;
    ListaDoble<Infraccion> listaInfracciones;
    void crearListaConductores(ifstream &);
    void crearListaInfracciones(ifstream &);
    void procesarConductores(ifstream &, ofstream &);
    void imprimirConductor(ofstream &, int, char *, int, double);
    double calcularMonto(int *);
public:
    void crear(const char *, const char *);
    void leerInfracciones(const char *);
    void emitirMultasAcumuladas(const char *, const char *);
};

#endif /* ENTIDADREGULADORA_H */
