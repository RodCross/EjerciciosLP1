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

#define MAX_CAR_LIN 120
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
        bajoMinimo = sobregiro = false;
        
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
        if(monedaCuenta == 'S') {
            cout << "FECHA" << setw(25) << "RETIROS SOLES" << setw(25)
                << "DEPOSITOS SOLES" << setw(25) << "SALDO SOLES"
                << setw(25) << "OBSERVACION";
        }
        else if(monedaCuenta == '$') {
            cout << "FECHA" << setw(25) << "RETIROS DOLARES" << setw(25)
                << "DEPOSITOS DOLARES" << setw(25) << "SALDO DOLARES"
                << setw(25) << "OBSERVACION";
        }
        else if(monedaCuenta == '&') {
            cout << "FECHA" << setw(25) << "RETIROS EUROS" << setw(25)
                << "DEPOSITOS EUROS" << setw(25) << "SALDO EUROS"
                << setw(25) << "OBSERVACION";
        }
        cout << endl;
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
            
            cout << setw(9) << monedaCuenta << setw(9) << sumaRet << setw(15)
                << monedaCuenta << setw(9) << sumaDep << setw(19) << monedaCuenta
                << setw(9) << saldoCuenta;
            
            // observación
            if(!sobregiro && !bajoMinimo) {
                if(saldoCuenta < 0) {
                    sobregiro = true;
                }
                else if(saldoCuenta < convertirMoneda('$', monedaCuenta, 1000, valorUsd, valorEur)) {
                    bajoMinimo = true;
                }
            }
            else {
                if(saldoCuenta > 0) {
                    sobregiro = false;
                    if(saldoCuenta >= convertirMoneda('$', monedaCuenta, 1000, valorUsd, valorEur)) {
                        bajoMinimo = false;
                    }
                }
            }
            if(sobregiro) cout << setw(20) << "SOBREGIRO";
            else if(bajoMinimo) cout << setw(20) << "BAJO EL MINIMO";
            cout << endl;
        }
        
        
        
    }
    
    
    
    
    
    
    return 0;
}

