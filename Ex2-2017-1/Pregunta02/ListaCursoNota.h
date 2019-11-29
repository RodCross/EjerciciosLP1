#ifndef LISTACURSONOTA_H
#define LISTACURSONOTA_H
#include "NodoCursoNota.h"
#include <fstream>
using namespace std;

class ListaCursoNota {
    private:
        NodoCursoNota *lista;
        void insertar(NodoCursoNota *);
    public:
        ListaCursoNota();
        virtual ~ListaCursoNota();
        void leerInsertar(ifstream &);
        void imprimir(ofstream &);
};

#endif /* LISTACURSONOTA_H */
