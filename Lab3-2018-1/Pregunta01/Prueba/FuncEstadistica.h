#ifndef FUNCESTADISTICA_H
#define FUNCESTADISTICA_H

template <typename TIPO>
double mediaAritmetica(TIPO *, int);
// Parámetros: datos, número de datos

template <typename TIPO>
double mediaAritmeticaPonderada(TIPO *, TIPO *, int);
// Parámetros: datos, pesos, número de datos

template <typename TIPO>
void swap(TIPO *, int, int);

template <typename TIPO>
int partition(TIPO *, int, int);

template <typename TIPO>
void quicksort(TIPO *, int, int);

template <typename TIPO>
double mediana(TIPO *, int);
// Parámetros: datos, número de datos

template <typename TIPO>
double desviacionEstandar(TIPO *, int);
// Parámetros: datos, número de datos

template <typename TIPO>
void distribucionDeFrecuencias(TIPO *, int, TIPO *, int, int *, int &);
// Parámetros: datos, número de datos, límites, número de límites, frecuencias

#endif