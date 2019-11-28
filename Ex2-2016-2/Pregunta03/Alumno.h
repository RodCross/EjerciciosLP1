/* 
 * File:   Alumno.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 05:56 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include "Miembro.h"
#include <fstream>
using namespace std;

class Alumno : public Miembro {
    private:
        int escala;
        char *especialidad;
        char *facultad;
    public:
        Alumno();
        virtual ~Alumno();
        void SetFacultad(char* facultad);
        void GetFacultad(char*) const;
        void SetEspecialidad(char* especialidad);
        void GetEspecialidad(char*) const;
        void SetEscala(int escala);
        int GetEscala() const;
        void leer(ifstream &);
        void imprimir(ofstream &);
};

#endif /* ALUMNO_H */
