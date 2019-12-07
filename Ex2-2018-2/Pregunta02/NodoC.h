#ifndef NODOC_H
#define NODOC_H
#include <cstdlib>
#include "Conductor.h"
#include "ListaConductores.h"

class NodoC {
private:
    Conductor conductor;
    NodoC *izq;
    NodoC *der;
public:
    NodoC() {izq = der = NULL;}
    friend class ListaConductores;
};

#endif /* NODOC_H */
