/* 
 * File:   NodoMiembro.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 06:53 PM
 */

#ifndef NODOMIEMBRO_H
#define NODOMIEMBRO_H
#include "Miembro.h"
#include "ListaMiembro.h"
#include "ListaLibro.h"
#include <cstdlib>

class NodoMiembro {
    private:
        Miembro *miembro;
        ListaLibro listaLibros;
        NodoMiembro *sig;
    public:
        NodoMiembro() {sig = NULL;}
        friend class ListaMiembro;
};

#endif /* NODOMIEMBRO_H */

