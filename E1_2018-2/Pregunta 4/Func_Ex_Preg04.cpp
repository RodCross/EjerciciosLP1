#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Func_Ex_Preg04.h"
#include "Func_Ex_Preg01.h"

#define MAX_LINEA 72

enum Ext {CODIGO, PROVINCIA, ANHO, ESPECIE, CANTIDADES};

void leerExtracciones(void *&extracciones, int &N){
    ifstream arch("extracciones.txt", ios::in);
    if(!arch){
        cout<<"Error al abrir extracciones.txt"<<endl;
        exit(1);
    }

    void **buffExtracciones[1000];
    void ***fin_extracciones;
    int numE=0;

    while(1){
        buffExtracciones[numE] = leerExtraccion(arch);
        if(buffExtracciones[numE] == NULL) break;
        numE++;
    }

    fin_extracciones = new void**[numE+1];
    for(int i=0; i<numE; i++)
        fin_extracciones[i] = buffExtracciones[i];
    fin_extracciones[numE] = NULL;
    extracciones = fin_extracciones;
    N = numE;
}

void** leerExtraccion(ifstream &arch){
    void **extraccion;
    int *codProv, *anho, *cantidades;
    char *nomProv, *especie, *u_medida;

    arch.peek();
    if(arch.eof()) return NULL;

    char aux[200];
    
    codProv = leerNumero(arch);
    nomProv = leerCadena(arch,',');
    anho = leerNumero(arch);
    especie = leerCadena(arch, ',');
    u_medida = leerCadena(arch,',');

    cantidades = new int[5];
    for(int i=0; i<4; i++){
        arch>>cantidades[i];
        arch.get();
    }
    // Cosas raras si se pone en el for
    arch>>cantidades[4];
    arch.getline(aux, 200);


    extraccion = new void*[5];
    extraccion[CODIGO] = codProv;
    extraccion[PROVINCIA] = nomProv;
    extraccion[ANHO] = anho;
    extraccion[ESPECIE] = especie;
    extraccion[CANTIDADES] = cantidades;
    return extraccion;
}

int *leerNumero(ifstream &arch){
    int *numero;
    numero = new int;
    arch>>*numero;
    arch.get();
    return numero;
}

void imprimirExtracciones(void *ext, int N){
    ofstream arch("ReporteExtracciones.txt", ios::out);
    if(!arch){
        cout<<"Error al abrir ReporteExtracciones.txt"<<endl;
        exit(1);
    }
    void **extracciones = (void **) ext;

    arch<<"       EXTRACCIONES FORESTALES POR ANHO Y PROVINCIA (TONELADAS)"<<endl;
    
    int codProvAnt = -1, codProv;
    for(int i=0; i<N; i++){
        codProv = obtenerProv(extracciones[i]);
        if(codProv != codProvAnt) imprimirEncabezado(arch, extracciones[i]);
        imprimirExtraccion(arch, extracciones[i]);
        codProvAnt = codProv;
    }
}

void imprimirEncabezado(ofstream &arch, void *ext){
    void **extraccion = (void**) ext;
    int *codigo = (int*)extraccion[CODIGO];
    char *nombre = (char *)extraccion[PROVINCIA];
    int *anho = (int *)extraccion[ANHO];
    
    impLinea(arch, MAX_LINEA, '=');
    arch<<"ANHO: "<<left<<setw(40)<<*anho
        <<"PROVINCIA ";
    arch.fill('0');
    arch<<right<<setw(2)<<*codigo<<": ";
    arch.fill(' ');
    arch<<left<<setw(20)<<nombre<<endl;

    impLinea(arch, MAX_LINEA, '-');
    arch<<"  ESPECIE      TIPO-R    TIPO-C    TIPO-L    TIPO-P    TIPO-D"<<endl;
    
}

void imprimirExtraccion(ofstream &arch, void *ext){
    void **extraccion = (void**) ext;
    
    char *especie = (char *)extraccion[ESPECIE];
    int *cantidades = (int *)extraccion[CANTIDADES];
    
    arch<<setw(15)<<especie;
    for(int i=0; i<5; i++){
        arch<<setw(10)<<cantidades[i];
    }
    arch<<endl;
}

int obtenerProv(void *ext){
    void **extraccion = (void**) ext;
    int *codigo = (int*)extraccion[CODIGO];
    return *codigo;
}