/* 
 * File:   AlIntercambio.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 09:04 AM
 */

#ifndef ALINTERCAMBIO_H
#define ALINTERCAMBIO_H
#include "BaseAlum.h"
#include <fstream>
using namespace std;

class AlIntercambio : public BaseAlum {
    private:
        char *pais;
        char **idiomas;
        int semestres;
    public:
        AlIntercambio();
        virtual ~AlIntercambio();
        void SetSemestres(int semestres);
        int GetSemestres() const;
        void SetIdiomas(char** idiomas);
        void GetIdiomas(char *) const;
        void SetPais(const char* pais);
        void GetPais(char*) const;
        void leer(ifstream &);
        void imprimir(ofstream &);
};

#endif /* ALINTERCAMBIO_H */
