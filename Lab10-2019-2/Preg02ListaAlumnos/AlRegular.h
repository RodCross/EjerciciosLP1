/* 
 * File:   AlRegular.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:57 AM
 */

#ifndef ALREGULAR_H
#define ALREGULAR_H
#include "BaseAlum.h"
#include <fstream>
using namespace std;

class AlRegular : public BaseAlum {
    private:
        char *especialidad;
        char *facultad;
    public:
        AlRegular();
        virtual ~AlRegular();
        void SetFacultad(const char* facultad);
        void GetFacultad(char*) const;
        void SetEspecialidad(const char* especialidad);
        void GetEspecialidad(char*) const;
        void leer(ifstream &);
        void imprimir(ofstream &);
};

#endif /* ALREGULAR_H */
