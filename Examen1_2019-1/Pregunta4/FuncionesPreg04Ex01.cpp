#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include <cstdlib>
#include <cstring>
#include "FuncionesPreg04Ex01.h"

enum Curso {CODIGO, NOMBRE, CREDITOS, REQUISITOS};

void leeCursosV(void *&cur){
    ifstream arch("PlanDeEstudiosYNotasPreg4.csv",ios::in);
    if(!arch){
        cout<<"Error al abrir PlanDeEstudiosYNotasPreg4.csv"<<endl;
        exit(1);
    }
    void *buff[100], *curso, **cursos;
    int numDat = 0;
    while(1){
        curso = leeCurso(arch);
        if(curso == NULL) break;
        buff[numDat] = curso;
        numDat++;
    }
    cursos = new void* [numDat+1];
    for(int i=0; i<numDat; i++){
        cursos[i] = buff[i];
    }
    cursos[numDat] = NULL;
    cur = cursos;
}

void *leeCurso(ifstream &arch){
    void **curso;
    char *cur;
    double *creditos;
    cur = leeCadLine(arch);
    if(arch.eof()) return NULL;
    curso = new void*[4];
    curso[CODIGO] = cur;
    curso[NOMBRE] = leeCadLine(arch);
    creditos = new double;
    arch>>*creditos;
    curso[CREDITOS] = creditos;
    curso[REQUISITOS] = leeRequisitos(arch);
    return curso;
}

char *leeCadLine(ifstream &arch){
    char buff[100], *cad;
    arch.getline(buff, 100,',');
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void *leeRequisitos(ifstream&arch){
    char *buff[10], *req;
    void **requisitos;
    int numReq = 0;
    while(1){
        if(arch.get()=='\n') break;
        req = new char[7];
        arch.get(req,7);
        buff[numReq] = req;
        numReq++;
    }
    if(numReq ==0) return NULL;
    requisitos = new void*[numReq+1];
    for(int i=0; i<numReq; i++)
        requisitos[i] = buff[i];
    requisitos[numReq] = NULL;
    return requisitos;
}

void imprimirCursosV(void*cur){
    ofstream arch("ReportePreg4.txt",ios::out);
    if(!arch){
        cout<<"Error: No se pudo abrir ReportePreg4.txt"<<endl;
        exit(1);
    }
    void **cursos = (void**) cur;
    arch.precision(2);
    arch<<fixed;
    for(int i=0; cursos[i]; i++){
        arch<<right<<setw(3)<<i+1<<") ";
        imprimeCur(cursos[i], arch, cur);
    }
}

void imprimeCur(void *cur, ofstream&arch, void*curs){
    void **curso = (void**) cur;
    char *codigo = (char*)curso[CODIGO];
    char *nombre = (char *)(curso[NOMBRE]);
    double *creditos = (double *)(curso[CREDITOS]);
    char **req = (char **)(curso[REQUISITOS]);
    char *requisito;
    arch<<left<<setw(10)<<codigo<<setw(55)<<nombre<<right<<setw(8)<<*creditos;
    
    for(int i=0; req && req[i]; i++){
        if(i!=0) arch<<setw(78)<<"";
        requisito = buscarReq(curs, req[i]);
        arch<<right<<setw(3)<<i+1<<") "
            <<left<<setw(50)<<requisito
            <<" ["<<req[i]<<"] "<<endl;
    }
    arch<<endl;
}

char* buscarReq(void *cur, char*cod){
    void **cursos = (void**) cur;
    void **curso;
    char *codCur, *nombCur;
    for(int i=0; cursos[i]; i++){
        curso = (void**)(cursos[i]);
        codCur = (char*)(curso[CODIGO]);
        if(strcmp(cod,codCur)==0){
            nombCur = (char*)(curso[NOMBRE]);
            return nombCur;
        }
    }
    return NULL;
}