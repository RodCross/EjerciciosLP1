#ifndef MATRICULA_H
#define MATRICULA_H
#include "ListaAlumno.h"

class Matricula {
    private:
        ListaAlumno listaAlumnos;
    public:
        void leerAlumnos(const char *);
        void leerNotas(const char *);
        void imprimirAlumnos(const char *);
};

#endif /* MATRICULA_H */
