#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include <cstdlib>
#include <cstring>
#include "funciones.h"

enum Curso {CODIGO, NOMBRE, CREDITOS, REQUISITOS};

void leeCursosV(void *&cur){
    ifstream archR("Requisitos.csv",ios::in);
    if(!archR){
        cout<<"Error al abrir Requisitos.csv"<<endl;
        exit(1);
    }
    ifstream archC("Cursos.csv", ios::in);
    if(!archC){
        cout<<"Error al abrir Cursos.csv"<<endl;
        exit(1);
    }

    void *buff[100], *curso, **cursos;
    int numDat = 0;
    while(1){
        curso = leeCurso(archC, archR);
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

void *leeCurso(ifstream &archC, ifstream &archR){
    void **curso;
    char *codigo;
    double *creditos;

    codigo = leeCadLine(archC);
    if(archC.eof()) return NULL;
    curso = new void*[4];
    curso[CODIGO] = codigo;
    curso[NOMBRE] = leeCadLine(archC);
    creditos = new double;
    archC>>*creditos;
    curso[CREDITOS] = creditos;
    archC>>ws;
    curso[REQUISITOS] = leeRequisitos(codigo, archR);
    return curso;
}

char *leeCadLine(ifstream &arch){
    char buff[100], *cad;
    arch.getline(buff, 100,',');
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void *leeRequisitos(char* codigo, ifstream& archR){
    char *buff[10], *req, *cod, *newReq;
    void **requisitos;
    int numReq = 0;
    archR.seekg(0,ios::beg);
    //cout<<"Buscamos requisitos de "<<codigo<<endl;
    while(1){
        cod = leeCodigo(archR);
        if(archR.eof()){
            archR.clear();
            break;
        }
        archR.get();        // Salta coma
        req = leeCodigo(archR);
        archR>>ws;          // Salta enter
        if(strcmp(cod, codigo)==0){
            // Nueva variable para guardar el requisito
            newReq = new char[7];
            strcpy(newReq, req);
            //cout<<"Curso: "<<codigo<<" Req: "<<newReq<<endl;
            buff[numReq] = newReq;
            numReq++;
        }
        delete [] req;
        delete [] cod;
    }
    if(numReq ==0) return NULL;
    requisitos = new void*[numReq+1];
    for(int i=0; i<numReq; i++)
        requisitos[i] = buff[i];
    //cout<<(char*)requisitos[0]<<endl;
    requisitos[numReq] = NULL;
    return requisitos;
}

void imprimirCursosV(void*cur){
    ofstream arch("Reporte.txt",ios::out);
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

char *leeCodigo(ifstream &arch){
    char *cad;
    cad = new char[7];
    arch.get(cad, 7);
    return cad;
}