#ifndef NODODOBLE_H
#define NODODOBLE_H
#include "ListaDoble.h"
#include <cstdlib>

template <typename T> class ListaDoble;

template <typename T>
class NodoDoble {
private:
    T dato;
    NodoDoble *izq;
    NodoDoble *der;
public:
    NodoDoble() {izq = der = NULL;}
    friend class ListaDoble<T>;
};

#endif /* NODODOBLE_H */
