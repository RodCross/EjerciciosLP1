#ifndef LISTAALUMNO_H
#define LISTAALUMNO_H
#include "NodoAlumno.h"
#include <fstream>
using namespace std;

class ListaAlumno {
    private:
        NodoAlumno *lista;
        void insertar(ifstream &, char);
        NodoAlumno *buscar(int);
    public:
        ListaAlumno();
        virtual ~ListaAlumno();
        void leerInsertar(ifstream &);
        void leerCursosNotas(ifstream &);
        void imprimir(ofstream &);
};

#endif /* LISTAALUMNO_H */
