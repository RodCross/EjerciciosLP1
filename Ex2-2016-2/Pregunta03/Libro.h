/* 
 * File:   Libro.h
 * Author: M. Geldres
 * Codigo: 20196969
 * 
 * Created on 27 de noviembre de 2019, 07:53 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;

class Libro {
    private:
        int codigo;
        char *titulo;
        char *autor;
        char *pais;
    public:
        Libro();
        virtual ~Libro();
        void SetPais(const char* pais);
        void GetPais(char*) const;
        void SetAutor(const char* autor);
        void GetAutor(char*) const;
        void SetTitulo(const char* titulo);
        void GetTitulo(char*) const;
        void SetCodigo(int codigo);
        int GetCodigo() const;
        void leerDatos(ifstream &);
        void imprimir(ofstream &);
};

#endif /* LIBRO_H */

