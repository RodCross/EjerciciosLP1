#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H
#include "NodoV.h"
#include <fstream>
using namespace std;

class ListaVehiculos {
private:
    NodoV *lista;
public:
    ListaVehiculos();
    virtual ~ListaVehiculos();
    void insertar(char *);
    void leer(ifstream &);
    void imprimir(ofstream &);
};

#endif /* LISTAVEHICULOS_H */
