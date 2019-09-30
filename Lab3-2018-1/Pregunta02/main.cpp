/* 
 * File:   main.cpp
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

using namespace std;

#include "funciones.h"
#include "FuncionesEstadisticas.h"
#define MAX_LINEA 100

int main(int argc, char** argv) {
    ifstream archReg;
    archReg.open("RegistroDeSismos.txt",ios::in);
    if(!archReg){
        cout<<"Error al abrir el archivo RegistroDeSismos.txt"<<endl;
        exit(1);
    }
    ofstream archRep;
    archRep.open("Reporte.txt", ios::out);
    if(!archRep){
        cout<<"Error al abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    
    // Impresion del titulo
    archRep<<setw(75)<<right<<"REPORTE DE LOS SISMOS A TRAVES DEL TIEMPO"<<endl;

    // Declaracion de variables
    char c, *pais, *ciudad;
    double *intensidad = NULL;
    int *fecha = NULL, *hora = NULL, *duracion = NULL, numDat, num=1;
    
    while(1){
        archReg.get();
        if(archReg.eof()) break;
        archReg.unget();
        
        // Reiniciar arreglos
        if(num > 1){
            delete [] intensidad;
            delete [] fecha;
            delete [] hora;
            delete [] duracion;
            intensidad = NULL;
            fecha = hora = duracion = NULL;
        }
        
        
        // Lectura de datos
        pais = leeNombre(archReg,',');
        ciudad = leeNombre(archReg, ':');
        archReg.get();      // Se come el enter
        
        // Lee los datos por cada ciudad y los guarda en arreglos
        leeDatos(archReg, intensidad, duracion, fecha, hora, numDat);
        
        // Impresion de los datos
        impEncabezado(archRep);
        impDatos(archRep, num, pais, ciudad, intensidad, duracion, fecha, hora, numDat);
        impResumen(archRep, intensidad, duracion,fecha, hora, numDat);
        impInfEstadistica(archRep, intensidad, duracion, fecha, hora, numDat);
        impCantidadReg(archRep, numDat);
        
        num++;
        archRep<<endl;
    }
    
    return 0;
}

