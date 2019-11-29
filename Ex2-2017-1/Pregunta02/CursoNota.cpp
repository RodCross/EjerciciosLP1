#include "CursoNota.h"
#include <cstring>
#include <iostream>
#include <iomanip>

CursoNota::CursoNota() {
    codigo = NULL;
}

CursoNota::~CursoNota() {
    if (codigo) delete[] codigo;
}

void CursoNota::SetNota(int nota) {
    this->nota = nota;
}

int CursoNota::GetNota() const {
    return nota;
}

void CursoNota::SetCodigo(const char* cod) {
    if (codigo) delete[] codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void CursoNota::GetCodigo(char* cod) const {
    strcpy(cod, codigo);
}

void CursoNota::leer(ifstream &arch) {
    char cod[10];
    int n;
    
    arch.getline(cod, 10, ',');
    arch >> n;
    arch.get(); // sacar la coma
    
    SetCodigo(cod);
    SetNota(n);
}

void CursoNota::imprimir(ofstream &arch) {
    char cod[10];
    
    GetCodigo(cod);
    
    arch << left << setw(10) << cod
         << right << setw(2) << GetNota() << endl;
}
