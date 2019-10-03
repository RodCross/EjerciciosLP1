#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Biblioteca-Lab05.h"

enum Curso {CODIGO, NOMBRE};

void leerCursos(char ***&cursos) {
    ifstream archIn("Matricula.csv", ios::in);
    if (!archIn) {
        cout << "Error: no se pudo abrir el archivo Matricula.csv" << endl;
        exit(EXIT_FAILURE);
    }

    char **buffCursos[100];
    int numDat = 0;

    while(1) {
        if (archIn.peek() == '\n') break;
        buffCursos[numDat] = leerCur(archIn);
        numDat++;
    }

    cursos = new char **[numDat + 1];
    for (int i = 0; i < numDat; i++) {
        cursos[i] = buffCursos[i];
    }
    cursos[numDat] = NULL;
}

char **leerCur(ifstream &archIn) {
    char **cur;
    char *cod, buffNom[100], *nom;

    cod = new char[7];
    archIn.getline(cod, 7, ',');
    archIn.getline(buffNom, 100);
    nom = new char[strlen(buffNom) + 1];
    strcpy(nom, buffNom);

    cur = new char *[2];
    cur[CODIGO] = cod;
    cur[NOMBRE] = nom;

    return cur;
}

void imprimirCursos(char ***cursos) {
    for (int i = 0; cursos[i]; i++) {
        cout << setw(4) << i + 1 << ") ";
        imprimirCur(cursos[i]);
        cout << endl;
    }
}

void imprimirCur(char **cur) {
    cout << setw(10) << cur[CODIGO];
    cout << setw(5) << " ";
    cout << cur[NOMBRE];
}

// void leerMatricula(int *&, char ***&) {

// }

// void imprimirMatricula(int *, char ***) {

// }

// void armarListasDeClases(char ***&, int *&, char ***&) {

// }

// void imprimirListasDeClases(char ***, char ***) {

// }
