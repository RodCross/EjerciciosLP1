#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Funcioneslaboratorio05.h"

void leerPalets(char ***&almacenes) {
    ifstream archStock("Stock.txt", ios::in);
    if (!archStock) {
        cout << "Error: no se pudo abrir el archivo Stock.txt" << endl;
        exit(EXIT_FAILURE);
    }
    
    char **buffAlmacenes[100];
    int alm, almPrev, arrAlm[100], numAlm;

    // guardar los numeros de almacen en un arreglo
    almPrev = -1;
    numAlm = 0;
    while (1) {
        archStock >> alm;
        if (archStock.eof()) break;
        if (alm != almPrev) {
            arrAlm[numAlm] = alm;
            numAlm++;
        }
        almPrev = alm;
        saltarLinea(archStock);
    }
    archStock.clear();
    
    for (int i = 0; i < numAlm; i++) {
        buffAlmacenes[i] = leerPal(archStock, arrAlm[i]);
    }

    almacenes = new char **[numAlm + 1];
    for (int i = 0; i < numAlm; i++) {
        almacenes[i] = buffAlmacenes[i];
    }
    almacenes[numAlm] = NULL;
}

void saltarLinea(ifstream &arch) {
    char c;
    while ((c = arch.get()) != '\n');
}

char **leerPal(ifstream &arch, int alm) {
    int temp;
    int numPal = 0, tamPal = 0;
    char **pal = NULL, *cod;
    char c;

    arch.seekg(0, ios::beg);
    while (1) {
        arch >> temp;
        if (arch.eof()) {
            arch.clear();
            break;
        }

        if (alm == temp) {
            while (isspace(c = arch.get()));
            arch.unget();
            
            cod = new char[8];
            arch.get(cod, 8);
            if (numPal == tamPal) {
                incrementarEspacios(pal, numPal, tamPal);
            }
            pal[numPal] = NULL;
            pal[numPal - 1] = cod;
            numPal++;
        }
        saltarLinea(arch);
    }
    
    return pal;
}

void incrementarEspacios(char **&pal, int &num, int &tam) {
    char **aux;

    tam += INCREMENTO;
    if (pal == NULL) {
        pal = new char *[tam];
        num++;
    }
    else {
        aux = new char *[tam];
        for (int i = 0; i < num; i++) {
            aux[i] = pal[i];
        }
        delete[] pal;
        pal = aux;
    }
}

void imprimirPalets(char ***almacenes) {
    ofstream archOut("reporte1.txt", ios::out);
    if (!archOut) {
        cout << "Error: no se pudo abrir el archivo reporte1.txt\n";
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; almacenes[i]; i++) {
        archOut << right << setw(4) << i + 1 << ")    ";
        imprimirPal(archOut, almacenes[i]);
        archOut << endl;
    }
}

void imprimirLinea(ofstream &arch, int n, char c) {
    for (int i = 0; i < n; i++) {
        arch.put(c);
    }
    arch << endl;
}

void imprimirPal(ofstream &archOut, char **pal) {
    archOut << left << setw(10) << pal[0] << endl;
    for (int i = 1; pal[i]; i++) {
        archOut << setw(9) << " ";
        archOut << left << setw(10) << pal[i] << endl;
    }
}

void leerProductos(char **&codigoProd, char **&nombreProd) {
    ifstream archProd("Productos.csv", ios::in);
    if (!archProd) {
        cout << "Error: no se pudo abrir el archivo Productos.csv\n";
        exit(EXIT_FAILURE);
    }

    char *buffCod[100], *buffNom[100];
    int numProd = 0;

    while (1) {
        buffCod[numProd] = leerCod(archProd);
        if (buffCod[numProd] == NULL) break;
        buffNom[numProd] = leerNom(archProd);
        numProd++;
    }

    codigoProd = new char *[numProd + 1];
    nombreProd = new char *[numProd + 1];
    for (int i = 0; i < numProd; i++) {
        codigoProd[i] = buffCod[i];
        nombreProd[i] = buffNom[i];
    }
    codigoProd[numProd] = nombreProd[numProd] = NULL;
}

char *leerCod(ifstream &arch) {
    char *cod;

    cod = new char[8];
    arch.getline(cod, 8, ',');
    if (arch.eof()) return NULL;
    return cod;
}

char *leerNom(ifstream &arch) {
    char buff[100], *nom;

    arch.getline(buff, 100);
    nom = new char[strlen(buff) + 1];
    strcpy(nom, buff);
    return nom;
}


void imprimirProductos(char **codigoProd, char **nombreProd) {
    ofstream archRep("reporte2.txt", ios::out);
    if(!archRep) {
        cout << "Error: no se pudo abrir el archivo reporte2.txt\n";
        exit(EXIT_FAILURE);
    }

    archRep << left << setw(10) << "CODIGO" << setw(60) << "NOMBRE" << endl;
    imprimirLinea(archRep, MAX_CAR_PROD, '=');

    for (int i = 0; codigoProd[i]; i++) {
        archRep << setw(10) << codigoProd[i]
            << setw(60) << nombreProd[i] << endl;
    }
}

void ordenaproductos(char **codigoProd, char **nombreProd) {
   int numProd;

   for (numProd = 0; codigoProd[numProd]; numProd++);
   ordenarQS(codigoProd, nombreProd, 0, numProd - 1);
}

void ordenarQS(char **codigoProd, char **nombreProd, int izq, int der) {
    int limite;

    if (izq >= der) return;
    cambiar(codigoProd, nombreProd, izq, (izq + der) / 2);

    limite = izq;
    for (int i = izq + 1; i <= der; i++) {
        if (strcmp(nombreProd[i], nombreProd[izq]) < 0) {
            cambiar(codigoProd, nombreProd, ++limite, i);
        }
    }

    cambiar(codigoProd, nombreProd, izq, limite);
    ordenarQS(codigoProd, nombreProd, izq, limite - 1);
    ordenarQS(codigoProd, nombreProd, limite + 1, der);
}

void cambiar(char **codigoProd, char **nombreProd, int i, int j) {
    char *temp;

    temp = codigoProd[i];
    codigoProd[i] = codigoProd[j];
    codigoProd[j] = temp;

    temp = nombreProd[i];
    nombreProd[i] = nombreProd[j];
    nombreProd[j] = temp;
}

void cuentaProductos(char ***almacenes, char **codigoProd, char **nombreProd) {
    int numProd, numAlm, cant;
    int *cantPalets;

    for (numProd = 0; codigoProd[numProd]; numProd++);
    for (numAlm = 0; almacenes[numAlm]; numAlm++);
    cantPalets = new int[numProd];

    for (int i = 0; i < numProd; i++) {
        cant = 0;
        for (int j = 0; j < numAlm; j++) {
            cant += obtenerCantProd(codigoProd[i], almacenes[j]);
        }
        cantPalets[i] = cant;
    }
    
    reportarCantPalets(codigoProd, nombreProd, cantPalets);
}

int obtenerCantProd(char *codigo, char **almacen) {
    int cant = 0;

    for (int i = 0; almacen[i]; i++) {
        if (strcmp(codigo, almacen[i]) == 0) {
            cant++;
        }
    }

    return cant;
}

void reportarCantPalets(char **codigoProd, char **nombreProd, int *cantPalets) {
    ofstream archRep("reporte3.txt", ios::out);
    if (!archRep) {
        cout << "Error: no se pudo abrir el archivo reporte3.txt\n";
        exit(EXIT_FAILURE);
    }

    archRep << left << setw(60) << "NOMBRE" << setw(19) << "CODIGO" << "PALETS\n";
    imprimirLinea(archRep, MAX_CAR_PAL, '=');

    for (int i = 0; codigoProd[i]; i++) {
        archRep << left << setw(60) << nombreProd[i]
            << setw(19) << codigoProd[i]
            << right << setw(4) << cantPalets[i] << endl;
    }
}