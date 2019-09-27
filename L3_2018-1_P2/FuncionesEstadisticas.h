/* 
 * File:   FuncionesEstadisticas.h
 * Author: migue
 *
 * Created on September 26, 2019, 3:51 PM
 */

#ifndef FUNCIONESESTADISTICAS_H
#define FUNCIONESESTADISTICAS_H

template <typename TIPO>
double mediaAritmetica(TIPO*,int);
//Parametros: (Datos, Numero de datos)

template <typename TIPO>
double mediaAritmeticaPonderada(TIPO*, TIPO*, int);
//Parametros: (Datos, Pesos, Numero de datos)

template <typename TIPO>
TIPO mediana(TIPO*, int);
//Parametros: (Datos, Numero de datos)

template <typename TIPO>
void ordenar(TIPO *, int, int);

template <typename TIPO>
void cambiar(TIPO*, int, int);

template <typename TIPO>
double desviacionEstandar(TIPO*, int);
//Parametros: (Datos, Numero de datos)

template <typename TIPO>
void distribucionDeFrecuencias(TIPO*, int, TIPO*, int, int*, int&);
//Parametros: (Datos, Numero de datos, Limites, Numero de Limites,
//             Frecuencias, Numero de frecuencias)

#endif /* FUNCIONESESTADISTICAS_H */

