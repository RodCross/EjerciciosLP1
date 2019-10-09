#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include <cstring>

#include "FuncionesPreg01Ex01.h"
#define CODE_LEN 6
#define MAX_LINEA 128

enum {CODIGO, NOMBRE, REQUISITOS};

void leerCursos(char ***& cursos){
    ifstream arch("PlanDeEstudiosYNotas.csv", ios::in);
    if(!arch){
        cout<<"Error: No se pudo abrir PlanDeEstudiosYNotas.csv"<<endl;
        exit(1);
    }
    char c, **buff[200];
    int numCur = 0;
    while(1){
        c = arch.get();
        if(c == '\n') break;    // Verifico el fin de la primera parte del arch
        arch.unget();
        buff[numCur] = leeCurso(arch);
        numCur++;
    }
    cursos = new char**[numCur+1];
    for(int i=0; i<numCur; i++){
        cursos[i] = buff[i];
    }
    cursos[numCur] = NULL;
}

char** leeCurso(ifstream &arch){
    char *buffCurso[50], **curso, c;
    int numReq = 0, datos = 2;

    buffCurso[CODIGO] = leeCodigo(arch);    // Deja la coma en el buffer
    arch.get();
    buffCurso[NOMBRE] = leeNombre(arch);    // Deja la coma en el buffer
    while(1){       // Se leen los requisitos, si es que hubiera
        c = arch.get();
        if(c == '\n') break;        // No hay mas
        if(c == ','){
            buffCurso[REQUISITOS+numReq] = leeCodigo(arch);
            numReq++;    
        }
        else{
            cout<<"Error "<<c;
            exit(1);
        }
    }
    
    datos += numReq;
    curso = new char*[datos+1];
    for(int i=0; i<datos; i++){
        curso[i] = buffCurso[i];
    }
    curso[datos] = NULL;
    return curso;
}

char *leeCodigo(ifstream &arch){
    char *codigo;
    codigo = new char[CODE_LEN+1];
    arch.get(codigo, CODE_LEN+1, ',');
    return codigo;
}

char *leeNombre(ifstream &arch){
    // Le puede seguir una coma o un enter
    char buff[100], c, *nombre;
    int n=0;
    while(1){
        c = arch.peek();
        if(c=='\n' || c==',') break;
        arch.get();
        buff[n] = c;
        n++;
    }
    nombre = new char[n+1];
    for(int i=0; i<n; i++){
        nombre[i] = buff[i];
    }
    nombre[n] = 0;
    return nombre;
}

void imprimirCursos(char *** cursos){
    ofstream arch("PlanDeEstudios.txt", ios::out);
    if(!arch){
        cout<<"Error al abrir PlanDeEstudios.txt"<<endl;
        exit(1);
    }
    arch<<setw(70)<<right<<"PLAN DE ESTUDIOS"<<endl;
    impLinea(arch, '=', MAX_LINEA);
    arch<<"   CODIGO     CURSO                                                 REQUISITOS"<<endl;
    impLinea(arch, '=', MAX_LINEA);

    for(int i=0; cursos[i]; i++)
        imprimirCurso(arch,i+1,cursos[i], cursos);
}

void imprimirCurso(ofstream &arch, int num, char**curso, char ***cursos){
    arch<<right<<setw(2)<<num<<") ";
    arch<<left<<setw(10)<<curso[CODIGO];
    arch<<setw(55)<<curso[NOMBRE];
    int tab = 2+12+55;
    bool conTab = false;
    char *nombreReq;

    for(int i=0; curso[REQUISITOS+i]; i++){
        if(conTab)
            arch<<setw(tab)<<"";
        nombreReq = obtenerNombre(curso[REQUISITOS+i], cursos);
        arch<<i+1<<") "<<setw(50)<<nombreReq<<curso[REQUISITOS+i]<<endl;
        conTab = true;
    }
    if(curso[REQUISITOS] == NULL) arch<<endl;
    impLinea(arch, '-', MAX_LINEA);
}

void impLinea(ofstream &arch, char a, int n){
    for(int i=0; i<n; i++){
        arch.put(a);
    }
    arch<<endl;
}

char* obtenerNombre(char *codigo, char***cursos){
    char *nombre;
    int i=0;
    while(cursos[i]){
        if(compararCod(cursos[i],codigo)) break;
        i++;
    }
    return cursos[i][NOMBRE];
}

bool compararCod(char **curso, char *codigo){
    if(strcmp(curso[CODIGO], codigo)==0) return true;
    return false;
}