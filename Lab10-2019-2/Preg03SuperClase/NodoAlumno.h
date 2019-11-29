/* 
 * File:   NodoAlumno.h
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 09:07 AM
 */

#ifndef NODOALUMNO_H
#define NODOALUMNO_H
#include "Alumno.h"
#include "ListaAlumnos.h"

class NodoAlumno {
    private:
        Alumno alumno;
        class NodoAlumno *sig;
    public:
        NodoAlumno() {sig = NULL;}
        friend class ListaAlumnos;
};

#endif /* NODOALUMNO_H */
