/* 
 * Archivo:  Funcioneslaboratorio06.h
 * Autor:    Rodrigo Alonso Cruz Lean
 * Codigo:   20170516
 *
 * Creado el 11 de octubre de 2019, 08:18 AM
 */

#ifndef FUNCIONESLABORATORIO06_H
#define FUNCIONESLABORATORIO06_H

#include <fstream>
using namespace std;

void leerPalets(void *&);
void *leerPal(ifstream &);
void imprimirPalets(void *);
void imprimirPal(ofstream &, void *);
void leerProductos(void *&);
void *leerProd(ifstream &);
void imprimirProductos(void *);
void imprimirProd(ofstream &, void *);
void ordenaproductos(void *);
void ordenarQS(void *, int, int);
void cambiar(void *&, void *&);
int comparar(void *, void *);
void cargastock(void *, void *);
int obtenerStock(void *, void *);
void modificarStock(void *, int);
void reportarStock(void *);
void imprimirProdCant(ofstream &, void *);
void imprimirLinea(ofstream &, int, char);

#endif /* FUNCIONESLABORATORIO06_H */

