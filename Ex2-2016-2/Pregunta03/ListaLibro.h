/* 
 * File:   ListaLibro.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 07:58 PM
 */

#ifndef LISTALIBRO_H
#define LISTALIBRO_H
#include "NodoLibro.h"
#include <fstream>
using namespace std;

class ListaLibro {
    private:
        NodoLibro *lista;
        void insertar(NodoLibro *);
    public:
        ListaLibro();
        virtual ~ListaLibro();
        void leerInsertar(ifstream &);
        void imprimir(ofstream &);
};

#endif /* LISTALIBRO_H */

