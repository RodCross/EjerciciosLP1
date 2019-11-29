/* 
 * File:   Alumno.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 09:10 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include "BaseAlum.h"
#include "ListaNotas.h"
#include <fstream>
using namespace std;

class Alumno {
    private:
        BaseAlum *alum;
        ListaNotas listaNotas;
    public:
        int GetCodigo() const;
        void SetBaseAlum(BaseAlum *);
        void leerAlumno(ifstream &);
        void leerNotas(ifstream &);
        void imprimir(ofstream &);
};

#endif /* ALUMNO_H */
