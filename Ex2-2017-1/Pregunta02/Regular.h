#ifndef REGULAR_H
#define REGULAR_H
#include "Alumno.h"
#include <fstream>
using namespace std;

class Regular : public Alumno {
    private:
        char *especialidad;
        char *facultad;
    public:
        Regular();
        virtual ~Regular();
        void SetFacultad(const char* facultad);
        void GetFacultad(char*) const;
        void SetEspecialidad(const char* especialidad);
        void GetEspecialidad(char*) const;
        void leer(ifstream &);
        void imprimir(ofstream &);
        char GetTipo();

};

#endif /* REGULAR_H */
