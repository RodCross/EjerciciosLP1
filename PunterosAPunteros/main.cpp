#include <iostream>
#include "FuncDeCadenas.h"
using namespace std;

int main() {
    char **codCur, **nomCur, ***req;

    leerDatos(codCur, nomCur, req);
    ordenarDatos(codCur, nomCur, req);
    imprimirDatos(codCur, nomCur, req);

    return 0;
}