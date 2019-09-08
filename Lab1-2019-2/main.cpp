/* 
 * Archivo:   main.cpp
 * Autor:     Rodrigo Alonso Cruz Leán
 * Código:    20170516
 *
 * Creado el 6 de septiembre de 2019, 08:07 AM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "FuncAux.h"
using namespace std;

#define MAX_CAR_LIN 110
#define MAX_CAD_NOM 50

int main() {
    int codCuenta;
    int dd, mm, aaaa;
    int numRet, numDep;
    int numCar, numBlanc; // para el formato del reporte
    
    double valorUsd, valorEur; // para monedas extranjeras
    double saldoCuenta;
    double montoMov;
    double sumaRet, sumaDep, totalRet, totalDep;
    
    char c; // caracter auxiliar
    char monedaCuenta; // moneda de la cuenta
    char tipoMov; // tipo del movimiento (depósito o retiro)
    char monedaMov; // moneda del movimiento
    
    bool bajoMinimo, sobregiro, nuevoCliente;
    
    // se leen valores de monedas extranjeras
    cin >> valorUsd >> valorEur;
    
    // impresión de título
    cout << "ESTADO DE CUENTAS DEL BANCO ABCD";
    cout.precision(2);
    cout << fixed;
    
    // lectura de cuentas
    while(1) {
        if(cin.eof()) break;

        numCar = 0;
        numRet = numDep = 0;
        totalRet = totalDep = 0;
        nuevoCliente = false;
        
        // encabezado de cuenta
        cout << endl;
        for(int i = 0; i < MAX_CAR_LIN; i++) cout.put('=');
        cout << endl;
        cout << "CLIENTE" << setw(61) << "CODIGO DE CUENTA" << setw(12)
            << "MONEDA" << setw(25) << "SALDO INICIAL" << endl;
        
        while(!(cin >> codCuenta)) {
            // si entra aqui, es porque no se pudo leer la cuenta
            cin.clear();
            c = cin.get();
            cout.put(c); // imprimir el caracter en mayusculas
            numCar++;
            while((c = cin.get()) != ' ') {
                cout.put(tolower(c));
                numCar++;
            }
            cout.put(c); // imprime espacio
            numCar++;
        }
        
        // al salir, ya se leyó la cuenta
        // se completa con espacios
        numBlanc = MAX_CAD_NOM - numCar;
        for(int i = 0; i < numBlanc; i++) cout.put(' ');
        cout << setw(13) << codCuenta; // se imprime la cuenta
        
        // se imprime la moneda
        cin >> monedaCuenta >> saldoCuenta;
        cout << setw(11) << " ";
        if(monedaCuenta == 'S') cout << "Soles";
        else if(monedaCuenta == '$') cout << "Dolar";
        else if(monedaCuenta == '&') cout << "Euros";
        
        cout << setw(15) << monedaCuenta << setw(9) << saldoCuenta << endl;
        for(int i = 0; i < MAX_CAR_LIN; i++) cout.put('=');
        cout << endl;
        
        // encabezado de depósitos y retiros
        cout << left;
        if(monedaCuenta == 'S') {
            cout << "FECHA" << setw(13) << " " << setw(23) << "RETIROS SOLES" << setw(29)
                << "DEPOSITOS SOLES" << setw(26) << "SALDO SOLES" << "OBSERVACION";
        }
        else if(monedaCuenta == '$') {
            cout << "FECHA" << setw(13) << " " << setw(23) << "RETIROS DOLARES" << setw(29)
                << "DEPOSITOS DOLARES" << setw(26) << "SALDO DOLARES" << "OBSERVACION";
        }
        else if(monedaCuenta == '&') {
            cout << "FECHA" << setw(13) << " " << setw(23) << "RETIROS EUROS" << setw(29)
                << "DEPOSITOS EUROS" << setw(26) << "SALDO EUROS" << "OBSERVACION";
        }
        cout << right << endl;
        for(int i = 0; i < MAX_CAR_LIN; i++) cout.put('-');
        cout << endl;
        
        // lectura de depósitos y retiros
        while(1) {
            if(cin.eof()) break;
            if(nuevoCliente) break;

            sumaRet = sumaDep = 0;
            
            // lectura e impresión de la fecha
            cin >> dd >> c >> mm >> c >> aaaa;
            cout.fill('0');
            cout << setw(2) << dd << "/" << setw(2) << mm << "/" << setw(4) << aaaa;
            cout.fill(' ');
            
            // se lee el tipo del movimiento
            cin >> tipoMov;
            while(1) {
                if(!(cin >> monedaMov)) {
                    break;                    
                }
                if(monedaMov != 'S' && monedaMov != '$' && monedaMov != '&') {
                    if(monedaMov == 'D' || monedaMov == 'R') {
                        tipoMov = monedaMov;
                    }
                    else {
                        cin.unget();
                        break;
                    }
                }
                else {
                    cin >> montoMov;
                    
                    // convirtiendo monto original a moneda de la cuenta
                    montoMov = convertirMoneda(monedaMov, monedaCuenta, montoMov,
                        valorUsd, valorEur);
                    
                    if(tipoMov == 'D') {
                        saldoCuenta += montoMov;
                        sumaDep += montoMov;
                        numDep++;
                    }
                    else {
                        saldoCuenta -= montoMov;
                        sumaRet += montoMov;
                        numRet++;
                    }

                    // verifica los dos saltos de línea
                    if(cin.peek() == '\n') {
                        cin.get();
                        if(cin.peek() == '\n') {
                            cin.get();
                            nuevoCliente = true;
                            break;
                        }
                    }
                }
            }
            
            totalRet += sumaRet;
            totalDep += sumaDep;
            
            cout << setw(9) << monedaCuenta << setw(11) << sumaRet << setw(15)
                << monedaCuenta << setw(11) << sumaDep << setw(14) << monedaCuenta
                << setw(11) << saldoCuenta;
            
            // observación
                if(saldoCuenta < 0) {
                    sobregiro = true;
                }
                else if(saldoCuenta < convertirMoneda('$', monedaCuenta, 1000, valorUsd, valorEur)) {
                    sobregiro = false;
                    bajoMinimo = true;
                }
                else {
                    sobregiro = false;
                    bajoMinimo = false;
                }
            
            if(sobregiro) cout << setw(24) << "SOBREGIRO";
            else if(bajoMinimo) cout << setw(29) << "BAJO EL MINIMO";
            cout << endl;
        }
        
        // impresión del resumen
        for(int i = 0; i < MAX_CAR_LIN; i++) cout.put('=');
        cout << endl;
        cout << "RESUMEN:" << endl;
        cout << "CANTIDAD TOTAL DE RETIROS:" << setw(8) << numRet << setw(30)
            << "TOTAL DE RETIROS:" << setw(5) << monedaCuenta << setw(11) << totalRet << endl;
        cout << "CANTIDAD TOTAL DE DEPOSITOS:" << setw(6) << numDep << setw(30)
            << "TOTAL DE DEPOSITOS:" << setw(5) << monedaCuenta << setw(11) << totalDep << endl;
        cout << "SALDO FINAL:" << setw(5) << monedaCuenta << setw(11) << saldoCuenta
            << setw(36) << "OBSERVACION FINAL:" << setw(4) << " ";

        // observación final
        if(saldoCuenta < 0) {
            cout << "CUENTA EN SOBREGIRO";
        }
        else if(saldoCuenta < convertirMoneda('$', monedaCuenta, 1000, valorUsd, valorEur)) {
            cout << "CUENTA BAJO EL MINIMO";
        }
    }

    return 0;
}