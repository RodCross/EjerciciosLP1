/* 
 * File:   Alumno.cpp
 * Author: Rodrigo Alonso Cruz Lean
 * Codigo: 20170516
 * 
 * Creado el 29 de noviembre de 2019, 09:10 AM
 */

#include "Alumno.h"

void Alumno::SetBaseAlum(BaseAlum* al) {
    alum = al;
}

void Alumno::leerAlumno(ifstream& arch) {
    alum->leer(arch);
}

void Alumno::leerNotas(ifstream& arch) {
    listaNotas.leerInsertar(arch);
}

void Alumno::imprimir(ofstream& arch) {
    alum->imprimir(arch); // POLIMORFISMO
    listaNotas.imprimir(arch);
}

int Alumno::GetCodigo() const {
    return alum->GetCodigo(); // POLIMORFISMO
}
