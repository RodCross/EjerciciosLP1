/* 
 * File:   ListaAlumnos.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 09:08 AM
 */

#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H
#include "NodoAlumno.h"
#include <cstdlib>
#include <fstream>
using namespace std;

class ListaAlumnos {
    private:
        NodoAlumno *lista;
        void insertar(ifstream &, char);
        NodoAlumno *buscar(int);
    public:
        ListaAlumnos();
        virtual ~ListaAlumnos();
        void leerInsertar(ifstream &);
        void leerNotas(ifstream &);
        void imprimir(ofstream &);
};

#endif /* LISTAALUMNOS_H */
