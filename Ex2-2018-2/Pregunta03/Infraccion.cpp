#include "Infraccion.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

Infraccion::Infraccion() {
    descripcion = gravedad = NULL;
}

Infraccion::~Infraccion() {
    if (descripcion) delete[] descripcion;
    if (gravedad) delete[] gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(const char* g) {
    if (gravedad) delete[] gravedad;
    gravedad = new char[strlen(g) + 1];
    strcpy(gravedad, g);
}

void Infraccion::GetGravedad(char*g) const {
    strcpy(g, gravedad);
}

void Infraccion::SetDescripcion(const char* d) {
    if (descripcion) delete[] descripcion;
    descripcion = new char[strlen(d) + 1];
    strcpy(descripcion, d);
}

void Infraccion::GetDescripcion(char*d) const {
    strcpy(d, descripcion);
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::operator =(const Infraccion& inf) {
    char buff[500];
    
    SetCodigo(inf.GetCodigo());
    SetMulta(inf.GetMulta());
    inf.GetDescripcion(buff);
    SetDescripcion(buff);
    inf.GetGravedad(buff);
    SetGravedad(buff);
}

bool Infraccion::operator==(int cod) {
    return GetCodigo() == cod;
}

bool Infraccion::operator >(const Infraccion& inf) {
    return GetCodigo() > inf.GetCodigo();
}

double Infraccion::obtenerCosto() {
    return GetMulta();
}

void operator >>(ifstream &in, Infraccion &inf) {
    int cod;
    double mul;
    char buff[500];
    
    in >> cod;
    if (in.eof()) return;
    in.get(); // lee la comita
    in.getline(buff, 500, ',');
    inf.SetDescripcion(buff);
    in.getline(buff, 500, ',');
    inf.SetGravedad(buff);
    in >> mul;
    in.get(); // lee la comita
    
    inf.SetCodigo(cod);
    inf.SetMulta(mul);
}

ofstream &operator <<(ofstream &out, const Infraccion &inf) {
    char buff[500];
    
    out << left << setw(6) << inf.GetCodigo();
    inf.GetDescripcion(buff);
    out << setw(200) << buff;
    inf.GetGravedad(buff);
    out << setw(10) << buff
        << right << setw(8) << inf.GetMulta();
    
    return out;
}