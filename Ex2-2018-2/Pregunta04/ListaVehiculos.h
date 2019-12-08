#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H
#include "NodoV.h"
#include <fstream>
using namespace std;

class ListaVehiculos {
private:
    NodoV *lista;
    NodoV *buscar(char *);
public:
    ListaVehiculos();
    virtual ~ListaVehiculos();
    void insertar(char *);
    void leer(ifstream &);
    void imprimir(ofstream &);
    void leerInfraccion(ifstream &);
    void acumularMultas(int *);
};

#endif /* LISTAVEHICULOS_H */
