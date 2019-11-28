/* 
 * File:   ListaMiembro.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 06:54 PM
 */

#ifndef LISTAMIEMBRO_H
#define LISTAMIEMBRO_H
#include "NodoMiembro.h"
#include <fstream>
using namespace std;

class ListaMiembro {
    private:
        NodoMiembro *lista;
        void insertar(ifstream &, char);
        NodoMiembro *buscar(int);
    public:
        ListaMiembro();
        virtual ~ListaMiembro();
        void leerInsertar(ifstream &);
        void leerLibros(ifstream &);
        void imprimir(ofstream &);
};

#endif /* LISTAMIEMBRO_H */

