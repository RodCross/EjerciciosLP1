#include <iostream>
#include "EntidadReguladora.h"
#include <fstream>
using namespace std;

int main() {
    EntidadReguladora entReg;
    
    entReg.crear("Conductores.csv", "Infracciones.csv");
    entReg.leerInfracciones("Registro_de_Faltas.csv");
    entReg.emitirMultasAcumuladas("Datos.txt", "Reporte.txt");
    
    return 0;
}
