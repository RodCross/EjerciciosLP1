#ifndef INSTITUCIONEDUCATIVA_H
#define INSTITUCIONEDUCATIVA_H
#include "ListaAlumnos.h"

class InstitucionEducativa {
    private:
        ListaAlumnos listaAlumnos;
    public:
        void leerAlumnos(const char *);
        void leerNotas(const char *);
        void imprimirAlumnos(const char *);
};

#endif /* INSTITUCIONEDUCATIVA_H */
