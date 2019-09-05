#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "FuncAux.h"
using namespace std;
#define MAX_CAR_LIN 36

int main() {
    ifstream archDatos("matricula.txt", ios::in);
    if(!archDatos) {
        cout << "Error: no se pudo abrir el archivo matricula.txt" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream archRep("reporte.txt", ios::out);
    if(!archRep) {
        cout << "Error: no se pudo abrir el archivo reporte.txt" << endl;
        exit(EXIT_FAILURE);
    }

    archRep.precision(2);
    archRep << fixed;

    int codAlumno, ciclo, aux, cicloAnt, veces;
    double numCreditos;
    char c;

    while(1) {
        cicloAnt = -1;

        archDatos >> codAlumno;
        if(archDatos.eof()) break;
        archRep << codAlumno;

        // se leen el ciclo, curso, créditos y veces
        while(1) {
            // lectura del ciclo
            archDatos >> ciclo;
            archDatos.get(); // para sacar el guion
            archDatos >> aux;
            ciclo = ciclo * 10 + aux;
            // se imprime el ciclo si se ha leído por primera vez
            if(cicloAnt == -1 || cicloAnt != ciclo) {
                archRep << endl << ciclo / 10 << '-' << ciclo % 10 << endl;
                imprimirLinea(archRep, MAX_CAR_LIN, '-');
                archRep << endl;
            }
            cicloAnt = ciclo;

            // impresión del código del curso, carácter por carácter
            archDatos >> c;
            archDatos.unget();
            while((c = archDatos.get()) != ' ') {
                archRep << c;
            }

            // se supone que el siguiente dato es el número de veces
            archDatos >> veces;
            if(archDatos.peek() == '.') {
                // si se entra aquí, entonces el dato
                // era el número de créditos
                archDatos >> numCreditos;
                numCreditos += veces;

                // se lee el número de veces
                archDatos >> veces;
            }
            else {
                // si se entra aquí, el dato era correcto
                // se lee el número de créditos
                archDatos >> numCreditos;
            }

            // se imprimen el número de créditos y las veces
            archRep << setw(13) << numCreditos << setw(10) << veces << endl;

            if(archDatos.get() == '\n') {
                archRep << endl << endl;
                break;
            }
        }
    }


    archDatos.close();

    return 0;
}