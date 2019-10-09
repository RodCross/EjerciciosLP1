#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include <cstring>

#include "FuncionesPreg01Ex01.h"
#include "FuncionesPreg02Ex01.h"
#define MAX_LINEA 65
#define INCREMENTO 5
#define NOTA_APROB 11

void leerNotas(int *& alumnos, char ***&cursosAprob){
    ifstream arch("Notas.csv", ios::in);
    if(!arch){
        cout<<"Error al abrir el archivo Notas.csv"<<endl;
        exit(1);
    }

    int alumno, nota, cant, cap;
    char aux[50];
    // Lectura de alumnos
    cant = cap = 0;
    alumnos = NULL;
    while(1){
        arch>>alumno;
        if(arch.eof()||arch.peek()=='\n'){
            arch.clear();
            break;
        }
        arch.get();
        if(nuevoAlumno(alumnos,cant,alumno)){
            if(cant == cap) incrementarEsp(alumnos, cant, cap);
            alumnos[cant] = -1;
            alumnos[cant-1] = alumno;
            cant++;
        }
        arch.getline(aux,50);
    }
    // Lectura de notas
    cursosAprob = new char**[cant+1];
    for(int i=0; i<cant+1; i++)
        cursosAprob[i] = NULL;
    for(int i=0; i<cant; i++){
        buscarCurAprob(arch,alumnos[i],cursosAprob[i]);
    }
}

bool nuevoAlumno(int *alumnos,int cant, int alumno){
    for(int i=0; i<cant; i++){
        if(alumnos[i]==alumno) return false;
    }
    return true;
}

void buscarCurAprob(ifstream &arch, int alumno, char**&cursosAprob){
    int aux, cant, cap;
    char *codigo, salto[50];
    
    arch.seekg(0,ios::beg);
    cant = cap = 0;
    while(1){
        arch>>aux;
        if(arch.eof()){
            arch.clear();
            break;
        }
        if(aux == alumno){
            arch.get();
            codigo = leeCodigo(arch);
            arch.get();
            arch>>aux;
            if(aux>=NOTA_APROB){ 
                if(cant==cap) incrementarEspChar(cursosAprob, cant, cap);
                cursosAprob[cant] = NULL;
                cursosAprob[cant-1] = codigo;
                cant++;
            }
            else{
                delete[] codigo;
            }
        }
        arch.getline(salto,50);
    }
}

void incrementarEsp(int *&datos, int &cant, int &cap){
    int *nuevo;
    cap += INCREMENTO;
    if(datos == NULL){
        datos = new int [cap];
        datos[0] = -1;
        cant++;
    }
    else{
        nuevo = new int [cap];
        for(int i=0; i<cant; i++)
            nuevo[i] = datos[i];
        delete[] datos;
        datos = nuevo;
    }
}

void incrementarEspChar(char **&datos, int &cant, int &cap){
    char **nuevo;
    cap += INCREMENTO;
    if(datos == NULL){
        datos = new char*[cap];
        datos[0] = NULL;
        cant++;
    }
    else{
        nuevo = new char*[cap];
        for(int i=0; i<cant; i++)
            nuevo[i] = datos[i];
        delete[] datos;
        datos = nuevo;
    }
}

void imprimirAprobados(int *alumnos, char ***cursosAprob){
    ofstream arch("CursosAprobados.txt", ios::out);
    if(!arch){
        cout<<"Error al abrir CursosAprobados.txt"<<endl;
        exit(1);
    }
    arch<<"               CURSOS APROBADOS POR LOS ALUMNOS"<<endl;
    impLinea(arch, '=', MAX_LINEA);
    arch<<"CODIGO                           CURSO APROBADO"<<endl;
    impLinea(arch, '=', MAX_LINEA);

    for(int i=0; alumnos[i]!=-1; i++){
        arch<<right<<setw(2)<<i+1<<") "<<alumnos[i];
        imprimirCurAprob(arch,cursosAprob[i]);
        impLinea(arch, '-', MAX_LINEA);
    }
}

void imprimirCurAprob(ofstream& arch, char**cursosAprob){
    for(int i=0; cursosAprob[i]; i++){
        if(i%3 == 0){
            arch<<endl;
            arch<<setw(15)<<"";
        }
        arch<<right<<setw(2)<<i+1<<") "<<left<<setw(15)<<cursosAprob[i];
    }
    arch<<endl;
}