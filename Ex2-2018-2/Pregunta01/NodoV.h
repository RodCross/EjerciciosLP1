#ifndef NODOV_H
#define NODOV_H
#include "Vehiculo.h"
#include "ListaVehiculos.h"

class NodoV {
private:
    Vehiculo vehiculo;
    NodoV *izq;
    NodoV *der;
public:
    NodoV() {izq = der = NULL;}
    friend class ListaVehiculos;
};

#endif /* NODOV_H */
