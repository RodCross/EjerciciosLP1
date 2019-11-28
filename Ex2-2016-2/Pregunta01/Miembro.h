/* 
 * File:   Miembro.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 05:52 PM
 */

#ifndef MIEMBRO_H
#define MIEMBRO_H
#include <fstream>
using namespace std;

class Miembro {
    private:
        char *nombre;
        int codigo;
        char *distrito;
    public:
        Miembro();
        virtual ~Miembro();
        void SetDistrito(char* distrito);
        void GetDistrito(char *) const;
        void SetCodigo(int codigo);
        int GetCodigo() const;
        void SetNombre(char* nombre);
        void GetNombre(char *) const;
        virtual void leer(ifstream &) = 0;
        virtual void imprimir(ofstream &) = 0;
};

#endif /* MIEMBRO_H */
