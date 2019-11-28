/* 
 * File:   NodoLibro.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 07:58 PM
 */

#ifndef NODOLIBRO_H
#define NODOLIBRO_H
#include "Libro.h"
#include "ListaLibro.h"
#include <cstdlib>

class NodoLibro {
    private:
        Libro libro;
        NodoLibro *sig;
    public:
        NodoLibro() {sig = NULL;}
        friend class ListaLibro;
};

#endif /* NODOLIBRO_H */

