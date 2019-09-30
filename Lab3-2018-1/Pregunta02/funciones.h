/* 
 * File:   funciones.h
 * Miguel Antero Silva Luna
 * 20171051
 * Laboratorio 3
 * LP 1 2018-1
 * Pregunta 2
 * 
 * Created on 20 de septiembre de 2019, 08:04 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void impLinea(ofstream&, char, int);
char *leeNombre(ifstream &,char );
void leeDatos(ifstream &, double *&, int *&, 
        int *&, int *&, int &);

template <typename TIPO>
void addData(TIPO *&, TIPO , int , int &);

template <typename TIPO>
void incrementarEsp(TIPO *& , int , int &);

void impEncabezado(ofstream&);
void impDatos(ofstream &, int , char* , char *, 
        double *, int *, int *, int *, int );

template <typename TIPO>
void hallarMinMax(TIPO *, int &, int &, int );

void impResumen(ofstream &, double *, int *, int *, 
        int *, int );

void impInfEstadistica(ofstream &, double *, int *,int *, 
        int *, int );

void impCantidadReg(ofstream &, int );


#endif /* FUNCIONES_H */

