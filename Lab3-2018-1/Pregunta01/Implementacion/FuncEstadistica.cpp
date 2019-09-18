#include <cmath>
#include "FuncEstadistica.h"

template <typename TIPO>
double mediaAritmetica(TIPO *datos, int num) {
    TIPO suma = 0;
    
    for (int i = 0; i < num; i++) {
        suma += datos[i];
    }

    return (double)suma / num;
}

template <typename TIPO>
double mediaAritmeticaPonderada(TIPO *datos, TIPO *pesos, int num) {
    TIPO suma1 = 0, suma2 = 0;

    for (int i = 0; i < num; i++) {
        suma1 += datos[i] * pesos[i];
        suma2 += pesos[i];
    }

    return (double)suma1 / suma2;
}

template <typename TIPO>
void swap(TIPO *datos, int i, int j) {
    TIPO temp;

    temp = datos[i];
    datos[i] = datos[j];
    datos[j] = temp;
}

template <typename TIPO>
int partition(TIPO *datos, int inf, int sup) {
    TIPO pivote = datos[inf + (sup - inf) / 2];
    while (1) {
        while (datos[inf] < pivote) {
            inf++;
        }
        while (datos[sup] > pivote) {
            sup--;
        }
        if (inf >= sup) {
            return sup;
        }
        swap(datos, inf, sup);
        inf++;
        sup--;
    }
}

template <typename TIPO>
void quicksort(TIPO *datos, int inf, int sup) {
    if (inf < sup) {
        int p = partition(datos, inf, sup);
        quicksort(datos, inf, p);
        quicksort(datos, p + 1, sup);
    }
}

template <typename TIPO>
double mediana(TIPO *datos, int num) {
    TIPO datosTemp[num];

    for (int i = 0; i < num; i++) {
        datosTemp[i] = datos[i];
    }

    quicksort(datosTemp, 0, num - 1);
    
    if (num % 2 == 0) {
        return (datosTemp[num / 2] + datosTemp[num / 2 + 1]) / 2.0;
    }
    else {
        return datosTemp[num / 2];
    }
}

template <typename TIPO>
double desviacionEstandar(TIPO *datos, int num) {
    double media = mediaAritmetica(datos, num);
    double suma = 0;

    for (int i = 0; i < num; i++) {
        suma += pow(datos[i] - media, 2);
    }

    return sqrt(suma / (num - 1));
}

template <typename TIPO>
void distribucionDeFrecuencias(TIPO *datos, int num,
                               TIPO *limites, int numLimites,
                               int *frecuencias, int &numFrecuencias) {
    numFrecuencias = numLimites + 1;

    for (int i = 0; i < numFrecuencias; i++) {
        frecuencias[i] = 0;
    }

    for (int d = 0; d < num; d++) {
        for (int f = 0; f < numFrecuencias; f++) {
            if (f == 0 && datos[d] <= limites[f] ||
                f == numFrecuencias - 1 && datos[d] > limites[f - 1] ||
                f > 0 && datos[d] > limites[f - 1] && datos[d] <= limites[f]) {
                    frecuencias[f]++;
                    break;
                }
        }
    }
}

template double mediaAritmetica(int *, int);
template double mediaAritmetica(double *, int);

template double mediaAritmeticaPonderada(int *, int *, int);
template double mediaAritmeticaPonderada(double *, double *, int);

template void swap(int *, int, int);
template void swap(double *, int, int);

template int partition(int *, int, int);
template int partition(double *, int, int);

template void quicksort(int *, int, int);
template void quicksort(double *, int, int);

template double mediana(int *, int);
template double mediana(double *, int);

template double desviacionEstandar(int *, int);
template double desviacionEstandar(double *, int);

template void distribucionDeFrecuencias(int *, int, int *, int, int *, int &);
template void distribucionDeFrecuencias(double *, int, double *, int, int *, int &);