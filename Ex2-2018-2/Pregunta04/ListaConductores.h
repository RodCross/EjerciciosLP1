#ifndef LISTACONDUCTORES_H
#define LISTACONDUCTORES_H
#include "NodoC.h"
#include <fstream>
using namespace std;

class ListaConductores {
private:
    NodoC *lista;
    NodoC *buscar(int);
public:
    ListaConductores();
    virtual ~ListaConductores();
    void leerInsertar(ifstream &);
    void imprimir(ofstream &);
    void leerInfraccion(ifstream &);
    void acumularMultas(int, char *, int &, int *);
};

#endif /* LISTACONDUCTORES_H */
