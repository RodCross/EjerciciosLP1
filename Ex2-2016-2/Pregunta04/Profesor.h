/* 
 * File:   Profesor.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 06:01 PM
 */

#ifndef PROFESOR_H
#define PROFESOR_H
#include "Miembro.h"
#include <fstream>
using namespace std;

class Profesor : public Miembro {
    private:
        char *categoria;
        char *dedicacion;
        char *seccion;
        char *grado;
    public:
        Profesor();
        virtual ~Profesor();
        void SetGrado(char* grado);
        void GetGrado(char*) const;
        void SetSeccion(char* seccion);
        void GetSeccion(char*) const;
        void SetDedicacion(char* dedicacion);
        void GetDedicacion(char*) const;
        void SetCategoria(char* categoria);
        void GetCategoria(char*) const;
        void leer(ifstream &);
        void imprimir(ofstream &);
};

#endif /* PROFESOR_H */

