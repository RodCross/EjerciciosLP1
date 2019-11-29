#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H
#include "Alumno.h"
#include <fstream>
using namespace std;

class Intercambio : public Alumno {
    private:
        char *pais;
        char *idioma;
        int semestres;
    public:
        Intercambio();
        virtual ~Intercambio();
        void SetSemestres(int semestres);
        int GetSemestres() const;
        void SetIdioma(const char* idioma);
        void GetIdioma(char*) const;
        void SetPais(const char* pais);
        void GetPais(char*) const;
        void leer(ifstream &);
        void imprimir(ofstream &);
        char GetTipo();
};

#endif /* INTERCAMBIO_H */
