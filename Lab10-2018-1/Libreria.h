#ifndef LIBRERIA_H
#define LIBRERIA_H
#include "ArbolLibros.h"

class Libreria {
    private:
        ArbolLibros arbolLibros;
    public:
        void leerLibros(const char *);
        void venderLibros(const char *);
        void imprimirLibros(const char *);
};

#endif /* LIBRERIA_H */
