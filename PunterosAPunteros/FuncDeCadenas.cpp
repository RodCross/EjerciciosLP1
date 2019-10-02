#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "FuncDeCadenas.h"

void leerDatos(char **&codCur, char **&nomCur, char **&req) {
    ifstream archCur("cursos.csv", ios::in);
    if (!archCur) {
        cout << "Error: no se pudo abrir el archivo cursos.csv" << endl;
        exit(EXIT_FAILURE);
    }
    ifstream archReq("requisitos.csv", ios::in);
    if (!archReq) {
        cout << "Error: no se pudo abrir el archivo requisitos.csv" << endl;
        exit(EXIT_FAILURE);
    }

    int numDat = 0, pos;
    char *buffCodCur[100], *buffNomCur[100], *buffReq[100];
    char **codCur2, **req2;

    leerRequisitos(archReq, codCur2, req2);

    while (1) {
        buffCodCur[numDat] = leerCodigo(archCur);
        if (buffCodCur[numDat] == NULL) break;
        buffNomCur[numDat] = leerCurso(archCur);
        pos = buscarCurso(buffCodCur[numDat], codCur2);
        if (pos != -1) {
            buffReq[numDat] = req2[pos];
        }
        else {
            buffReq[numDat] = NULL;
        }
        numDat++;
    }

    delete[] codCur2;
    delete[] req2;

    codCur = new char *[numDat + 1];
    nomCur = new char *[numDat + 1];
    req = new char *[numDat + 1];
    for (int i = 0; i < numDat; i++) {
        codCur[i] = buffCodCur[i];
        nomCur[i] = buffNomCur[i];
        req[i] = buffReq[i];
    }
    codCur[numDat] = nomCur[numDat] = req[numDat] = NULL;
}

char *leerRequisitos(ifstream &arch, char **&codCur2, char **&req2) {
    int numDat = 0;
    char *buffCodCur2[150], *buffReq2[150];

    while (1) {
        buffCodCur2[numDat] = leerCodigo(arch);
        if (buffCodCur2[numDat] == NULL) break;
        buffReq2[numDat] = leerUnicoReq(arch);
        numDat++;
    }

    codCur2 = new char *[numDat + 1];
    req2 = new char *[numDat + 1];
    for (int i = 0; i < numDat; i++) {
        codCur2[i] = buffCodCur2[i];
        req2[i] = buffReq2[i];
    }
    codCur2[numDat] = req2[numDat] = NULL;
}

void ordenarDatos(char **codCur, char **nomCur, char **req) {
    int nd;

    for (nd = 0; codCur[nd]; nd++);
    ordenarQS(codCur, nomCur, req, 0, nd - 1);
}

void imprimirDatos(char **codCur, char **nomCur, char **req) {
    ofstream archRep("reporte.txt", ios::out);
    if (!archRep) {
        cout << "Error: no se pudo abrir el archivo reporte.txt" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; codCur[i]; i++) {
        archRep << right << setw(4) << i + 1 << ") " << left << setw(10) << codCur[i];
        archRep << setw(60) << nomCur[i];
        if (req[i] != NULL) {
            archRep << setw(10) << req[i];
        }
        archRep << endl;
    }
}

char *leerCodigo(ifstream &arch) {
    char *codCur;

    codCur = new char[7];
    arch.getline(codCur, 7, ',');
    if (arch.eof()) return NULL;
    return codCur;    
}

char *leerCurso(ifstream &arch) {
    char buff[200], *nomCur;

    arch.getline(buff, 200);
    nomCur = new char[strlen(buff) + 1];
    strcpy(nomCur, buff);
    return nomCur;
}

char *leerUnicoReq(ifstream &arch) {
    char *req;

    req = new char[7];
    arch.getline(req, 7);
    if (arch.eof()) return NULL;
    return req; 
}

int buscarCurso(char *cod, char **arr) {
    int p = 0;

    while (1) {
        if (arr[p] == NULL) return -1;
        if (strcmp(arr[p], cod) == 0) return p;
        p++;
    }
}

void ordenarQS(char **codCur, char **nomCur, char **req, int izq, int der) {
    int limite;

    if (izq >= der) return;
    cambiar(codCur, nomCur, req, izq, (izq + der) / 2);
    
    limite = izq;
    for (int i = izq + 1; i <= der; i++) {
        if (strcmp(nomCur[i], nomCur[izq]) < 0) {
            cambiar(codCur, nomCur, req, ++limite, i);
        }
    }
    
    cambiar(codCur, nomCur, req, izq, limite);
    ordenarQS(codCur, nomCur, req, izq, limite - 1);
    ordenarQS(codCur, nomCur, req, limite + 1, der);
}

void cambiar(char **codCur, char **nomCur, char **req, int i, int j) {
    char *aux;

    aux = codCur[i];
    codCur[i] = codCur[j];
    codCur[j] = aux;

    aux = nomCur[i];
    nomCur[i] = nomCur[j];
    nomCur[j] = aux;

    aux = req[i];
    req[i] = req[j];
    req[j] = aux;
}