#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "FuncDeCadenas.h"

void leerDatos(char **&codCur, char **&nomCur, char ***&req) {
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

    int numDat = 0;
    char *buffCodCur[100], *buffNomCur[100], **buffReq[100];
    char **codCur2, **req2;

    leerRequisitos(archReq, codCur2, req2);

    while (1) {
        buffCodCur[numDat] = leerCodigo(archCur);
        if (buffCodCur[numDat] == NULL) break;
        buffNomCur[numDat] = leerCurso(archCur);
        buffReq[numDat] = leerReq(codCur2, req2, buffCodCur[numDat]);
        numDat++;
    }

    delete[] codCur2;
    delete[] req2;

    codCur = new char *[numDat + 1];
    nomCur = new char *[numDat + 1];
    req = new char **[numDat + 1];
    for (int i = 0; i < numDat; i++) {
        codCur[i] = buffCodCur[i];
        nomCur[i] = buffNomCur[i];
        req[i] = buffReq[i];
    }
    codCur[numDat] = nomCur[numDat] = NULL;
    req[numDat] = NULL;
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

void ordenarDatos(char **codCur, char **nomCur, char ***req) {
    int nd;

    for (nd = 0; codCur[nd]; nd++);
    ordenarQS(codCur, nomCur, req, 0, nd - 1);
}

void imprimirDatos(char **codCur, char **nomCur, char ***req) {
    ofstream archRep("reporte.txt", ios::out);
    if (!archRep) {
        cout << "Error: no se pudo abrir el archivo reporte.txt" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; codCur[i]; i++) {
        archRep << right << setw(4) << i + 1 << ") " << left << setw(10) << codCur[i];
        archRep << setw(60) << nomCur[i];
        imprimirReq(archRep, req[i]);
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

char **leerReq(char **codCur2, char **req2, char *cod) {
    char **req = NULL, *codReq;
    int tamReq = 0, numReq = 0;
    int p = 0;

    while (1) {
        if (codCur2[p] == NULL) break;
        if (strcmp(codCur2[p], cod) == 0) {
            codReq = new char[7];
            strcpy(codReq, req2[p]);
            if (numReq == tamReq) {
                incrementarEspacios(req, numReq, tamReq);
            }
            req[numReq] = NULL;
            req[numReq - 1] = codReq;
            numReq++;
        }
        p++;        
    }
    return req; 
}

void incrementarEspacios(char **&req, int &numReq, int &tamReq) {
    char **aux;

    tamReq += INCREMENTO;
    if (req == NULL) {
        req = new char *[tamReq];
        numReq++;
    }
    else {
        aux = new char *[tamReq];
        for (int i = 0; i < numReq; i++) {
            aux[i] = req[i];
        }
        delete[] req;
        req = aux;
    }
}

void ordenarQS(char **codCur, char **nomCur, char ***req, int izq, int der) {
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

void cambiar(char **codCur, char **nomCur, char ***req, int i, int j) {
    char *aux1, **aux2;

    aux1 = codCur[i];
    codCur[i] = codCur[j];
    codCur[j] = aux1;

    aux1 = nomCur[i];
    nomCur[i] = nomCur[j];
    nomCur[j] = aux1;

    aux2 = req[i];
    req[i] = req[j];
    req[j] = aux2;
}

void imprimirReq(ofstream &archRep, char **req) {
    for (int i = 0; req[i]; i++) {
        archRep << setw(10) << req[i];
    }
}