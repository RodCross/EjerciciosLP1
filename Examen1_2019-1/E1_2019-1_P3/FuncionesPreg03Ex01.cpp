#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include <cstring>

#include "FuncionesPreg01Ex01.h"
#include "FuncionesPreg02Ex01.h"
#include "FuncionesPreg03Ex01.h"
#define MAX_LINEA 80

enum {CODIGO, NOMBRE, REQUISITOS};

void cursosMatricula(char ***cursos, int *alumnos, char ***cursosAprob){
    // Funcion para imprimir los cursos en los que los alumnos pueden matricularse
    // Lease:
    //  - Que no este en su lista de cursosAprob
    //  - Todos sus requisitos si lo estan
    ofstream arch("CursosMatriculables.txt",ios::out);
    if(!arch){
        cout<<"Error al abrir el archivo CursosMatriculables.txt"<<endl;
        exit(1);
    }
    char *codigo, *nombre;
    int numAp, numReq;
    bool matricula;
    arch<<"                 CURSOS EN LOS QUE SE PUEDE MATRICULAR UN ALUMNO"<<endl;
    for(int i=0; alumnos[i]!=-1; i++){
        numAp = 0;
        impLinea(arch, '=', MAX_LINEA);
        arch<<"Codigo del alumno: "<<alumnos[i]<<endl;
        impLinea(arch, '-', MAX_LINEA);
        arch<<"CURSOS EN LOS QUE PUEDE MATRICULARSE:"<<endl;
        arch<<"No.   Codigo           Curso"<<endl;
        for(int j=0; cursos[j]; j++){
            // Ver si se puede matricular en el curso
            codigo = cursos[j][CODIGO];
            nombre = cursos[j][NOMBRE];
            numReq = 0;
            if(!estaAprobado(cursosAprob[i], codigo)){
                matricula = true;
                while(cursos[j][REQUISITOS+numReq]){
                    if(estaAprobado(cursosAprob[i], cursos[j][REQUISITOS+numReq]))
                        matricula = true;
                    else{
                        matricula = false;
                        break;
                    }
                    numReq++;
                }
                if(matricula){
                    numAp++;
                    imprimirCursoMat(arch, numAp, codigo, nombre);
                }
            }
        }
    }
}

bool estaAprobado(char**cursosAprob, char* codigo){
    for(int i=0; cursosAprob[i]; i++){
        if(strcmp(cursosAprob[i], codigo)==0) return true;
    }
    return false;
}

void imprimirCursoMat(ofstream &arch, int numAp, char *codigo, char*nombre){
    arch<<right<<setw(2)<<numAp<<".-   "<<setw(16)<<left<<codigo<<nombre<<endl;
}

