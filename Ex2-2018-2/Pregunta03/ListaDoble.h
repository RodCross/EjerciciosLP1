#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "NodoDoble.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

template <typename T>
class ListaDoble {
private:
    NodoDoble<T> *cabecita;
    NodoDoble<T> *colita;
    void insertar(T &);
public:
    ListaDoble();
    virtual ~ListaDoble();
    void crear(ifstream &);
    void imprimir(ofstream &, int);
    double buscar(int);
};

template <typename T>
ListaDoble<T>::ListaDoble() {
    cabecita = colita = NULL;
}

template <typename T>
ListaDoble<T>::~ListaDoble() {
    NodoDoble<T> *p = cabecita, *sale;
    
    while (p) {
        sale = p;
        p = p->der;
        delete sale;
    }
}

template <typename T>
void ListaDoble<T>::crear(ifstream &arch) {
    T dato;
    
    while (1) {
        arch >> dato;
        if (arch.eof()) break;
        insertar(dato);
    }
}

template <typename T>
void ListaDoble<T>::insertar(T& dato) {
    NodoDoble<T> *p = cabecita, *ant = NULL, *nuevo;
    
    nuevo = new NodoDoble<T>;
    nuevo->dato = dato;
    
    while (p) {
        if (p->dato > dato) break;
        ant = p;
        p = p->der;
    }
     
    nuevo->der = p;
    nuevo->izq = ant;
    if (p) p->izq = nuevo;
    else colita = nuevo;
    if (ant) ant->der = nuevo;
    else cabecita = nuevo;
}

template <typename T>
void ListaDoble<T>::imprimir(ofstream &arch, int opcion) {
    NodoDoble<T> *p;
    
    // 0: DE INICIO A FIN
    if (opcion == 0) {
        arch << "DE INICIO A FIN" << endl << endl;
        p = cabecita;
        while (p) {
            arch << p->dato << endl;
            p = p->der;
        }
    }
    // 1: DE FIN A INICIO
    else if (opcion == 1) {
        arch << "DE FIN A INICIO" << endl << endl;
        p = colita;
        while (p) {
            arch << p->dato << endl;
            p = p->izq;
        }
    }
    
    arch << endl;
}

template <typename T>
double ListaDoble<T>::buscar(int cod) {
    NodoDoble<T> *p = cabecita;
    
    while (p) {
        if (p->dato == cod) return p->dato.obtenerCosto();
        p = p->der;
    }
    
    return -1;
}

#endif /* LISTADOBLE_H */
