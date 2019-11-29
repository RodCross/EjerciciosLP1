#ifndef NODOALUMNO_H
#define NODOALUMNO_H
#include "Alumno.h"
#include "ListaAlumno.h"
#include "ListaCursoNota.h"

class NodoAlumno {
    private:
        Alumno *alumno;
        ListaCursoNota listaCN;
        NodoAlumno *sig;
    public:
        NodoAlumno() {sig = NULL;}
        friend class ListaAlumno;
};

#endif /* NODOALUMNO_H */
