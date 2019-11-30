#ifndef NODO_H
#define NODO_H
#include "Libro.h"
#include "ArbolLibros.h"

class Nodo {
    private:
        Libro libro;
        Nodo *izq;
        Nodo *der;
    public:
        Nodo() {izq = der = NULL;}
        friend class ArbolLibros;
};

#endif /* NODO_H */
