/* 
 * File:   funciones.cpp
 * Miguel Antero Silva Luna
 * 20171051
 * Laboratorio 3
 * LP 1 2018-1
 * Pregunta 2
 * 
 * Created on 20 de septiembre de 2019, 08:04 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "funciones.h"
#include "FuncionesEstadisticas.h"

#define INCREMENTO 5
#define MAX_LINEA 120

void impLinea(ofstream &arch,char c, int n){
    for(int i=0; i<n; i++){
        arch.put(c);
    }
    arch<<endl;
}

char *leeNombre(ifstream &arch,char a){
    char buff[500], *nombre;
    arch.getline(buff,500,a);
    if(arch.eof()) return NULL;
    nombre = new char[strlen(buff)+1];
    strcpy(nombre,buff);
    return nombre;
}

void leeDatos(ifstream &arch, double *&intensidad, int *&duracion, 
        int *&fecha, int *&hora, int &numDat){
    
    char c;
    double inten;
    int dur, dd, mm, aa, hh, min, seg;
    int fech, hor, cap1, cap2, cap3, cap4;
    numDat = cap1 = cap2 = cap3 = cap4 = 0;
    
    while(1){
        c = arch.get();
        if(c == '\n'||arch.eof()) break;
        arch.unget();
        
        arch>>inten>>dur>>dd>>c>>mm>>c>>aa>>hh>>c>>min>>c>>seg;
        arch.get();     // Final de linea
        
        fech = aa*10000 + mm*100 + dd;
        hor = hh*10000 + min*100 + seg;
        
        addData(intensidad, inten, numDat, cap1);
        addData(duracion, dur, numDat, cap2);
        addData(fecha, fech, numDat, cap3);
        addData(hora, hor, numDat, cap4);
        numDat++;
    }
}

template <typename TIPO>
void addData(TIPO *&arreglo, TIPO dato, int numDat, int &cap){
    if(numDat == cap) incrementarEsp(arreglo,numDat, cap);
    arreglo[numDat] = dato;
}

template <typename TIPO>
void incrementarEsp(TIPO *& arreglo, int numDat, int &cap){
    TIPO *aux;
    cap += INCREMENTO;
    if(arreglo == NULL){
        arreglo = new TIPO [cap];
    }
    else{
        aux = new TIPO [cap];
        for(int i=0; i<numDat; i++)
            aux[i] = arreglo[i];
        delete [] arreglo;
        arreglo = aux;
    }
}

void impEncabezado(ofstream &arch){
    impLinea(arch, '=', MAX_LINEA);
    arch<<"Nro   PAIS            CIUDAD                  INTENSIDAD        DURACION       Fecha        Hora      Observacion"<<endl;
    impLinea(arch, '=', MAX_LINEA);
}

void impDatos(ofstream &arch, int num, char* pais, char *ciudad, 
        double *intensidad, int *duracion, int *fecha, int *hora, int numDat){
    
    int dd, mm, aa, hh, min, seg, aux;
    int iMin, iMax, dMax, dMin;
    
    // Hallar minima y maxima intensidad
    hallarMinMax(intensidad, iMin, iMax, numDat);
    hallarMinMax(duracion, dMin, dMax, numDat);
    
    arch.precision(2);
    arch<<fixed;
    for(int i=0; i<numDat; i++){
        if(i == 0){
            arch.fill('0');
            arch<<setw(2)<<num;
            arch.fill(' ');
            arch<<"   "<<setw(16)<<left<<pais<<setw(26)<<ciudad;
        }
        else{
            arch.fill(' ');
            arch<<setw(35+12)<<"";
        }
        arch<<right<<setw(4)<<intensidad[i]<<setw(16)<<duracion[i]<<setw(8)<<"";
        
        aa = fecha[i]/10000;
        aux = fecha[i]%10000;
        mm = aux/100;
        dd = aux%100;
        
        hh = hora[i]/10000;
        aux = hora[i]%10000;
        min = aux/100;
        seg = aux%100;
        
        arch.fill('0');
        arch<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa;
        arch.fill(' ');
        arch<<setw(4)<<"";
        arch.fill('0');
        arch<<setw(2)<<hh<<":"<<setw(2)<<min<<":"<<setw(2)<<seg;
        
        // Observacion
        if(i==iMin) arch<<"    Minima Intensidad";
        if(i==iMax) arch<<"    Maxima Intensidad";
        if(i==dMin) arch<<"    Minima Duracion";
        if(i==dMax) arch<<"    Maxima Duracion";
        
        arch<<endl;
    }
    impLinea(arch, '-', MAX_LINEA);
}

template <typename TIPO>
void hallarMinMax(TIPO *arreglo, int &iMin, int &iMax, int numDat){
    TIPO max = -1, min = 1000000;
    for(int i=0; i<numDat; i++){
        if(arreglo[i]>max) {
            max = arreglo[i];
            iMax = i;
        }
        if(arreglo[i]<min) {
            min = arreglo[i];
            iMin = i;
        }
    }
}

void impResumen(ofstream &arch, double *intensidad, int *duracion, int *fecha, 
        int *hora, int numDat){
    
    int dd, mm, aa, hh, min, seg, aux;
    int iAntiguo, iReciente;
    
    // Hallar sismo mas antiguo y mas reciente
    hallarMinMax(fecha, iAntiguo, iReciente, numDat);
    
    arch<<"RESUMEN:"<<endl;
    arch<<"SISMO MAS ANTIGUO:  ";
    
    arch.fill(' ');
    arch<<setw(35+12)<<"";

    arch<<right<<setw(4)<<intensidad[iAntiguo]<<setw(16)<<duracion[iAntiguo]<<setw(8)<<"";

    aa = fecha[iAntiguo]/10000;
    aux = fecha[iAntiguo]%10000;
    mm = aux/100;
    dd = aux%100;

    hh = hora[iAntiguo]/10000;
    aux = hora[iAntiguo]%10000;
    min = aux/100;
    seg = aux%100;

    arch.fill('0');
    arch<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa;
    arch.fill(' ');
    arch<<setw(4)<<"";
    arch.fill('0');
    arch<<setw(2)<<hh<<":"<<setw(2)<<min<<":"<<setw(2)<<seg<<endl;
    
    arch<<"SISMO MAS RECIENTE: ";
    
    arch.fill(' ');
    arch<<setw(35+12)<<"";

    arch<<right<<setw(4)<<intensidad[iReciente]<<setw(16)<<duracion[iReciente]<<setw(8)<<"";

    aa = fecha[iReciente]/10000;
    aux = fecha[iReciente]%10000;
    mm = aux/100;
    dd = aux%100;

    hh = hora[iReciente]/10000;
    aux = hora[iReciente]%10000;
    min = aux/100;
    seg = aux%100;

    arch.fill('0');
    arch<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa;
    arch.fill(' ');
    arch<<setw(4)<<"";
    arch.fill('0');
    arch<<setw(2)<<hh<<":"<<setw(2)<<min<<":"<<setw(2)<<seg<<endl;
}

void impInfEstadistica(ofstream &arch, double *intensidad, int *duracion, int *fecha, 
        int *hora, int numDat){
    
    double intM = mediaAritmetica(intensidad, numDat);
    double durM = mediaAritmetica(duracion, numDat);
    double durDV = desviacionEstandar(duracion, numDat);
    double intDV = desviacionEstandar(intensidad, numDat);
    double intMediana = mediana(intensidad, numDat);
    int durMediana = mediana(duracion, numDat);
    
    // Limites
    int numL=10, numFrec;
    double limIntens[numL];
    for(int i=0, j=1; i<numL; i++, j++){
        limIntens[i] = j;
    }
    int limDur[numL];
    for(int i=0, j=1; i<numL; i++, j++){
        limDur[i] = j*10;
    }
    int frecuencias[numL];
    arch.fill(' ');
    
    impLinea(arch,'*',MAX_LINEA);
    arch<<setw(70)<<right<<"INFORMACION ESTADISTICA"<<endl;
    arch<<setw(100)<<right<<"MEDIA ARITM.            DESV. ESTANDAR            MEDIANA"<<endl;
    
    
    arch.precision(2);
    arch<<fixed;
    arch<<"INTENSIDADES:"<<setw(30);
    arch<<setw(20)<<intM<<setw(20)<<intDV<<setw(17)<<intMediana<<endl;
    arch<<"DURACIONES:  "<<setw(30);
    arch<<setw(20)<<durM<<setw(20)<<durDV<<setw(17)<<durMediana<<endl;
    
    impLinea(arch, '*', MAX_LINEA);
    arch<<"            DISTRIBUCION DE FRECUENCIAS"<<endl;
    arch<<"   INTENSIDADES:"<<endl;
    distribucionDeFrecuencias(intensidad, numDat, limIntens, numL, frecuencias,numFrec);
    for(int f=0; f<numFrec-1; f++){
        if(f==0) arch <<"< "<<setw(2)<<limIntens[f]<<" : "<<setw(4)<<frecuencias[f]<<endl;
        else arch<<"  "<<setw(2)<<limIntens[f-1]+1<<" : "<<setw(4)<<frecuencias[f]<<endl;
    }
    arch<<" >"<<setw(2)<<limIntens[numL-1]<<" : "<<setw(4)<<frecuencias[numFrec-1]<<endl;
    
    arch<<"   DURACIONES:"<<endl;
    distribucionDeFrecuencias(duracion, numDat, limDur, numL, frecuencias,numFrec);
    for(int f=0; f<numFrec-1; f++){
        if(f==0) arch <<"< "<<setw(2)<<limDur[f]<<" : "<<setw(4)<<frecuencias[f]<<endl;
        else arch<<"  "<<setw(2)<<limDur[f-1]+1<<" : "<<setw(4)<<frecuencias[f]<<endl;
    }
    arch<<" >"<<setw(2)<<limIntens[numL-1]<<" : "<<setw(4)<<frecuencias[numFrec-1]<<endl;
    
}

void impCantidadReg(ofstream &arch, int numDat){
    impLinea(arch,'/', MAX_LINEA);
    arch<<"CANTIDAD DE REGISTROS: "<<numDat<<endl;
    impLinea(arch,'/', MAX_LINEA);
}

template void addData(double *&, double, int, int&);
template void addData(int *&, int, int, int&);

template void incrementarEsp(double *&, int, int&);
template void incrementarEsp(int *&, int, int&);

template void hallarMinMax(double*, int&, int&, int);
template void hallarMinMax(int*,int&,int&, int);