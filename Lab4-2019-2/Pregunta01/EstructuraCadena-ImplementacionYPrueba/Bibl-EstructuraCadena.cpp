/* 
 * Archivo:  Bibl-EstructuraCadena.cpp
 * Autor:    alulab14
 *
 * Creado el 27 de septiembre de 2019, 08:06 AM
 */

#include <iostream>
#include <cctype>
#include "Bibl-EstructuraCadena.h"
using namespace std;

void inicializa(struct Cadena &cadena) {
    cadena.longitud = 0;
    cadena.overF = false;
}

void inicializa(struct Cadena &cadena, char car, int cant) {
    if (cant > MAX_CAD) {
        cadena.longitud = 0;
        cadena.overF = true;
        return;
    }
    for (int i = 0; i < cant; i++) {
        cadena.cadena[i] = car;
    }
    cadena.overF = false;
    cadena.longitud = cant;
}

void leer(ifstream &arch, struct Cadena &cadena, char car) {    
    char c;
    int i;
    
    i = 0;
    while (1) {
        c = arch.get();
        if (i == MAX_CAD) {
            cadena.longitud = MAX_CAD;
            cadena.overF = true;
            return;
        }
        if (arch.eof()) return;
        if (c == car) break;
        cadena.cadena[i] = c;
        i++;
    }
    cadena.longitud = i;
    cadena.overF = false;
}

void imprimir(ofstream &arch, struct Cadena &cadena) {
    if (!cadena.overF) {
        for (int i = 0; i < cadena.longitud; i++) {
            arch.put(cadena.cadena[i]);
        }
    }
    else {
        arch << "DESBORDE";
    }
}

int longitud(struct Cadena &cadena) {
    if (!cadena.overF) {
        return cadena.longitud;
    }
    else {
        return -1;
    }
}

void recortar(struct Cadena &cadena) {
    if (!cadena.overF) {
        int i, j;
        char buff[MAX_CAD];

        i = j = 0;
        while (isspace(cadena.cadena[i])) {
            i++;
        }

        while (i < cadena.longitud) {
            if (!isspace(cadena.cadena[i])) {
                buff[j] = cadena.cadena[i];
                j++;
            }
            else if (!isspace(buff[j - 1])) {
                buff[j] = ' ';
                j++;
            }
            i++;
        }

        // Manejar la cadena auxiliar para que no se tome
        // en cuenta el ' ' del final de la cadena (si existe)
        if (buff[j - 1] == ' ') j--;

        for (i = 0; i < j; i++) {
            cadena.cadena[i] = buff[i];
        }

        cadena.longitud = j;
    }
}

void intercambiar(struct Cadena &cad01, struct Cadena &cad02) {
    struct Cadena temp;
    int i;
    
    inicializa(temp);
    
    if (!cad01.overF && !cad02.overF) {
        for (i = 0; i < cad01.longitud; i++) {
            temp.cadena[i] = cad01.cadena[i];
        }
        for (i = 0; i < cad02.longitud; i++) {
            cad01.cadena[i] = cad02.cadena[i];
        }
        for (i = 0; i < cad01.longitud; i++) {
            cad02.cadena[i] = temp.cadena[i];
        }
        
        temp.longitud = cad01.longitud;
        cad01.longitud = cad02.longitud;
        cad02.longitud = temp.longitud;
        
        temp.overF = cad01.overF;
        cad01.overF = cad02.overF;
        cad02.overF = temp.overF;
    }
}

void operator &(struct Cadena &cad01, const struct Cadena &cad02) {
    if (!cad02.overF) {
        for (int i = 0; i < cad02.longitud; i++) {
            cad01.cadena[i] = cad02.cadena[i];
        }
        cad01.longitud = cad02.longitud;
        cad01.overF = cad02.overF;
    }
}

void operator +=(struct Cadena &cad01, const struct Cadena &cad02) {
    if (!cad01.overF && !cad02.overF) {
        if (cad01.longitud + cad02.longitud <= MAX_CAD) {
            int k = cad01.longitud;
            for (int i = 0; i < cad02.longitud; i++, k++) {
                cad01.cadena[k] = cad02.cadena[i];
            }
            cad01.longitud += cad02.longitud;
        }
        else {
            cad01.overF = true;
        }
    }
}

struct Cadena operator +(const struct Cadena &cad01, const struct Cadena &cad02) {
    struct Cadena result;
    int i;
    
    inicializa(result);
    
    if (!cad01.overF && !cad02.overF) {
        if (cad01.longitud + cad02.longitud <= MAX_CAD) {
            for (i = 0; i < cad01.longitud; i++) {
                result.cadena[i] = cad01.cadena[i];
            }
            for (; i < cad02.longitud; i++) {
                result.cadena[i] = cad02.cadena[i];
            }
            result.longitud = cad01.longitud + cad02.longitud;
        }
        else {
            result.overF = true;
        }
    }
    
    return result;
}

bool operator ==(const struct Cadena &cad01, const struct Cadena &cad02) {
    if (!cad01.overF && !cad02.overF) {
        if (cad01.longitud != cad02.longitud) return false;
        
        for (int i = 0; i < cad01.longitud; i++) {
            if (cad01.cadena[i] != cad02.cadena[i]) return false;
        }
        
        return true;
    }
    return false;
}

bool operator >(const struct Cadena &cad01, const struct Cadena &cad02) {    
    if (!cad01.overF && !cad02.overF) {
        int i;
        if (cad01.longitud < cad02.longitud) {
            for (i = 0; i < cad01.longitud; i++) {
                if (toupper(cad01.cadena[i]) > toupper(cad02.cadena[i])) return true;
                else if (toupper(cad01.cadena[i]) < toupper(cad02.cadena[i])) return false;
            }
            return false;
        }
        else {
            for (i = 0; i < cad02.longitud; i++) {
                if (toupper(cad01.cadena[i]) > toupper(cad02.cadena[i])) return true;
                else if (toupper(cad01.cadena[i]) < toupper(cad02.cadena[i])) return false;
            }
            return true;
        }
    }
    return false;
}

bool operator <(const struct Cadena &cad01, const struct Cadena &cad02) {
    if (!cad01.overF && !cad02.overF) {
        int i;
        if (cad01.longitud < cad02.longitud) {
            for (i = 0; i < cad01.longitud; i++) {
                if (toupper(cad01.cadena[i]) < toupper(cad02.cadena[i])) return true;
                else if (toupper(cad01.cadena[i]) > toupper(cad02.cadena[i])) return false;
            }
            return true;
        }
        else {
            for (i = 0; i < cad02.longitud; i++) {
                if (toupper(cad01.cadena[i]) < toupper(cad02.cadena[i])) return true;
                else if (toupper(cad01.cadena[i]) > toupper(cad02.cadena[i])) return false;
            }
            return false;
        }
    }
    return false;
}

istream & operator <<(istream &arch, struct Cadena &cadena) {
    char c;
    int i;
    
    i = 0;
    while (1) {
        c = arch.get();
        if (i == MAX_CAD) {
            cadena.longitud = MAX_CAD;
            cadena.overF = true;
            return arch;
        }
        if (arch.eof()) return arch;
        if (c == '\n') break;
        cadena.cadena[i] = c;
        i++;
    }
    cadena.longitud = i;
    cadena.overF = false;
    
    return arch;
}

ostream & operator >>(ostream &arch, struct Cadena &cadena) {
    if (!cadena.overF) {
        for (int i = 0; i < cadena.longitud; i++) {
            arch.put(cadena.cadena[i]);
        }
    }
    return arch;
}