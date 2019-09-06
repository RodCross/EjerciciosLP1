#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;
#define MAX_CAR_LIN 133
#define MAX_CAD_PROV 32

int main() {
    ifstream archDatos("superficie_incendios.txt", ios::in);
    if(!archDatos) {
        cout << "Error: no se pudo abrir el archivo datos.txt" << endl;
        exit(EXIT_FAILURE);
    }
    ofstream archRep("reporte.txt", ios::out);
    if(!archRep) {
        cout << "Error: no se pudo abrir el archivo reporte.txt" << endl;
        exit(EXIT_FAILURE);
    }

    archRep.precision(2);
    archRep << fixed;

    int num = 1; // contador
    int anio, totalAnios, menorAnio, mayorAnio; // años
    int numCar; // número de caracteres de la provincia
    int numBlanc; // variable para el formato

    double superficie; // superficie auxiliar
    double supN, supC, supM, supP, supI, supSuma; // superficies de cada vegetación
    double menorSup, mayorSup; // para comparación de superficies
    double totalN, totalC, totalM, totalP, totalI, totalGen; // totales
    double menorTotal, mayorTotal; // para comparación de totales
    double promSup; // promedio de superficies

    char menorCategoria, mayorCategoria; // para resumen histórico
    char c; // carácter auxiliar
    char unidad; // para unidad de medida

    bool primerDato;

    // título del reporte
    archRep << setw(104) << "REPORTE DE HECTAREAS AFECTADAS POR INCENDIOS FORESTALES EN ARGENTINA";

    while(1) {
        numCar = 0;
        totalAnios = 0;
        primerDato = true;
        totalN = totalC = totalM = totalP = totalI = totalGen = 0;

        archDatos.peek();
        if(archDatos.eof()) break;

        // encabezado de provincia
        archRep << endl;
        for(int i = 0; i < MAX_CAR_LIN; i++) {
            archRep.put('=');
        }
        archRep << "\nN°" << setw(12) << "PROVINCIA" << setw(29) << "AÑO" << setw(14) << "TOTAL"
            << setw(16) << "B.NATIVO" << setw(17) << "B.CULTIVABLE" << setw(14) << "MATORRAL"
            << setw(14) << "PASTIZAL" << setw(16) << "NO DETERMIN" << endl;
        for(int i = 0; i < MAX_CAR_LIN; i++) {
            archRep.put('-');
        }
        archRep << endl;

        archRep.fill('0');
        archRep << setw(2) << num++;
        archRep.fill(' ');
        archRep << setw(3) << " ";

        while(!(archDatos >> anio)) {
            // si se entra a esta parte, no se pudo leer el año
            archDatos.clear();

            c = archDatos.get();
            archRep.put(c); // imprime en mayúsculas
            numCar++;
            while((c = archDatos.get()) != ' ') {
                archRep.put(tolower(c)); // imprime en minúsculas
                numCar++;
            }
            archRep.put(c); // pone un espacio
            numCar++;
        }
        
        // se leyó el año
        totalAnios++;

        numBlanc = MAX_CAD_PROV - numCar;
        for(int i = 0; i < numBlanc; i++) {
            archRep.put(' ');
        }
        archRep << setw(6) << anio;

        while(1) {
            // lectura de la vegetación afectada
            for(int i = 0; i < 5; i++) {
                // verificar si hay datos
                archDatos >> c;
                if(isalpha(archDatos.peek())) {
                    unidad = archDatos.get();
                    superficie = 0.0;
                }
                else {
                    archDatos >> superficie >> unidad;

                    // se convierte todo a hectáreas
                    if(unidad == 'f') {
                        superficie /= 0.39;
                    }
                    else if(unidad == 'k') {
                        superficie /= 100;
                    }
                }

                // se asigna el valor a la superficie correspondiente
                if(c == 'N') {
                    supN = superficie;
                    totalN += supN;
                }
                else if(c == 'C') {
                    supC = superficie;
                    totalC += supC;
                }
                else if(c == 'M') {
                    supM = superficie;
                    totalM += supM;
                }
                else if(c == 'P') {
                    supP = superficie;
                    totalP += supP;
                }
                else if(c == 'I') {
                    supI = superficie;
                    totalI += supI;
                }

                // se compara con las superficies mayor y menor
                if(primerDato) {
                    menorSup = mayorSup = superficie;
                    mayorAnio = menorAnio = anio;
                    primerDato = false;
                }
                else {
                    if(superficie > mayorSup) {
                        mayorSup = superficie;
                        mayorAnio = anio;
                    }
                    else if(superficie < menorSup) {
                        menorSup = superficie;
                        menorAnio = anio;
                    }
                }
            }

            supSuma = supN + supC + supM + supP + supI;
            totalGen += supSuma;

            // impresión de las superficies
            archRep << setw(13) << supSuma << setw(15) << supN << setw(15)
                << supC << setw(15) << supM << setw(15) << supP << setw(15)
                << supI << endl;

            if(archDatos >> anio) {
                archRep << setw(43) << anio;
                totalAnios++;
            }
            else {
                // cálculo del promedio de superficies
                promSup = totalGen / totalAnios;

                // cálculo de los totales menor y mayor
                // se asume a la categoría N como menor y mayor
                menorTotal = mayorTotal = totalN;
                menorCategoria = mayorCategoria = 'N';
                // se compara en el orden N - C - M - P - I
                if(totalC > mayorTotal) {
                    mayorTotal = totalC;
                    mayorCategoria = 'C';
                }
                else if(totalC < menorTotal) {
                    menorTotal = totalC;
                    menorCategoria = 'C';
                }
                if(totalM > mayorTotal) {
                    mayorTotal = totalM;
                    mayorCategoria = 'M';
                }
                else if(totalM < menorTotal) {
                    menorTotal = totalM;
                    menorCategoria = 'M';
                }
                if(totalP > mayorTotal) {
                    mayorTotal = totalP;
                    mayorCategoria = 'P';
                }
                else if(totalP < menorTotal) {
                    menorTotal = totalP;
                    menorCategoria = 'P';
                }
                if(totalI > mayorTotal) {
                    mayorTotal = totalI;
                    mayorCategoria = 'I';
                }
                else if(totalI < menorTotal) {
                    menorTotal = totalI;
                    menorCategoria = 'I';
                }

                // impresión del resumen
                archRep << setw(5) << " "; // espacios
                for(int i = 0; i < MAX_CAR_LIN - 5; i++) archRep.put('-');

                archRep << endl << setw(5) << " "; // salto de línea y espacios
                archRep << "Subtotales" << setw(41) << totalGen << setw(15)
                    << totalN << setw(15) << totalC << setw(15) << totalM
                    << setw(15) << totalP << setw(15) << totalI << endl
                    << setw(5) << " ";

                for(int i = 0; i < MAX_CAR_LIN - 5; i++) archRep.put('-');
                archRep << endl << setw(5) << " ";
                archRep << "Años registrados = " << totalAnios;
                archRep << endl << setw(5) << " ";
                archRep << "Año con menor superficie total afectada = " << menorAnio;
                archRep << endl << setw(5) << " ";
                archRep << "Año con mayor superficie total afectada = " << mayorAnio;
                archRep << endl << setw(5) << " ";
                archRep << "Promedio de superficie total afectada anual = " << promSup << " ha";
                archRep << endl << endl;

                archRep << "Resumen histórico";
                for(int i = 0; i < MAX_CAR_LIN - 17; i++) archRep.put('-');
                archRep << endl;
                archRep << "Total de superficie afectada = " << totalGen << " ha" << endl;

                archRep.precision(3);

                archRep << "Tipo de vegetación con menor superficie afectada = ";
                if(menorCategoria == 'N') archRep << setw(12) << "B.NATIVO";
                else if(menorCategoria == 'C') archRep << left << setw(12) << "B.CULTIVABLE";
                else if(menorCategoria == 'M') archRep << left << setw(12) << "MATORRAL";
                else if(menorCategoria == 'P') archRep << left << setw(12) << "PASTIZAL";
                else if(menorCategoria == 'I') archRep << left << setw(12) << "NO DETERMIN";
                archRep << " (" << right << setw(6) << menorTotal / totalGen * 100
                    << "% del total)" << endl;

                archRep << "Tipo de vegetación con mayor superficie afectada = ";
                if(mayorCategoria == 'N') archRep << left << setw(12) << "B.NATIVO";
                else if(mayorCategoria == 'C') archRep << left << setw(12) << "B.CULTIVABLE";
                else if(mayorCategoria == 'M') archRep << left << setw(12) << "MATORRAL";
                else if(mayorCategoria == 'P') archRep << left << setw(12) << "PASTIZAL";
                else if(mayorCategoria == 'I') archRep << left << setw(12) << "NO DETERMIN";
                archRep << " (" << right << setw(6) << mayorTotal / totalGen * 100
                    << "% del total)" << endl;

                archRep.precision(2);

                break;
            }
        }

    }

    return 0;
}