#ifndef LISTACONDUCTORES_H
#define LISTACONDUCTORES_H
#include "NodoC.h"
#include <fstream>
using namespace std;

class ListaConductores {
private:
    NodoC *lista;
public:
    ListaConductores();
    virtual ~ListaConductores();
    void leerInsertar(ifstream &);
    void imprimir(ofstream &);
};

#endif /* LISTACONDUCTORES_H */
