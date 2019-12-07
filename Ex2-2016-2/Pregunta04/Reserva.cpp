#include "Reserva.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;

Reserva::Reserva() {
    atencion = devolucion = solicitud = NULL;
}

Reserva::~Reserva() {
    if (atencion) delete[] atencion;
    if (devolucion) delete[] devolucion;
    if (solicitud) delete[] solicitud;
}

void Reserva::SetAtencion(const char *at) {
    if (atencion) delete[] atencion;
    atencion = new char[strlen(at) + 1];
    strcpy(atencion, at);
}

void Reserva::GetAtencion(char *at) const {
//    std::cout << strlen(atencion) << "->" << atencion << "   ";
    strcpy(at, atencion);
}

void Reserva::SetDevolucion(const char *dev) {
    if (devolucion) delete[] devolucion;
    devolucion = new char[strlen(dev) + 1];
    strcpy(devolucion, dev);
}

void Reserva::GetDevolucion(char *dev) const {
//    std::cout << strlen(devolucion) << "->" << devolucion << std::endl;
    strcpy(dev, devolucion);
}

void Reserva::SetSolicitud(const char *sol) {
    if (solicitud) delete[] solicitud;
    solicitud = new char[strlen(sol) + 1];
    strcpy(solicitud, sol);
}

void Reserva::GetSolicitud(char *sol) const {
//    std::cout << strlen(solicitud) << "->" << solicitud << "   ";
    strcpy(sol, solicitud);
}

void Reserva::SetEstado(int e) {
    estado = e;
}

int Reserva::GetEstado() const {
    return estado;
}

void Reserva::leer(ifstream &arch) {
    int est;
    char fSol[15], fAt[15], fDev[15];
    
    arch.getline(fSol, 15, ',');
    arch.getline(fAt, 15, ',');
    
    arch.getline(fDev, 15, ',');
    arch >> est;
    arch.get();
    
    SetSolicitud(fSol);
    SetAtencion(fAt);
    SetDevolucion(fDev);
    SetEstado(est);
}

void Reserva::imprimir(ofstream &arch) {
    char fSol[15], fAt[15], fDev[15];
    int est;
    
    GetSolicitud(fSol);
    GetAtencion(fAt);
    GetDevolucion(fDev);
    est = GetEstado();
    
    arch << left << setw(16) << fSol
        << setw(16) << fAt
        << setw(20) << fDev;
    
    if (est == 1) arch << "A tiempo";
    else if (est == 2) arch << "Fuera de tiempo";
    else if (est == 3) arch << "En atencion";
    arch << endl;
}

void Reserva::convertirFecha(char *fecha) {
    int i, j;
    char dia[3], mes[3], anio[5];
    
    for (i = 0, j = 0; j < 2; i++, j++) dia[i] = fecha[j];
    dia[i] = 0;
    for (i = 0, j = 3; j < 5; i++, j++) mes[i] = fecha[j];
    mes[i] = 0;
    for (i = 0, j = 6; j < 10; i++, j++) anio[i] = fecha[j];
    anio[i] = 0;
    
    strcpy(fecha, anio);
    strcat(fecha, mes);
    strcat(fecha, dia);
}

bool Reserva::operator <(const Reserva &res) {
    char fecha1[15], fecha2[15];
    
    GetAtencion(fecha1);
    res.GetAtencion(fecha2);
    
    convertirFecha(fecha1);
    convertirFecha(fecha2);
    
    return strcmp(fecha1, fecha2) < 0;
}
