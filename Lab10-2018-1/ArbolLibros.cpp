#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "ArbolLibros.h"

ArbolLibros::ArbolLibros() {
    arbol = NULL;
}

ArbolLibros::~ArbolLibros() {
    eliminarArbol(arbol);
}

void ArbolLibros::crearArbol(ifstream &arch) {
    Nodo datos;
    
    while (1) {
        arch >> datos.libro;
        if (arch.eof()) break;
        insertar(datos, arbol);
    }
}

void ArbolLibros::insertar(Nodo &datos, Nodo *&arbol) {
    if (arbol == NULL) {
        char buff[100];
        
        arbol = new Nodo;
        
        datos.libro.GetCodigo(buff);
        arbol->libro.SetCodigo(buff);
        
        datos.libro.GetTitulo(buff);
        arbol->libro.SetTitulo(buff);
        
        datos.libro.GetAutor(buff);
        arbol->libro.SetAutor(buff);
        
        arbol->libro.SetPrecio(datos.libro.GetPrecio());
        
        return;
    }
    
    char buff1[100], buff2[100];
    
    datos.libro.GetCodigo(buff1);
    arbol->libro.GetCodigo(buff2);
    
    if (strcmp(buff1, buff2) < 0) {
        insertar(datos, arbol->izq);
    }
    else {
        insertar(datos, arbol->der);
    }
}

Nodo* ArbolLibros::buscar(char *codigo) {
    char buff[100];
    Nodo *p = arbol;
    
    while (p) {
        p->libro.GetCodigo(buff);
        if (strcmp(codigo, buff) == 0) return p;
        if (strcmp(codigo, buff) < 0) p = p->izq;
        else p = p->der;
    }
    
    return NULL;
}

void ArbolLibros::venderLibro(ifstream &arch) {
    char buff[50];
    Nodo *p;
    
    while (1) {
        arch.getline(buff, 50, ','); // ignorar fecha
        arch.getline(buff, 50, ','); // ignorar hora
        arch.getline(buff, 7);       // leer codigo
        if (arch.eof()) break;
        
        p = buscar(buff);
        if (p != NULL) {
            p->libro++;
        }
    }
}

void ArbolLibros::imprimirLibros(ofstream &arch) {
    imprimirEnOrden(arch, arbol);
}

void ArbolLibros::imprimirEnOrden(ofstream &arch, Nodo *arbol) {
    if (arbol == NULL) return;
    imprimirEnOrden(arch, arbol->izq);
    arch << arbol->libro;
    imprimirEnOrden(arch, arbol->der);
}

void ArbolLibros::eliminarArbol(Nodo *arbol) {
    if (arbol == NULL) return;
    eliminarArbol(arbol->izq);
    eliminarArbol(arbol->der);
    delete arbol;
}
