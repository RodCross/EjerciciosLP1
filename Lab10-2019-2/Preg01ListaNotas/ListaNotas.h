/* 
 * File:   ListaNotas.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:15 AM
 */

#ifndef LISTANOTAS_H
#define LISTANOTAS_H
#include "NodoNota.h"
#include <fstream>
using namespace std;

class ListaNotas {
    private:
        class NodoNota *lista;
        void insertar(NodoNota *);
        void modificar(NodoNota *, int, char *);
        NodoNota *buscar(char *);
    public:
        ListaNotas();
        virtual ~ListaNotas();
        void leerInsertar(ifstream &);
        void imprimir(ofstream &);
};

#endif /* LISTANOTAS_H */
