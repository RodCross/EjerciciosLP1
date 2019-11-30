#ifndef ARBOLLIBROS_H
#define ARBOLLIBROS_H
#include "Nodo.h"
#include <fstream>
using namespace std;

class ArbolLibros {
    private:
        Nodo *arbol;
        Nodo *buscar(char *);
        void insertar(Nodo &, Nodo *&);
        void imprimirEnOrden(ofstream &, Nodo *);
        void eliminarArbol(Nodo *);
    public:
        ArbolLibros();
        virtual ~ArbolLibros();
        void crearArbol(ifstream &);
        void venderLibro(ifstream &);
        void imprimirLibros(ofstream &);
};

#endif /* ARBOLLIBROS_H */
