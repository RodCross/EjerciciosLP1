/* 
 * Archivo:  main.cpp
 * Autor:    Rodrigo Alonso Cruz Leán
 * Código:   20170516
 *
 * Creado el 27 de septiembre de 2019, 08:04 AM
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Bibl-EstructuraCadena.h"
using namespace std;

int main() {
    ifstream archDatos("datos.txt", ios::in);
    if (!archDatos) {
        cout << "Error: no se pudo abrir el archivo datos.txt" << endl;
        exit(EXIT_FAILURE);
    }
    ofstream archRep("reporte.txt", ios::out);
    if (!archRep) {
        cout << "Error: no se pudo abrir el archivo reporte.txt" << endl;
        exit(EXIT_FAILURE);
    }
    
    struct Cadena s1, s2, s3, s4, s5;
    
    inicializa(s1);
    inicializa(s2, '*');
    inicializa(s3, '#', 5);
    inicializa(s4, '-', 200);
    
    archRep << "Cadena s1: ";
    imprimir(archRep, s1);
    archRep << endl;
    
    archRep << "Cadena s2: ";
    imprimir(archRep, s2);
    archRep << endl;
    
    archRep << "Longitud s2: " << s2.longitud << endl;
    
    archRep << "Cadena s3: ";
    imprimir(archRep, s3);
    archRep << endl;
    
    archRep << "Cadena s4: ";
    imprimir(archRep, s4);
    archRep << endl;
    
    s5 & (s1 + s1);
    s5 += s3;
    
    archRep << "Cadena s5: ";
    imprimir(archRep, s5);
    archRep << endl;
    
    leer(archDatos, s1, ',');
    leer(archDatos, s2, ',');
    recortar(s2);
    intercambiar(s1, s2);
    
    archRep << "Cadena s1: ";
    imprimir(archRep, s1);
    archRep << endl;
    
    archRep << "Cadena s2: ";
    imprimir(archRep, s2);
    archRep << endl;
    
    return 0;
}

