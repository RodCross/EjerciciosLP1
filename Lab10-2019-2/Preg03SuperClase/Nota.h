/* 
 * File:   Nota.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:09 AM
 */

#ifndef NOTA_H
#define NOTA_H
#include <fstream>
using namespace std;

class Nota {
    private:
        char *codCur;
        int nota;
        char *semestre;
    public:
        Nota();
        virtual ~Nota();
        void SetSemestre(const char* semestre);
        void GetSemestre(char*) const;
        void SetNota(int nota);
        int GetNota() const;
        void SetCodCur(const char* codCur);
        void GetCodCur(char*) const;
        void leerDatos(ifstream &);
        void imprimir(ofstream &);
};

#endif /* NOTA_H */
