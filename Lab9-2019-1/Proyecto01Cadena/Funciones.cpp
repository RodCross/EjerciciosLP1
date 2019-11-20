#include "Funciones.h"

ifstream &operator >>(ifstream &in, Cadena &cad) {
    char buff[500];
    
    in >> buff;
    cad = buff;
    
    return in;
}

ofstream &operator <<(ofstream &out, const Cadena &cad) {
    char buff[500];
    
    cad.getCadena(buff);
    out << buff << "\n";
    
    return out;
}