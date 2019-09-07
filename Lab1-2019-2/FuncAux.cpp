/* 
 * Archivo:   FuncAux.cpp
 * Autor:     Rodrigo Alonso Cruz Leán
 * Código:    20170516
 *
 * Creado el 6 de septiembre de 2019, 09:07 AM
 */

#include "FuncAux.h"

double convertirMoneda(char origen, char destino, double monto,
    double valorUsd, double valorEur) {
    if(origen == destino) {
        return monto; 
    }
    else {
        if(destino == 'S') {
            if(origen == '$') {
                monto *= valorUsd;
            }
            else {
                monto *= valorEur;
            }
        }
        else if(destino == '$') {
            if(origen == 'S') {
                monto *= valorUsd;
            }
            else {
                monto = monto * valorEur / valorUsd;
            }
        }
        else {
            if(origen == '$') {
                monto = monto * valorUsd / valorEur;
            }
            else {
                monto /= valorEur;
            }
        }
    }
    return monto;
}