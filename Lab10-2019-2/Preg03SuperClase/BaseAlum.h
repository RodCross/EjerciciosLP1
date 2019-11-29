/* 
 * File:   BaseAlum.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 08:54 AM
 */

#ifndef BASEALUM_H
#define BASEALUM_H
#include <fstream>
using namespace std;

class BaseAlum {
    private:
        int codigo;
        char *nombre;
    public:
        BaseAlum();
        virtual ~BaseAlum();
        void SetNombre(const char* nombre);
        void GetNombre(char*) const;
        void SetCodigo(int codigo);
        int GetCodigo() const;
        virtual void leer(ifstream &) = 0;
        virtual void imprimir(ofstream &) = 0;
};

#endif /* BASEALUM_H */
