/* 
 * Archivo:  Funcioneslaboratorio06.cpp
 * Autor:    Rodrigo Alonso Cruz Lean
 * Codigo:   20170516
 *
 * Creado el 11 de octubre de 2019, 08:18 AM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "Funcioneslaboratorio06.h"
using namespace std;

#define MAX_CAR_0 50
#define MAX_CAR_1 80
#define MAX_CAR_2 110

enum Pal {PROD_PAL, COD_PAL, CANTIDAD};
enum Prod {COD_PROD, NOM_PROD, STOCK};

void leerPalets(void *&palets) {
    ifstream archStock("Stock.txt", ios::in);
    if (!archStock) {
        cout << "Error: no se pudo abrir el archivo Stock.txt\n";
        exit(EXIT_FAILURE);
    }
    
    void *buff[500], *p, **pal;
    int numPal = 0;
    
    while (1) {
        p = leerPal(archStock);
        if (p == NULL) break;
        buff[numPal] = p;
        numPal++;
    }
    pal = new void *[numPal + 1];
    for (int i = 0; i < numPal; i++) {
        pal[i] = buff[i];
    }
    pal[numPal] = NULL;
    
    palets = pal;
}

void *leerPal(ifstream &arch) {
    char *prod, *cod;
    int *cant;
    void **palet;
    
    arch.peek();
    if (arch.eof()) return NULL;
    prod = new char[8];
    arch.getline(prod, 8, ' ');
    
    cod = new char[4];
    arch.getline(cod, 4, ' ');
    
    cant = new int;
    arch >> *cant;
    
    arch.get(); // sacar el '\n'
    
    palet = new void *[3];
    palet[PROD_PAL] = prod;
    palet[COD_PAL] = cod;
    palet[CANTIDAD] = cant;
    
    return palet;
}

void imprimirPalets(void *palets) {
    ofstream archRep("reportePalets.txt", ios::out);
    if (!archRep) {
        cout << "Error: no se pudo abrir el archivo reportePalets.txt\n";
        exit(EXIT_FAILURE);
    }
    
    // imprimir encabezado
    archRep << left << setw(21) << "COD. PRODUCTO"
            << setw(15) << "COD. PALET"
            << right << setw(14) << "CANTIDAD" << endl;
    imprimirLinea(archRep, MAX_CAR_0, '-');
    
    void **palet = (void **)palets;
    for (int i = 0; palet[i]; i++) {
        imprimirPal(archRep, palet[i]);
    }
}

void imprimirPal(ofstream &arch, void *palet) {
    void **pal = (void **)palet;
    char *prod = (char *)pal[PROD_PAL];
    char *cod = (char *)pal[COD_PAL];
    int *cant = (int *)pal[CANTIDAD];
    
    arch << left << setw(24) << prod << setw(12) << cod
        << right << setw(11) << *cant << endl;
}

void leerProductos(void *&producto) {
    ifstream archProd("Productos.csv", ios::in);
    if (!archProd) {
        cout << "Error: no se pudo abrir el archivo Productos.csv\n";
        exit(EXIT_FAILURE);
    }
    
    void *buff[50], *p, **prod;
    int numProd = 0;
 
    while (1) {
        p = leerProd(archProd);
        if (p == NULL) break;
        buff[numProd] = p;
        numProd++;
    }
    prod = new void *[numProd + 1];
    for (int i = 0; i < numProd; i++) {
        prod[i] = buff[i];
    }
    prod[numProd] = NULL;
    
    producto = prod;
}

void *leerProd(ifstream &arch) {
    char *cod, *nom, buff[100];
    int *stock;
    void **producto;
    
    arch.peek();
    if (arch.eof()) return NULL;
    cod = new char[8];
    arch.getline(cod, 8, ',');
    
    arch.getline(buff, 100);
    nom = new char[strlen(buff) + 1];
    strcpy(nom, buff);
    
    stock = new int;
    *stock = 0;
    
    producto = new void *[3];
    producto[COD_PROD] = cod;
    producto[NOM_PROD] = nom;
    producto[STOCK] = stock;
    
    return producto;
}

void imprimirProductos(void *producto) {
    static int vez = 0;
    
    ofstream archRep;
    
    if(vez == 0) {
        archRep.open("reporteProd.txt", ios::out);
        if (!archRep) {
            cout << "Error: no se pudo abrir el archivo reporteProd.txt\n";
            exit(EXIT_FAILURE);
        }
    }
    else {
        archRep.open("reporteProdOrd.txt", ios::out);
        if (!archRep) {
            cout << "Error: no se pudo abrir el archivo reporteProdOrd.txt\n";
            exit(EXIT_FAILURE);
        }
    }
    
    // imprimir encabezado
    archRep << left << setw(10) << "CODIGO"
            << setw(60) << "NOMBRE DEL PRODUCTO"
            << right << setw(10) << "STOCK" << endl;
    imprimirLinea(archRep, MAX_CAR_1, '-');
    
    void **prod = (void **)producto;
    for (int i = 0; prod[i]; i++) {
        imprimirProd(archRep, prod[i]);
    }
    
    vez++;
}

void imprimirProd(ofstream &arch, void *producto) {
    void **prod = (void **)producto;
    char *cod = (char *)prod[COD_PROD];
    char *nom = (char *)prod[NOM_PROD];
    int *stock = (int *)prod[STOCK];
    
    arch << left << setw(10) << cod << setw(60) << nom
        << right << setw(8) << *stock << endl;
}

void ordenaproductos(void *producto) {
    void **prod = (void **)producto;
    int numProd;
    
    for (numProd = 0; prod[numProd]; numProd++);
    
    ordenarQS(producto, 0, numProd - 1);
}

void ordenarQS(void *producto, int izq, int der) {
    void **prod = (void **)producto;
    int limite;
    
    if (izq >= der) return;
    cambiar(prod[izq], prod[(izq + der) / 2]);
    
    limite = izq;
    for (int i = izq + 1; i <= der; i++) {
        if (comparar(prod[i], prod[izq]) < 0) {
            cambiar(prod[++limite], prod[i]);
        }
    }
    
    cambiar(prod[izq], prod[limite]);
    ordenarQS(prod, izq, limite - 1);
    ordenarQS(prod, limite + 1, der);
}

void cambiar(void *&a, void *&b) {
    void *temp;
    
    temp = a;
    a = b;
    b = temp;
}

int comparar(void *prodI, void *prodJ) {
    void **pI = (void **)prodI, **pJ = (void **)prodJ;
    char *nI = (char *)pI[NOM_PROD], *nJ = (char *)pJ[NOM_PROD];
    
    return strcmp(nI, nJ);
}

void cargastock(void *palets, void *producto) {
    void **pal = (void **)palets;
    void **prod = (void **)producto;
    int cant;
    
    for (int i = 0; prod[i]; i++) {
        cant = 0;
        for (int j = 0; pal[j]; j++) {
            cant += obtenerStock(prod[i], pal[j]);
        }
        modificarStock(prod[i], cant);
    }
    
    reportarStock(producto);
}

int obtenerStock(void *producto, void *palet) {
    void **prod = (void **)producto;
    void **pal = (void **)palet;
    char *codProd = (char *)prod[COD_PROD];
    char *codPal = (char *)pal[PROD_PAL];
    
    if (strcmp(codProd, codPal) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void modificarStock(void *producto, int cant) {
    void **prod = (void **)producto;
    int *stock = (int *)prod[STOCK];
    
    *stock = cant;
}

void reportarStock(void *producto) {
    ofstream archRep("reporteStock.txt", ios::out);
    if (!archRep) {
        cout << "Error: no se pudo abrir el archivo reporteStock.txt\n";
        exit(EXIT_FAILURE);
    }
    
    // imprimir encabezado
    archRep << left << setw(65) << "NOMBRE DE PRODUCTO"
            << setw(25) << "CODIGO DE PRODUCTO"
            << right << setw(20) << "CANT. DE PRODUCTOS" << endl;
    imprimirLinea(archRep, MAX_CAR_2, '-');
    
    void **prod = (void **)producto;
    for (int i = 0; prod[i]; i++) {
        imprimirProdCant(archRep, prod[i]);
    }
}

void imprimirProdCant(ofstream &arch, void *producto) {
    void **prod = (void **)producto;
    char *cod = (char *)prod[COD_PROD];
    char *nom = (char *)prod[NOM_PROD];
    int *stock = (int *)prod[STOCK];
    
    arch << left << setw(70) << nom << setw(25) << cod
        << right << setw(7) << *stock << endl;
}

void imprimirLinea(ofstream &arch, int n, char c) {
    for (int i = 0; i < n; i++) {
        arch.put(c);
    }
    arch << endl;
}
