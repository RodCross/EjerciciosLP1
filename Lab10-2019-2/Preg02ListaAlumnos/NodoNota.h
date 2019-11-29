/* 
 * File:   NodoNota.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:14 AM
 */

#ifndef NODONOTA_H
#define NODONOTA_H
#include "Nota.h"
#include "ListaNotas.h"
#include <cstdlib>

class NodoNota {
    private:
        Nota nota;
        class NodoNota *sig;
    public:
        NodoNota() {sig = NULL;}
        friend class ListaNotas;
};

#endif /* NODONOTA_H */
